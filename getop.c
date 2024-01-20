#include "monty.h"

/**
 * get_ops - select the correct opcode to perform
 * @opc: opcode passed
 *
 * Return: pointer to the function that executes the opcode
 */
void (*get_ops(char *opc))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
		{"sub", op_sub},
		{"div", op_div},
		{"mul", op_mul},
		{"pchar", op_pchar},
		{"pstr", op_pstr},
		{"rotl", op_rotlt},
		{"rotr", op_rotr},
		{"queue", op_queue},
		{"stack", op_stack},
		{NULL, NULL}
	};
	int i;

	for (i = 0; instruct[i].opcode; i++)
	{
	if (get_strcmp(instruct[i].opcode, opc) == 0)
		break;
	}
	return (instruct[i].f);
}
