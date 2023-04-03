#include "lists.h"

/**
* pop_listint - deletes the head node of a linked list
* @head: pointer to head of linked list
*
* Return: data from new node
*/

int pop_listint(listint_t **head)
{
	listint_t *temp;
	int n = 0;

	if (*head == 0)
	{
	return (n);
	}

	temp = *head;
	n = temp->n;
	*head = (*head)->next;
	free(temp);

	return (n);
}
