#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/types.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct mont - global structure to use
 * @elem: is either stack or queue
 * @curr: line content
 * @arg: second param in line content
 * @head: double linked list
 * @fd: its a file descriptor
 * buff: input text
 */
typedef struct mont
{
	int elem;
	unsigned int curr;
	char *arg;
	stack_t *head;
	FILE *fd;
	char *buffer;
}mont_t;
extern mont_t st;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/*opcode*/
void op_push(stack_t **head, unsigned int curline);
void op_pall(stack_t **head, unsigned int curline);
void op_pint(stack_t **head, unsigned int curline);
void op_pop(stack_t **head, unsigned int curline);
void op_swap(stack_t **head, unsigned int curline);
/*get */
void (*get_ops(char *opc))(stack_t **stack, unsigned int line_number)
/*double link func*/

stack_t *add_node(stack_t **head, const int n);
stack_t *add_nodeend(stack_t **head, const int n);
int get_strcmp(char *c1, char *c2);
/*main*/
void free_st(void);
#endif
