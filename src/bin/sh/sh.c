/*
 * sh - shell
 * Usage: up to you
 */

#ifdef HOST
#include "hostcompat.h"
#endif

int
main(int argc, char *argv[])
{
#ifdef HOST
	hostcompat_init(argc, argv);
#endif

	/* Write this */
	waitpid(getpid(), 0, 0);
	(void)argc;
	(void)argv;

	return 1;
}
