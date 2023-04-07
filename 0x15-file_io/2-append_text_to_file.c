#include "main.h"

/**
 * append_text_to_file - adds text to end of file
 * @filename: name of file
 * @text_content: text to be added at end of file
 *
 * Return: 1 or -1 on failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int f, l = 0;

	if (filename == NULL)
	return (-1);

	f = open(filename, O_WRONLY | O_APPEND);
	if (f == -1)
	return (-1);

	if (text_content != NULL)
	{
	while (text_content[l] != '\0')
		l++;

	if (write(f, text_content, l) == -1)
	{
		close(f);
		return (-1);
	}
	}

	close(f);
	return (1);
}
