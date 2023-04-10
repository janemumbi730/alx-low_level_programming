#include "main.h"

/**
 * main - copies contents of file to another
 * @arc: no of arguments
 * @arv: argument ballpark
 *
 * Return: 0
 */
int main(int arc, char *arv[])
{
	int file_from, file_to, read_file;
	char buffer[1024];

	if (arc != 3)
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97);

	file_from = open(arv[1], O_RDONLY);
	if (file_from == -1)
		dprintf(STDERR_FILENO, "Error: Can't read from %s\n", arv[1]), exit(98);

	file_to = open(arv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);

	do {
		read_file = read(file_from, buffer, 1024);
		if (read_file > 0)
		{
		if (file_to < 0 || (write(file_to, buffer, read_file) != read_file))
		{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", arv[2]);
		exit(99);
		}
		}
	} while (read_file > 0);

	if (read_file == -1)
	dprintf(STDERR_FILENO, "Error; Can't read from %s\n", arv[1]), exit(98);

	if ((close(file_to)) == -1)
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to), exit(100);

	if ((close(file_from)) == -1)
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from),
	exit(100);
	return (0);
}
