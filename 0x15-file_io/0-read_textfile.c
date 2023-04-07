#include "main.h"

/**
 * read_textfile - reads text file and prints to standard output
 * @filename: file to be read
 * @letters: no of letters to be printed
 *
 * Return: no of bytes or 0 if an error occurs
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int f;
	char *bu;
	ssize_t input, output;

	if (!filename)
		return (0);

	bu = malloc(sizeof(char) * letters);
	if (!bu)
		return (0);

	f = open(filename, O_RDONLY);
	if (f == -1)
	{
		free(bu);
		return (0);
	}

	input = read(f, bu, letters);
	if (input == -1)
	{
		free(bu);
		close(f);
		return (0);
	}

	output = write(STDOUT_FILENO, bu, input);
	if (output == -1 || output != input)
	{
		free(bu);
		close(f);
		return (0);
	}

	free(bu);
	close(f);

	return (output);
}
