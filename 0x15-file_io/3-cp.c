#include "main.h"

/**
 * main - copies content from one file to next
 * @ac: no of arguments
 * @av: argument aim
 *
 * Return: 0
 */

int main(int ac, char **av)
{
	int from, to, file_from;
	char bu[1024];

	if (ac != 3)
	{
	dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
	return (97);
	}
	from = open(av[1], O_RDONLY);
	if (from == -1)
	{
	dprintf(STDERR_FILENO, "Error: Can't read from %s\n", av[1]);
	return (98);
	}
	to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (to == -1)
	{
	close(from);
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
	return (99);
	}
	while ((file_from = read(from, bu, 1024)) > 0)
	{
	if (write(to, bu, file_from) != file_from)
	{
	close(from);
	close(to);
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
	return (99);
	}
	}
	if (file_from == -1)
	{
	close(from);
	close(to);
	dprintf(STDERR_FILENO, "Error: Can't read from %s\n", av[1]);
	return (98);
	}
	if (close(from) == -1)
	{
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", from);
	return (100);
	}
	if (close(to) == -1)
	{
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", to);
	return (100);
	}
	return (0);
}
