#include "main.h"

/**
 * binary_to_uint - converts binary no to unsigned int
 * @b: character form
 *
 * Return: output
 */

unsigned int binary_to_uint(const char *b)
{

	unsigned int exit = 0;
	unsigned int m = 1;
	int l = 0;

	if (b == NULL)
	return (0);

	while (b[l])
	l++;

	for (l--; l >= 0; l--)
	{
	if (b[l] != '0' && b[l] != '1')
	return (0);

	exit += (b[l] - '0') * m;
	m *= 2;
	}

	return (exit);
}
