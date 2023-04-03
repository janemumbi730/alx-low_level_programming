#include "lists.h"

/**
* free_listint2 - frees linked list
* @head: pointer to head of linked list
*
* Return: void
*/


void free_listint2(listint_t **head)
{
	if (head == 0)
	{
	return;
	}
	while (*head != 0)
	{
		listint_t *temp = *head;
		*head = (*head)->next;
		free(temp);
	}

	*head = 0;
}
