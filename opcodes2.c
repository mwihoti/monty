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
/**
 * op_sub - subtracts the top elem with second elem
 * @stack: head of list
 * @curline: line number
 * Return: nothing
 */
void op_sub(stack_t **stack, unsigned int curline)
{
	int k = 0;
	stack_t *nm = NULL;

	nm = *stack;

	for (; nm != NULL; nm = nm->next, k++)
		;

	if (k < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", curline);
		free_st();
		exit(EXIT_FAILURE);
	}
	nm = (*stack)->next;
	nm->n -= (*stack)->n;
	op_pop(stack, curline);
}
/**
 * op_div - divides the second top elm of stack by second elem
 * @divs: head of list
 * @divline: line number
 * Return: nothing
 */
void op_div(stack_t **divs, unsigned int divline)
{
	int k = 0;
	stack_t *nm = NULL;

	nm = *divs;

	for(; nm != NULL; nm = nm->next, k++)
		;
	if (k < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", divline);
		free_st();
		exit(EXIT_FAILURE);
	}

	if ((*divs)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", divline);
		free_st();
		exit(EXIT_FAILURE);
	}
	nm = (*divs)->next;
	nm->n /= (*divs)->n;
	op_pop(divs, divline);
}
/**
 * op_mul - multiplies top and second elements of stack
 *
 * @mult: head of list
 * @multline: line number
 * Return: nothing
 */
void op_mul(stack_t **mult, unsigned int multline)
{
	int k = 0;
	stack_t *nm = NULL;

	nm = *mult;

	for (; nm != NULL; nm = nm->next, k++)
		;
	if (k < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", multline);
		free_st();
		exit(EXIT_FAILURE);
	}

	nm = (*mult)->next;
	nm->n *= (*mult)->n;
	op_pop(mult, multline);
}
