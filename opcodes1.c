#include "monty.h"
#include <stdio.h>
/**
 * op_push - pushes items to stack
 * @head: head of linked list
 * @curline: number of line
 * Return: no return
 */
void op_push(stack_t **head, unsigned int curline)
{
	int n, j;

	if (!st.arg)
	{
		fprintf(stderr, "L%u: ", curline);
		fprintf(stderr, "Usage: push integer\n");
		free_st();
		exit(EXIT_FAILURE);
	}
	for (j = 0; st.arg[j] != '\0'; j++)
	{
		if (!isdigit(st.arg[j]) && st.arg[j] != '-')
		{
			fprintf(stderr, "L%u: ", curline);
			fprintf(stderr, "usage: push integer\n");
			free_st();
			exit(EXIT_FAILURE);
		}
	}
	n = atoi(st.arg);
	if (st.elem == 1)
		add_node(head, n);
	else
		add_nodeend(head, n);
}
/**
 * op_pall - prints stack values
 * @head: head of linked list
 * @curline: number of lines
 * Return: nothing
 */
void op_pall(stack_t **head, unsigned int curline)
{
	stack_t *nm;
	(void)curline;

	nm = *head;

	while (nm)
	{
		printf("%d\n", nm->n);
		nm = nm->next;
	}
}
/**
 * op_pint - prints top value of stack
 *
 * @head: link list head
 * @curline: line number
 * Return: nothing
 */
void op_pint(stack_t **head, unsigned int curline)
{
	(void)curline;

	if (*head == NULL)
	{
		fprintf(stderr, "L%u: ", curline);
		fprintf(stderr, "can't pint, stack empty\n");
		free_st();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
/**
 * op_pop - remove stack elements from top
 * @head: linked list head
 * @curline: line number
 * Return: nothing
 */
void op_pop(stack_t **head, unsigned int curline)
{
	stack_t *nm;

	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", curline);
		free_st();
		exit(EXIT_FAILURE);
	}
	nm = *head;
	*head = (*head)->next;
	free(nm);
}
/**
 * op_swap - swaps top 2 element in stack
 * @head: head of linked list
 * @curline: line number
 * Return: nothing
 */
void op_swap(stack_t **head, unsigned int curline)
{
	int k = 0;

	stack_t *nm = NULL
		;
	nm = *head;

	for (; nm != NULL; nm = nm->next, k++)
		;
	if (k < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", curline);
		free_st();
		exit(EXIT_FAILURE);
	}
	nm = *head;
	*head = (*head)->next;
	nm->next = (*head)->next;
	nm->prev = *head;
	(*head)->next = nm;
	(*head)->prev = NULL;
}
