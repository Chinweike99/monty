#include "monty.h"
/**
 * _switch - Function to swap top of stack y second top stack
 * @stack: The pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */

void _switch(stack_t **stack, unsigned int line_number)
{
	int temp;
	stack_t *tracker;

	tracker = *stack;
	if (tracker == NULL || (*tracker).next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*tracker).n;
	(*tracker).n = (*tracker).next->n;
	tracker->next->n = temp;
}

/**
 * _plus - Function to add top of stack y second top stack
 * @stack: The pointer to the lists for monty stack
 * @line_number: number of line opcode occurs on
 */

void _plus(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int sum = 0;
	int x = 0;

	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (temp)
	{
		temp = temp->next;
		x++;
	}

	if (stack == NULL || (*stack)->next == NULL || x <= 1)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->next->n + (*stack)->n;
	_delete(stack, line_number);

	(*stack)->n = sum;
}


/**
 * _pchar - prints the ASCII value of a number
 * @stack: pointer to the top of the stack
 * @line_number: the index of the current line
 *
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	int value;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		freeDlistint(*stack);
		exit(EXIT_FAILURE);
	}

	value = (*stack)->n;
	if (value > 127 || value < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		freeDlistint(*stack);
		exit(EXIT_FAILURE);
	}

	putchar(value);
	putchar('\n');
}

/**
 * _isalphabet - Function to check if int is in alphabet
 * @c: int value to return
 * Return: 1 if yes, 0 if no
 */
int _isalphabet(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (1);
	else
		return (0);
}
