#include "lists.h"

/**
 * print_listint_safe - prints a linked list
 * @head: pointer to head of linked list
 *
 * Return: number of nodes in list
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t elements = 0;
	const listint_t *slow = head, *fast = head;

	if (head == 0)
	{
	exit(98);
	}

	while (slow != 0 && fast != 0 && fast->next != 0)
	{
	slow = slow->next;
	fast = fast->next->next;
	if (slow == fast)
	{
	printf("-> [%p] %d\n", (void *)head, head->n);
	exit(98);
	}

	printf("[%p] %d\n", (void *)head, head->n);
	head = head->next;
	elements++;
	}

	return (elements);
}
