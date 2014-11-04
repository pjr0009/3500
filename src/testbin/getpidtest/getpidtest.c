
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <err.h>


int
main(int argc, char *argv[])
{
	int mypid;
	mypid = getpid();
	cat("testfile.txt", "testfile2.txt");
	return 0;
}
