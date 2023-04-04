#include "lists.h"

/**
* sum_listint - calculates sum of integers in a linked list
* @head: A pointer to the head node of the linked list
*
* Return: The sum of all the integers in the linked list
*/

int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *current = head;

	while (current != NULL)
	{
	sum += current->n;
	current = current->next;
	}

	return (sum);
}
