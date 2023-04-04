#include "lists.h"

/**
* get_nodeint_at_index - returns the nth node of a linked list
* @head: Pointer to the head node of the linked list
* @index: index of the node to be returned
*
* Return: pointer to the nth node
*/

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	while (index > 0 && head)
	{
		head = head->next;
		index--;
	}

	return (head);
}
