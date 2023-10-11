#include <stdio.h>
#include "search_algos.h"

/**
 * binary_search - search mids
 * @array: given array of ints
 * @size: size of array
 * @value: value to search for
 * Return: index at which value's found
 */

int binary_search(int *array, size_t size, int value)
{
	int left = 0;
	int right = size - 1;
	int i;

	if (array == NULL)
		return (-1);

	while (left <= right)
	{
		int mid = (left + right) / 2;

		printf("Searching in array: ");
		for (i = left; i <= right; i++)
		{
		if (i != right)
			printf("%d, ", array[i]);
		else
			printf("%d\n", array[i]);
		}

		if (array[mid] == value)
		return (mid);
		else if (array[mid] < value)
		left = mid + 1;
		else
		right = mid - 1;
	}

	return (-1);
}
