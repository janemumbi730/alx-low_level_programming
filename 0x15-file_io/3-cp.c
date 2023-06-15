#include "main.h"

/**
 * check_stat - checks if a file can be opened or closed
 * @stat: file descriptor of the file to be opened
 * @filename: name of the file
 * @mode: closing or opening
 * @fd: file descriptor
 *
 * Return: void
 */
void check_stat(int stat, int fd, char *filename, char mode)
{
	if (mode == 'C' && stat == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
	else if (mode == 'O' && stat == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
		exit(98);
	}
	else if (mode == 'W' && stat == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		exit(99);
	}
}

/**
 * main - copies contents of file to another
 * @arc: no of arguments
 * @arv: argument ballpark
 *
 * Return: 0
 */
int main(int arc, char *arv[])
{
	int src, dest, n_read = 1024, wrote, close_src, close_dest;
	unsigned int mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	char buffer[1024];

	if (arc != 3)
	{
		dprintf(STDERR_FILENO, "%s", "Usage: cp file_from file_to\n");
		exit(97);
	}
	src = open(arv[1], O_RDONLY);
	check_stat(src, -1, arv[1], 'O');
	dest = open(arv[2], O_WRONLY | O_CREAT | O_TRUNC, mode);
	check_stat(dest, -1, arv[2], 'W');
	while (n_read == 1024)
	{
		n_read = read(src, buffer, sizeof(buffer));
		if (n_read == -1)
			check_stat(-1, -1, arv[1], 'O');
		wrote = write(dest, buffer, n_read);
		if (wrote == -1)
			check_stat(-1, -1, arv[2], 'W');
	}
	close_src = close(src);
	check_stat(close_src, src, NULL, 'C');
	close_dest = close(dest);
	check_stat(close_dest, dest, NULL, 'C');
	return (0);
}
