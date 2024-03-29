#include "lists.h"

/**
 * find_listint_loop - finds loop in a linked list
 * @head: pointer of the linked list
 *
 * Return: loop starts, or NULL
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow, *fast;

	if (head == NULL)
	return (NULL);

	slow = head;
	fast = head;

	while (fast != NULL && fast->next != NULL)
	{
	fast = fast->next->next;
	slow = slow->next;
	if (slow == fast)
	{
	slow = head;

	while (slow != fast)
	{
	slow = slow->next;
	fast = fast->next;
	}
	return (fast);
	}
	}

	return (NULL);
}
