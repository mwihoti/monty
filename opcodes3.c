#include "monty.h"
/**
 * op_pchar - prints char value of top element
 *
 * @charc: head of linked list
 * @charline: line number
 * Return: nothing
 */
 
void op_pchar(stack_t **charc, unsigned int charline)
{
	if (charc == NULL || *charc == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", charline);
		free_st();
		exit(EXIT_FAILURE);
	}
	if ((*charc)->n < 0 || (*charc)->n >= 128)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", charline);
		free_st();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*charc)->n);
}
/**
 * op_pstr - prints string at top followed by new line
 * @strline: line number
 * @ppstr: head of linked list
 * Return: nothing
 */
void op_pstr(stack_t **ppstr, unsigned int strline)
{
	stack_t *nm;
	(void)strline;

	nm = *ppstr;

	while (nm && nm->n > 0 && nm->n < 128)
	{
		printf("%c", nm->n);
		nm = nm->next;
	}
	printf("\n");
}
