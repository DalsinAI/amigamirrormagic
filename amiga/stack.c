/* A Shell gives 4 KB of stack; libnix's startup sets this much up instead.
 * The AmiCradle Team. GPL 2 or later, like Mirror Magic. */
unsigned long __stack = 1024 * 1024;
static const char version[] __attribute__((used)) = "$VER: Mirror Magic 3.3.1 Amiga (06.11.2026)";
