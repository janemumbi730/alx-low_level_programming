#include "search_algos.h"
#include <stdio.h>
/**
 * linear_search - search linearly
 * @array:  parameter to given array
 * @size: parameter to size of array
 * @value: value searched
 * Return: index
 */
int linear_search(int *array, size_t size, int value)
{
	size_t i;

	if (array == NULL)
		return (-1);

	for (i = 0; i < size; i++)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
		return (i);
	}

	return (-1);
}
