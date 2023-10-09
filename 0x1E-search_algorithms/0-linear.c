#include "search_algos.h"
/**
 * linear_search - search linearly
 * @array:  parameter to given array
 * @size: parameter to size of array
 * @value: value searched
 * Return: index
 */

int linear_search(int *array, size_t size, int value)
{
	size_t x;

	if (!array)
		return (-1);

	x = 0;
	while (x < size)
	{
		printf("Value checked array[%lu] = [%d]\n", x, array[x]);
		if (array[x] == value)
			return (x);
		x++;
	}
	return (-1);
}
