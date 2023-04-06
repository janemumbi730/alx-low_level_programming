#include "main.h"

/**
 * flip_bits - Returns no of bits that need to be flipped for conversion
 * @n: no to be converted to m
 * @m: no to be converted to
 *
 * Return: no of bits that need to be flipped for conversion
 */


unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int q = n ^ m;
	unsigned int tally = 0;

	while (q > 0)
	{
	tally++;
	q &= (q - 1);
	}

	return (tally);
}
