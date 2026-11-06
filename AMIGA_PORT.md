Mirror Magic 3.3.1 for AmigaOS 3.x
==================================

Mirror Magic (Holger Schemel, Artsoft Entertainment,
https://www.artsoft.org/mirrormagic/), the puzzle game after Deflektor: turn
the mirrors so the wizard's laser beam reaches the kettles and then the
exit, before the fuel runs out and without overheating, through the
Mindbender and Deflektor level sets, with a level editor and tapes that
record your solutions. Mirror Magic II, on the Rocks'n'Diamonds engine. For
AmigaOS 3.x on a 68040 or 68060 with an FPU and an RTG screen, on OpenGPU's
SDL 2.

Base: mirrormagic_3.3.1+dfsg1.orig.tar.xz from Debian (sha256
56cbc7887ef2c28c3c86ad37631566b14cd18cf571f956c9336f8dbec85b5ff8):
upstream's 3.3.1 without its music, whose licence Debian could not confirm.
Debian's patches (3.3.1+dfsg1-5) are the second commit. Branch
team2/mirrormagic-amiga.

Status: plays in the lab (Instance-45 on GFOpenUp 0.8.19, 6 November
2026): the main menu, Start Game, level 0 of the Mindbender set (a mirror
turned with the mouse, the beam bounced onto a kettle, the spell count and
the score), Escape and its question, the menu, and Quit with its question
back to the Shell; user/.MirrorMagic has the settings, the level set's
progress and a log. The lab is muted, so the sounds were not heard there.


What you need
-------------

- A 68040 or 68060 with an FPU, AmigaOS 3.x, an RTG card (or the
  AmigaChrome lab).
- GFOpenUp 0.8.18 or later: LIBS:OpenGPU/SDL2.module, SDL2_image.module,
  SDL2_mixer.module and SDL2_net.module.
- A TCP/IP stack's bsdsocket.library (GFOpenSocket, Roadshow or AmiTCP) for
  SDL2_net; the lab had GFOpenSocket. Without one is untested.


How to play
-----------

Open the MirrorMagic icon, or run MirrorMagic from a Shell. It opens a
640x440 window. Click a mirror (or a prism or polariser) to turn it; the
beam must reach every kettle and then the exit. Escape leaves a level. Setup on the main menu has the
graphics and sound sets, the keys and full screen. The graphics, levels and
sounds are in the drawer; the settings, tapes and your own levels in
user/.MirrorMagic.


Building
--------

    make -f amiga/Makefile.amigaos -j2 dist

with GFOpenAmigaGCC 16.2.0-open4, the OpenGPU kit and the Team's static
zlib (see the Makefile's head). The drawer is dist/MirrorMagic (and
dist/MirrorMagic.info).


What was changed
----------------

- src/libgame/misc.c: getPath2 puts no "/" after a ":" or a "/" on
  AmigaOS ("PROGDIR:/x" and "a//x" name a parent drawer), and "." is just
  the other part. BASE_PATH, the read-only data, is the drawer (PROGDIR:).
- amiga/amiga_env.c (-Wl,--wrap=getenv, from the GNU Robbo port): $HOME is
  the drawer's user/, where the game keeps .MirrorMagic.
- amiga/include/pwd.h: libnix has no getpwuid; it finds no entry, and the
  game uses its defaults.
- src/netserv.c: no SIGPIPE to ignore (libnix has no sigaction).
- amiga/Makefile.amigaos builds the sources of src/Makefile and
  src/libgame/Makefile (not the Windows zip file reader) and of game_em,
  game_mm and game_sp, for the SDL 2 target; the zip reader uses libnix's
  32-bit stdio; -lsocket for SDL2_net, as the Blob Wars port links it.
- amiga/stack.c: 1 MB of stack.
- Without music (Debian's source has none), the game warns that it finds
  no music and plays without it.


Licences
--------

Mirror Magic, its graphics, levels and sounds: GPL 2 (COPYING.txt; credits
in CREDITS.txt). The Amiga files (amiga/): GPL 2 or later, the AmiCradle
Team.
