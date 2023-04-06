#include "main.h"

/**
 * clear_bit - Sets value of bit at given index to 0
 * @n: pointer to unsigned long int representing bit.
 * @index: unsigned int representing index of bit
 *
 * Return: 1 or -1 if error occurs
 */


int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8) || n == NULL)
		return (-1);

	*n &= ~(1UL << index);
	return (1);
}
