#include "monty.h"

mont_t st;

/**
 * main - entry point for the monty program
 * @argc: number of command line arguments
 * @argv: array of command line argument strings
 *
 * Return: 0 on success, non-zero on failure
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	st.file = fopen(argv[1], "r");
	if (st.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	execute_file(&stack);
	fclose(st.file);
	free(st.line);
	free_stack(stack);
	exit(EXIT_SUCCESS);
}
