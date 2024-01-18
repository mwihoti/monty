#include "monty.h"
/**
 * get_strcmp - compares strings
 * @c1: str to compare
 * @c2: str to compare
 * Return: 0 if c1 and c2 are equal else 1 or -1
 */
int get_strcmp(char *c1, char *c2)
{
	int i;

	for (i = 0; c1[i] == c2[i] && c1[i]; i++);
	if (c1[i] > c2[i])
		return (1);
	if (c1[i] < c2[i])
		return (-1);
	return (0);
}
 
