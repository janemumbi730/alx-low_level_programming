#include "hash_tables.h"

/**
 * shash_table_create - creates shash table
 * @size: size
 * Return: created shash table, or NULL
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *tb;
	shash_node_t **array;
	unsigned long int a;

	tb = malloc(sizeof(shash_table_t));
	if (tb == NULL)
		return (NULL);

	array = malloc(sizeof(shash_node_t *) * size);
	if (array == NULL)
		return (NULL);

	for (a = 0; a < size; a++)
		array[a] = NULL;

	tb->array = array;
	tb->size = size;
	tb->shead = NULL;
	tb->stail = NULL;

	return (tb);
}


/**
 * shash_table_set - adds a hash key to shash table
 * @ht: shash table
 * @key: key
 * @value: value
 * Return: 1 or 0 if fails
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *new;

	if (ht == NULL)
		return (0);

	if (key == NULL || *key == '\0')
		return (0);

	index = key_index((unsigned char *)key, ht->size);

	new = add_n_shash(&(ht->array[index]), key, value);

	if (new == NULL)
		return (0);

	ad_shash(ht, new);

	return (1);
}

/**
 * shash_table_get - gets value related to key
 * @ht: shash table
 * @key: key
 * Return: value
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *temp;

	if (ht == NULL)
		return (NULL);

	if (key == NULL || *key == '\0')
		return (NULL);

	index = key_index((unsigned char *)key, ht->size);

	temp = ht->array[index];

	while (temp != NULL)
	{
		if (strcmp(temp->key, key) == 0)
			return (temp->value);
		temp = temp->next;
	}

	return (NULL);
}

/**
 * shash_table_print - prints values of the shash table
 * @ht: shash table
 * Return: void
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *temp;
	char *x;

	if (ht == NULL)
		return;

	printf("{");
	x = "";

	temp = ht->shead;

	while (temp != NULL)
	{
		printf("%s'%s': '%s'", x, temp->key, temp->value);
		x = ", ";
		temp = temp->snext;
	}

	printf("}\n");
}

/**
 * shash_table_print_rev - prints values of the shash table reversed
 * @ht: shash table
 * Return: void
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *temp;
	char *x;

	if (ht == NULL)
		return;

	printf("{");
	x = "";

	temp = ht->stail;

	while (temp != NULL)
	{
		printf("%s'%s': '%s'", x, temp->key, temp->value);
		x = ", ";
		temp = temp->sprev;
	}

	printf("}\n");
}

/**
 * shash_table_delete - deletes shash table
 * @ht: shash table
 * Return: void
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int a;
	shash_node_t *x;
	shash_node_t *y;

	if (ht == NULL)
		return;

	for (a = 0; a < ht->size; a++)
	{
		x = ht->array[a];
		while ((y = x) != NULL)
		{
			x = x->next;
			free(y->key);
			free(y->value);
			free(y);
		}
	}
	free(ht->array);
	free(ht);
}

/**
 * add_n_shash - adds a node to beginning of a shash
 * @h: head of shash linked list
 * @key: key
 * @value: value
 * Return: node
 */
shash_node_t *add_n_shash(shash_node_t **h, const char *key, const char *value)
{
	shash_node_t *x;

	x = *h;

	while (x != NULL)
	{
		if (strcmp(key, x->key) == 0)
		{
			free(x->value);
			x->value = strdup(value);
			return (x);
		}
		x = x->next;
	}

	x = malloc(sizeof(shash_node_t));

	if (x == NULL)
		return (NULL);

	x->key = strdup(key);
	x->value = strdup(value);
	x->next = *h;

	*h = x;

	return (x);
}

/**
 * ad_shash - adds a node of the shash table
 * @ht: shash table
 * @new: new node
 * Return: void
 */
void ad_shash(shash_table_t *ht, shash_node_t *new)
{
	shash_node_t *x, *y;
	int r;

	x = y = ht->shead;

	while (x != NULL)
	{
		r = strcmp(new->key, x->key);
		if (r == 0)
		{
			return;
		}
		else if (r < 0)
		{
			new->sprev = x->sprev;

			if (x->sprev)
				x->sprev->snext = new;
			else
				ht->shead = new;

			x->sprev = new;
			new->snext = x;

			return;
		}
		y = x;
		x = x->snext;
	}

	new->sprev = y;
	new->snext = NULL;

	if (ht->shead)
		y->snext = new;
	else
		ht->shead = new;

	ht->stail = new;
}
