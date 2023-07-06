#include "hash_tables.h"

/**
 * hash_table_get - gets value associated with a key
 * @ht: hash table
 * @key: key
 * Return: value or NULL
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *temp;

	if (!ht || !key)
	return (NULL);

	index = key_index((const unsigned char *)key, ht->size);

	temp = (ht->array)[index];

	while (temp != NULL && strcmp(temp->key, key) != 0)
	temp = temp->next;

	if (!temp)
	return (NULL);

	else
	return (temp->value);
}
