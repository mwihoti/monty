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
/**
 * op_rotlt - rotates the stack to the top
 * @rtr: head of linked list
 * @rtrline: line number
 * Return: nothing
 */
void op_rotlt(stack_t **rtr, unsigned int rtrline)
{
	stack_t *rt = NULL;
	stack_t *rt1 = NULL;
	(void)rtrline;

	if (*rtr == NULL)
		return;

	if ((*rtr)->next == NULL)
		return;

	rt = (*rtr)->next;
	rt1 = *rtr;

	for (; rt1->next != NULL; rt1 = rt1->next)
		;
	rt->prev = NULL;
	rt1->next = *rtr;
	(*rtr)->next = NULL;
	(*rtr)->prev = rt1;
	*rtr = rt;
}
/**
 * op_rotlt - rotates the stack to the top
 * @rtr: head of linked list
 * @rtrline: line number
 * Return: nothing
 */
void op_rotr(stack_t **rtr, unsigned int rtrline)
{
	stack_t *rt = NULL;
        (void)rtrline;

	if (*rtr == NULL)
                return;

        if ((*rtr)->next == NULL)
                return;
	rt = *rtr;

	for (; rt->next != NULL; rt = rt->next)
		;
	rt->prev->next = NULL;
	rt->next = *rtr;
	rt->prev = NULL;
	(*rtr)->prev = rt;
	*rtr = rt;
}
/**
 * op_queue - sets the format of data to queue
 *
 * @que: head of list
 * @queline: line number
 * Return: nothing
 */

void op_queue(stack_t **que, unsigned int queline)
{
	(void)que;
	(void)queline;

	st.elem = 0;
}
