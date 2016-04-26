#include <unistd.h>
#include <stdio.h>

#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif

int main(int argc, char **argv)
{
	ssize_t num_read;
	int i;
	char buf[BUF_SIZE];
	if (argc != 2) {
		fprintf(stderr, "usage: <stream> | append <text to append>");
		return 1;
	}

	if (isatty(STDIN_FILENO)) {
		fprintf(stderr, "no data in stdin stream");
		return 1;
	};

	while ((num_read = read(STDIN_FILENO, buf, BUF_SIZE)) != 0) {
		write(STDOUT_FILENO, buf, num_read);
	}

	for (i = 0; argv[1][i] != '\0'; i++);
	write(STDOUT_FILENO, argv[1], i);
}
