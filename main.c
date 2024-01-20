#include "monty.h"
mont_t st;
/**
 * main - enry point
 *
 * @argc: arguement count
 * @argv: arguement vector
 * Return: 0 o success
 */
int main(int argc, char *argv[])
{


	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *fd;
	size_t size = 256;
	ssize_t numlines = 0;
	char *lines[2] = {NULL, NULL};

	fd = checks_input(argc, argv);
	start_st(fd);
	numlines = getline(&st.buff, &size, fd);
	while (numlines != -1)
	{
		lines[0] = _strtoky(st.buff, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = get_ops(lines[0]);
			if (!f)
			{
				fprintf(stderr, "L%u: ", st.curr);
				fprintf(stderr, "unknown instructions %s\n", lines[0]);
				free_st();
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

/**
 * free_st - frees global variable
 *
 * Return: nothing
 */
void free_st(void)
{
	free_listint(st.head);
	free(st.buff);
	fclose(st.fd);
}


/**
 * start_st - initializes global variables
 * @fd: file descriptor
 * Return: no retrn
 */
void start_st(FILE *fd)
{
	st.elem = 1;
	st.curr = 1;
	st.arg = NULL;
	st.head = NULL;
	st.fd = fd;
	st.buff = NULL;
}
/**
 * checks_input - check if file exist and opened
 * @argc: arguement count
 * @argv: arguement vector
 * Return: file struct
 */
FILE *checks_input(int argc, char *argv[])
{
	FILE *fd;

	if (argc == 1 || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		fprintf(stderr, " Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

