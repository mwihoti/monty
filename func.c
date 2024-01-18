#include "monty.h"

/**
 * add_nodeend - add a node at end of the list
 * @head: position of first node
 * @n: data to store
 * Return: double linked list
 */
stack_t *add_nodeend(stack_t **head, const int n)
{
	stack_t *temp, *nm;

	if (head == NULL)
		return (NULL);
	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		fprintf(stderr, "Error: malloc-failed\n");
		free_st();
		exit(EXIT_FAILURE);
	}
	temp->n = n;
	if (*head == NULL)
	{
		temp->next = *head;
		temp->prev = NULL;
		*head = temp;
		return (*head);
	}
	nm = *head;
	while (nm->next)
		nm = nm->next;
	temp->next = nm->next;
	temp->prev = nm;
	nm->next = temp;
	return (nm->next);
}
/**
 * add_node - add a node at the begining of the list
 *
 * @head: position of linked list
 * @n: data to store
 * Return: doubly linked list
 */
stack_t *add_node(stack_t **head, const int n)
{
	stack_t *temp;

	if (head == NULL)
		return (NULL);
	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_st();
		exit(EXIT_FAILURE);
	}
	temp->n = n;

	if (*head == NULL)
	{
		temp->next = *head;
		temp->prev = NULL;
		*head = temp;
		return (*head);
	}
	(*head)->prev = temp;
	temp->next = (*head);
	temp->prev = NULL;
	*head = temp;
	return (*head);
}

