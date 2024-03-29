#include "hash_tables.h"

/**
 * hash_table_delete - deletes hash table
 * @ht: hash table
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int index = 0;
	hash_node_t *node, *next;

	if (ht == NULL)
	return;

	if (ht->array == NULL)
	return;

	while (index < ht->size)
	{
	node = (ht->array)[index];
	while (node)
	{
	next = node->next;
	if (node->key)
	free(node->key);
	if (node->value)
	free(node->value);
	node->key = NULL;
	node->value = NULL;
	free(node);
	node = next;
	}
	index++;
	}
	free(ht->array);
	free(ht);
}
