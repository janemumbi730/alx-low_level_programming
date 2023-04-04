#include "lists.h"

/**
 * free_listp - frees a linked list
 * @head: pointer to head of linked list
 *
 * Return: void
 */

void free_listp(listp_t **head)
{
	listp_t *current;

	if (head == NULL)
	return;

	current = *head;
	while (current != NULL)
	{
	listp_t *temp = current;

	current = current->next;

	free(temp);
	}
	*head = NULL;
}

/**
 * print_listint_safe - prints a linked list.
 * @head: head of a list.
 *
 * Return: number of nodes in the list.
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t nnodes = 0;
	listp_t *visited = NULL;
	listp_t *new_node;
	listp_t *current;

	while (head != NULL)
	{
	current = visited;
	while (current != NULL)
	{
	if ((void *)head == current->p)
	{
	printf("-> [%p] %d\n", (void *)head, head->n);
	free_listp(&visited);
	return (nnodes);
	}
	current = current->next;
	}


	new_node = malloc(sizeof(listp_t));
	if (new_node == NULL)
	exit(98);

	new_node->p = (void *)head;
	new_node->next = visited;
	visited = new_node;


	printf("[%p] %d\n", (void *)head, head->n);
	head = head->next;
	nnodes++;
	}

	free_listp(&visited);
	return (nnodes);
}
