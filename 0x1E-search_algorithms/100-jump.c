#include "search_algos.h"
/**
 * jump_search - searches for a value in a sorted array of int
 * @array:  pointer to the first element of the array to search
 * @size:  is the number of elements in array
 * @value: value searched
 * Return: index
 */

int jump_search(int *array, size_t size, int value)
{
	size_t a, y, z;

	if (array == NULL || size == 0)
		return (-1);

	z = sqrt(size);
	for (a = y = 0; y < size && array[y] < value;)
	{
		printf("Value checked array[%ld] = [%d]\n", y, array[y]);
		a = y;
		y += z;
	}

	printf("Value found between indexes [%ld] and [%ld]\n", a, y);

	y = y < size - 1 ? y : size - 1;
	for (; a < y && array[a] < value; a++)
		printf("Value checked array[%ld] = [%d]\n", a, array[a]);
	printf("Value checked array[%ld] = [%d]\n", a, array[a]);

	return (array[a] == value ? (int)a : -1);
}
