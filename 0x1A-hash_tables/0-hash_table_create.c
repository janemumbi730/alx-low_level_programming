#include "hash_tables.h"

/**
 * hash_table_create - creates hash table
 * @size: array size
 * Return: pointer to created hash table
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hasht;
	unsigned long int i;
	hash_node_t **array;

	if (size == 0)
		return (NULL);

	hasht = malloc(sizeof(hash_table_t));
	if (hasht == NULL)
		return (NULL);

	array = malloc(sizeof(*array) * size);
	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		array[i] = NULL;
	}
	hasht->size = size;
	hasht->array = array;

	return (hasht);
}
