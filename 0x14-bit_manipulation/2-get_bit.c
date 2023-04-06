#include "main.h"

/**
* get_bit - gets value of given bit index
* @n: no that has bit
* @index: of bit
*
* Return: index provided
*/

int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8) || n == 0)
		return (-1);
	return ((n >> index) & 1);
}
