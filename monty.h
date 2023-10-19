#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/*--- Struct Definitions ---*/
extern int push_arg;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO ALX  project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO ALX project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_variable - opcoode and its function
 * @file: the opcode
 * @push_arg: function to handle the opcode
 * @buffer: pointer to
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO ALX project
 */
typedef struct global_variable
{
	FILE *file;
	int push_arg;
	char *buffer;
} global_var;

extern global_var var_global;
typedef void (*instruct_func)(stack_t **stack, unsigned int line_number);
instruct_func get_op_func(char *ptr);

void _subtract(stack_t **stack, unsigned int line_number);
void _multiply(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _modul(stack_t **stack, unsigned int line_number);
void fileRead(char *filename, stack_t **stack);
int _number(char *str);
char *parseLine(char *queue, stack_t **stack, unsigned int line_number);
void pushTo(stack_t **stack, __attribute__ ((unused))unsigned int line_number);
void print_all(stack_t **stack, __attribute__ ((unused))unsigned int line_number);
void print_int(stack_t **stack, unsigned int line_number);
void _delete(stack_t **stack, unsigned int line_number);
void freeDlistint(stack_t *head);
void _switch(stack_t **stack, unsigned int line_number);
void _plus(stack_t **stack, unsigned int line_number);
void _nop(__attribute__ ((unused))stack_t **stack,
		                __attribute__ ((unused)) unsigned int line_number);
void _pchar(stack_t **stack, unsigned int line_number);
int _isalphabet(int c);
void _pstr(stack_t **stack, unsigned int line_number);
void rot_l(stack_t **stack, unsigned int line_number);
void rot_r(stack_t **stack, unsigned int line_number);



#endif
