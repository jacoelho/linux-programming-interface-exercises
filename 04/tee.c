#include <sys/stat.h>
#include <fcntl.h>
#include "tlpi_hdr.h"

#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif

static void usageError(const char *progName)
{
	fprintf(stderr, "Usage: %s [-a] file\n", progName);
	fprintf(stderr, "    -a           Use append flag\n");
	exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
	int outputFd, flags, appendFlag, opt;
	mode_t filePerms;
	ssize_t numRead;
	char buf[BUF_SIZE];

	flags = O_CREAT | O_WRONLY;
	appendFlag = 0;

	while ((opt = getopt(argc, argv, "a")) != -1) {
		switch (opt) {
		case 'a':
			appendFlag = 1;
			break;
		default:
			usageError(argv[0]);

		}

	}

	if (appendFlag) {
		flags |= O_APPEND;
	} else {
		flags |= O_TRUNC;
	}

	filePerms = S_IRUSR | S_IWUSR |
              S_IRGRP | S_IWGRP |
              S_IROTH | S_IWOTH;	/* rw-rw-rw- */

	outputFd = open(argv[optind], flags, filePerms);
	if (outputFd == -1)
		errExit("opening file %s", argv[optind]);

	while ((numRead = read(STDIN_FILENO, buf, BUF_SIZE)) > 0)
		if (write(outputFd, buf, numRead) != numRead)
			fatal("couldn't write whole buffer");

	if (numRead == -1)
		errExit("read");

	if (close(outputFd) == -1)
		errExit("close output");

	exit(EXIT_SUCCESS);
}
