#include "monty.h"
/**
 * executes_file - reads and executes opcode from a file
 * @stack: pointer to top of stack
 * Return: nothing
 */
void executes_file(stack_t **stack)
{
	char *opcode = NULL;
	size_t l_len = 0;
	ssize_t nmread;
	unsigned int line_number = 0;

	while ((nmread = getline(&st.line, &l_len, st.file)) != -1)
	{
		line_number++;
		opcode = strtok(st.line, "\t\r\n\a");
		st.arg = strtok(NULL, "\n\t");
		if (opcode == NULL || *opcode == '#')
			continue;
		executes_opcode(opcode, stack, line_number);
	}
}

/**
 * executes_opcode - executes a single opcode
 * @opcode: opcode to be executed
 * @stack: pointer to the top of stack
 * @line_number: line number of opcode
 */
void executes_opcode(char *opcode, stack_t **stack, unsigned int line_number)
{
	instruction_t instructions[] =
	{
		{"push", opc_push},
		{"pall", opc_pall},
		{"pint", opc_pint},
		{"pop", opc_pop},
		{"swap", opc_swap},
		{NULL, NULL}
	};

	int i;

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	frees_stack(*stack);
	fclose(st.file);
	free(st.line);
	exit(EXIT_FAILURE);
}
