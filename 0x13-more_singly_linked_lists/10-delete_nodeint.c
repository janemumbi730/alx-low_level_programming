#include "lists.h"

/**
* delete_nodeint_at_index - deletes the node at index provided
* @head: pointer to head of linked list
* @index: of node to be deleted
*
* Return: 1 or  -1 on success/fail
*/


int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int count = 0;
	listint_t *temp, *next_node;

	if (!head || !*head)
	return (-1);

	temp = *head;

	if (index == 0)
	{
	*head = (*head)->next;
	free(temp);
	return (1);
	}

	while (temp && count < index - 1)
	{
	temp = temp->next;
	count++;

	if (!temp || !temp->next)
		return (-1);
	}

	next_node = temp->next->next;
	free(temp->next);
	temp->next = next_node;

	return (1);
}
