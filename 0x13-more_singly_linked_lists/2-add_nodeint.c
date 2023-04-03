#include "lists.h"

/**
* add_nodeint - adds a new node at beginnning of list
* @head: pointer to head of linked list
* @n: integer value for data in node
*
* Return: pointer to the new head node of the list
*/



listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_head = malloc(sizeof(listint_t));

	if (new_head == 0)
	{
	return (0);
	}

	new_head->n = n;
	new_head->next = *head;
	*head = new_head;

	return (new_head);
}
