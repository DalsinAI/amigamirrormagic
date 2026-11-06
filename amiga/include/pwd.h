/* Mirror Magic for AmigaOS: libnix has no pwd.h. src/libgame/misc.c asks
 * getpwuid() for the user's name and home; AmigaOS has no such database, so
 * there is no entry and the game falls back to its own defaults ($HOME is
 * the drawer's user/, amiga/amiga_env.c).
 * The AmiCradle Team. GPL 2 or later, like Mirror Magic. */
#ifndef AMIGA_PWD_H
#define AMIGA_PWD_H
#include <sys/types.h>
struct passwd {
	char *pw_name;
	char *pw_passwd;
	uid_t pw_uid;
	gid_t pw_gid;
	char *pw_gecos;
	char *pw_dir;
	char *pw_shell;
};
static inline struct passwd *getpwuid(uid_t uid) { (void)uid; return 0; }
#endif
