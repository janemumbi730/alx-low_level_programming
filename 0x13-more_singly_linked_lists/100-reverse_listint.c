#include "lists.h"

/**
* reverse_listint - reverses linked list stated
* @head: pointer to head of linked list
*
* Return: pointer to first node
*/

listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL, *current = NULL, *next = NULL;

	while (*head)
	{
	current = *head;
	next = current->next;
	current->next = prev;
	prev = current;
	*head = next;
	}

	*head = current;

	return (*head);
}
