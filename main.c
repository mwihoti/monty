#include "monty.h"

mont_t st;
/**
 * free_st - frees global variable
 *
 * Return: nothing
 */
void free_st(void)
{
}
/**
 * main - entry point
 * argc: arguement count
 * @argv: arguement vector
 * Return: o on success else otherwise
 */

int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *fd;
	ssize_t size = 256;
	ssize_t numlines = 0;
	char *lines[2] = {NULLL, NULL};

	fd = check_input(argc, argv);
	start_st(fd);
	numlines = getline(&st.buff, &size, fd);
	while (numlines != -1)
	{
		line[0] = _strtoky(st.buff, " \t\n");
		if (lines[0] && lines[]0[0] != '#')
		{
			f = get_ops(lines[0]);
			if(!f)
			{
				fprintf(stderr, "L%u: ", st.curr);
				fprintf(stderr, "unknown instructions %s\n", lines[0]);
				free_str();
				exit(EXIT_FAILURE);
			}
			st.arg = _strtoky(NULL, "\t\n");
			f(&st.head, st.curr);
		}
		numlines = getline(&st.buff, &size, fd);
		st.curr++;
	}
	free_st();

	return (0);
}
