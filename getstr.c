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

	for (i = 0; c1[i] == c2[i] && c1[i]; i++)
		;

	if (c1[i] > c2[i])
		return (1);
	if (c1[i] < c2[i])
		return (-1);
	return (0);
}

/**
 * srch - search if char is inside of a string
 * @s: string to review
 * @c: char to find
 * Return: 1 if success 0 if not
 */
int srch(char *s, char c)
{
	int curr = 0;

	while (s[curr] != '\0')
	{
		if (s[curr] == c)
		{
			break;
		}
		curr++;
	}
	if (s[curr] == c)
		return (1);
	else
		return (0);
}
/**
 * _strtoky - functions that cut a string into tokens
 * @s: string to cut in parts
 * @d: delimeters
 * Return: first partition
 */
char *_strtoky(char *s, char *d)
{
	static char *ult;
	int i = 0, j = 0;

	if (!s)
		s = ult;
	while (s[i] != '\0')
	{
		if (srch(d, s[i]) == 0 && s[i + 1] == '\0')
		{
			ult = s + i + 1;
			*ult = '\0';
			s = s + j;
			return (s);
		}
		else if (srch(d, s[i]) == 0 && srch(d, s[i + 1]) == 0)
			i++;
		else if (srch(d, s[i]) == 0 && srch(d, s[i + 1]) == 1)
		{
			ult = s + i + 1;
			*ult = '\0';
			ult++;
			s = s + j;
			return (s);
		}
		else if (srch(d, s[i]) == 1)
		{
			j++;
			i++;
		}
	}
	return (NULL);
}
