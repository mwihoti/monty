#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
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
	char *buff;
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
void op_add(stack_t **stack, unsigned int curline);
void op_nop(stack_t **stack, unsigned int curline);
void op_sub(stack_t **stack, unsigned int curline);
void op_div(stack_t **divs, unsigned int divline);
void op_mul(stack_t **mult, unsigned int multline);
void op_pchar(stack_t **charc, unsigned int charline);
void op_pstr(stack_t **ppstr, unsigned int strline);
void op_rotlt(stack_t **rtr, unsigned int rtrline);
void op_rotr(stack_t **rtr, unsigned int rtrline);

void op_stack(stack_t **stac, unsigned int stacline);
void op_queue(stack_t **que, unsigned int queline);
/*get */
void (*get_ops(char *opc))(stack_t **stack, unsigned int line_number);
/*double link func*/
int srch(char *s, char c);
char *_strtoky(char *s, char *d);
void free_listint(stack_t *head);
void *get_calloc(unsigned int nmel, unsigned int size);
void *get_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
stack_t *add_node(stack_t **head, const int n);
stack_t *add_nodeend(stack_t **head, const int n);
int get_strcmp(char *c1, char *c2);
/*main*/
FILE *checks_input(int argc, char *argv[]);
void start_st(FILE *fd);
void free_st(void);
#endif
