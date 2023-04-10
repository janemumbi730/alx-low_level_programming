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
	int from, to, file_from;
	char buffer[1024];

	if (arc != 3)
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97);

	from = open(arv[1], O_RDONLY);
	if (from == -1)
		dprintf(STDERR_FILENO, "Error: Can't read from %s\n", arv[1]), exit(98);

	to = open(arv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);

	do {
		file_from = read(from, buffer, 1024);
		if (file_from > 0)
		{
		if (to < 0 || (write(to, buffer, file_from) != file_from))
		{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", arv[2]);
		exit(99);
		}
		}
	} while (file_from > 0);

	if (file_from == -1)
		dprintf(STDERR_FILENO, "Error; Can't read from %s\n", arv[1]), exit(98);
	if ((close(from)) == -1)
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", from),
	exit(100);
	if ((close(to)) == -1)
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", to), exit(100);

	return (0);
}
