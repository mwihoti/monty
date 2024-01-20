#include "monty.h"

/**
 * opc_push - pushes elements to stack
 * @stack: pointer
 * @line_number: current line
 */
void opc_push(stack_t **stack, unsigned int line_number)
{
	int n;

	if (st.arg == NULL || !is_number(st.arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		frees_stack(*stack);
		fclose(st.file);
		free(st.line);
		exit(EXIT_FAILURE);
	}

	n = atoi(st.arg);
	if (add_node(stack, n) ==  NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		frees_stack(*stack);
		fclose(st.file);
		free(st.line);
		exit(EXIT_FAILURE);
	}
}
/**
 * is_number - checks if string is a number
 * @str: string to check
 *
 * Return: 1 if number, else 0
 */
int is_number(char *str)
{
	if (str == NULL || *str == '\0')
		return (0);

	if (*str == '-' || *str  == '+')
		str++;

	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);

		str++;
	}
	return (1);
}
/*
 * opc_pall - prints all values on stack
 * @stack: stack pointer
 * line_number: line number of opcode
 */

void opc_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;
	
	while (curr != NULL)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
		(void)line_number;
	}

}
/*
 * opc_pint - prints all values on stack
 * @stack: stack pointer
 * line_number: line number of opcode
 */
void opc_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free(st.line);
		frees_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/*
 * opc_pop - prints all values on stack
 * @stack: stack pointer
 * line_number: line number of opcode
 */
void opc_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free(st.line);
		frees_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	free(*stack);
	*stack = temp;

	if (*stack != NULL)
		(*stack)->prev = NULL;
}
