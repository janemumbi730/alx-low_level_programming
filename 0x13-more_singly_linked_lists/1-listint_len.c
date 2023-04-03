#include "lists.h"

/**
* listint_len - returns number of elements in linked list
* @h: pointer to head of linked list
*
* Return: number of nodes in list
*/


size_t listint_len(const listint_t *h)
{
	size_t count;

	for (count = 0; h != 0; count++)
	{
	h = h->next;
	}

	return (count);
}
