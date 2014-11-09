/*
 * getpidtest - test getpid().
 *
 * This should work correctly when fork is implemented.
 *
 */

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <err.h>


int
main(int argc, char *argv[])
{
	int mypid;
	warn("starting getpid test");
	mypid = getpid();
	reboot(RB_REBOOT);
	warn("\n finish getpid test \n");
	return 0;
}
