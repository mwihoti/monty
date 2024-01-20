#include "monty.h"

/**
 * opc_add - adds top two elements
 * @stack: pointer to top of stack
 * @line_number: line number of opcode
 */
void opc_add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free(st.line);
		frees_stack(*stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	opc_pop(stack, line_number);
}

/**
 * opc_swap - swaps the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
*/
void opc_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free(st.line);
		frees_stack(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;

	if (tmp->next != NULL)

	tmp->next->prev = *stack;
	tmp->prev = NULL;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = tmp;
}

