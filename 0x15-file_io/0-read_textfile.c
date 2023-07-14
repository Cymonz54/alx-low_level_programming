#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - reads a text file and prints its contents to stdout
 * @filename: name of the file to read
 * @letters: maximum number of letters to read and print
 *
 * Return: number of letters read and printed, or 0 on failure
 */

ssize_t read_textfile(const char *filename, size_t letters)

{
	int x;
	ssize_t t, w;
	char *buf;

	if (!filename)
		return (0);

	x = open(filename, O_RDONLY);
	if (x == -1)
		return (0);

	buf = malloc(sizeof(char) * letters);
	if (!buf)
	{
		close(x);
		return (0);
	}

	t = read(x, buf, letters);
	w = write(STDOUT_FILENO, buf, t);

	free(buf);
	close(x);

	return (w);
}
