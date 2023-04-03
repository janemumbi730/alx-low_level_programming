#include "lists.h"

/**
* add_nodeint_end - adds new node at end of list
* @head: pointer to head of linked list
* @n: integer value for data in node
*
* Return: address of new node
*/


listint_t *add_nodeint_end(listint_t **head, const int n)

{
	listint_t *new_end = malloc(sizeof(listint_t));

	if (new_end == 0)
	{
	return (0);
	}

	new_end->n = n;
	new_end->next = 0;

	if (*head == 0)
	{
	*head = new_end;
	}
	else
	{

	listint_t *current = *head;

	while (current->next != 0)
	{
	current = current->next;
	}
	current->next = new_end;
	}

	return (new_end);
}
