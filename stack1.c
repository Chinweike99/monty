#include "monty.h"
/**
 * pushTo - Function to push int to a stack
 * @stack: The linked lists for monty stack
 * @line_number: The number of line opcode occurs on
 */
void pushTo(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *top;
	(void)line_number;

	top = malloc(sizeof(stack_t));
	if (top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	(*top).n = var_global.push_arg;
	(*top).next = *stack;
	(*top).prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = top;
	*stack = top;
}

/**
 * print_all - Function to print all function
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void print_all(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *tracker;

	tracker = *stack;
	while (tracker != NULL)
	{
		printf("%d\n", (*tracker).n);
		tracker = (*tracker).next;
	}
}

/**
 * print_int - Function to print int a top of stack
 * @stack: The pointer to linked list stack
 * @line_number: number of line opcode occurs on
 *
 */
void print_int(stack_t **stack, unsigned int line_number)
{
	stack_t *tracker;

	tracker = *stack;
	if (tracker == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*tracker).n);
}

/**
 * _delete - Function to remove element a list
 *@stack: The pointer to first node
 *@line_number: the integer
 *Return: Return void
 */
void _delete(stack_t **stack, unsigned int line_number)
{
	stack_t *newnode = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = (*newnode).next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(newnode);
}

/**
 * freeDlistint - Function to free a list
 * @head: head pointer to first node
 *
 */
void freeDlistint(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = (*head).next;
		free(head);
		head = temp;
	}
}
