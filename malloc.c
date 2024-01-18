#include "monty.h"
/**
 * get_calloc - concate two strings
 * @nmel: number of elements
 * @size: type of elements
 * Return: nothing
 */
void *get_calloc(unsigned int nmel, unsigned int size)
{
	void *p = NULL;
	unsigned int i;

	if (nmel == 0 || size == 0)
	{
		return (NULL);
	}
	p = malloc(nmel * size);

	if (p == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < (nmel * size); 1++)
	{
		*((char *)(p) + i) = 0;
	}
	return (p);
}
/**
 * get_realloc - change the size and copies content
 * @ptr: malloc pointer to reallocate
 * @old_size: old number of bytes
 * @new_size: new number of bytes
 * Return: nothing
 */
void get_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p = NULL;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		p = malloc(new_size);
		if (!p)
			return (NULL);
		return (p);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size > old_size)
	{
		p = malloc(new_size);
		if (!p)
			return (NULL);
		for (i = 0; i < old_size; i++)
			p[i] = *((char *)ptr + i);
		free(ptr);
	}
	else
	{
		p = malloc(new_size);
		if (!p)
			return (NULL);
		for (i = 0; i < new_size; i++)
			p[i] = *((char *)ptr + i);
		free(ptr);
	}
	return (p);
}


