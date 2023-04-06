#include "main.h"

/**
 * set_bit - Sets value of  bit at given index to 1
 * @n: pointer to an unsigned long int
 * @index: unsigned int representing index of bit
 *
 * Return: 1 or -1 if an error occurs
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8) || n == NULL)
		return (-1);

	*n |= (1UL << index);
	return (1);
}
