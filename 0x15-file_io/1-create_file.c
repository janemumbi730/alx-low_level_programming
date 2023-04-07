#include "main.h"

/**
 * create_file - creates file and write content in it
 * @filename: name of the file to create
 * @text_content: content to be written
 *
 * Return: 1 or -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int f, l = 0;

	if (filename == NULL)
		return (-1);

	f = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 600);

	if (f == -1)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[l] != '\0')
			l++;
	}

	if (l > 0)
	{
		if (write(f, text_content, l) == -1)
		{
			close(f);
			return (-1);
		}
	}

	close(f);
	return (1);
}
