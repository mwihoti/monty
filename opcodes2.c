#include "monty.h"

/**
 * op_add - adds top two elements
 * @stack: head of linked list
 * @curline: line number
 * Return: nothing
 */
void op_add(stack_t **stack, unsigned int curline)
{
	int k = 0;
	stack_t *nm = NULL;

	nm = *stack;

	for (; nm != NULL; nm = nm->next, k++)
		;
	if (k < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", curline);
		free_st();
		exit(EXIT_FAILURE);
	}
	nm = (*stack)->next;
	nm->n += (*stack)->n;
	op_pop(stack, curline);
}
/**
 * op_nop - does nothing
 * @stack: head of list
 * @curline: line number
 * Return: nothing
 */

void op_nop(stack_t **stack, unsigned int curline)
{
	(void)stack;
	(void)curline;
}
