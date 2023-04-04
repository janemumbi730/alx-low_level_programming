#include "lists.h"

/**
 * looped_listint_len - Returns the number of nodes in a looped linked list.
 * @head: A pointer to the head of the list.
 * Return: The number of nodes in the loop, or 0 if the list is not looped.
 */

size_t looped_listint_len(const listint_t *head)
{
	const listint_t *tortoise, *hare;
	size_t count = 0;

	if (head == NULL || head->next == NULL)
	return (0);

	tortoise = head->next;
	hare = head->next->next;

	while (hare != NULL && hare->next != NULL)
	{
	if (tortoise == hare)
	{
		hare = hare->next;
		count = 1;

		while (tortoise != hare)
		{
			hare = hare->next;
			count++;
		}
	tortoise = head;
		while (tortoise != hare)
		{
			tortoise = tortoise->next;
			hare = hare->next;
			count++;
		}
		return (count);
	}
	tortoise = tortoise->next;
	hare = hare->next->next;
	}
	return (0);
}

/**
 * print_listint_safe - prints a linked list
 * @head: pointer to head of linked list
 *
 * Return: number of nodes in list
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t nodes = 0;
	const listint_t *slow = head;

	while (slow)
	{
		nodes++;
		printf("[%p] %d\n", (void *)slow, slow->n);
		if (slow > slow->next)
			slow = slow->next;
		else
		{
			printf("-> [%p] %d\n", (void *)slow->next, slow->next->n);
			break;
		}
	}
	return (nodes);
}
