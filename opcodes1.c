#include "monty.h"
/**
 * op_push - pushes items to stack
 * @head: head of linked list
 * @curline: number of line
 * Return: no return
 */
void op_push(stack_t **head, unsigned int curline)
{
	int n, j;
	if(!st.arg)
	{
		dprintf(2, "L%u: ", curline);
		dprintf(2, "Usage: push integer\n");
		free_st();
		exit(EXIT_FAILURE);
	}
	for (j = 0; st.arg.arg[j] != '\0'; j++)
	{
		if(!isdigit(st.arg[j]) && st.arg[j] != '-')
		{
			dprintf(2, "L%u: "", curline);
			dprintf(2, "usage: push integer\n");
			free_st();
			exit(EXIT_FAILURE);
		}
	}
	n = atoi(st.arg);
	if(st.elem == 1)
		add_node(head, n);
	else
		add_nodeend(head, n);
}

