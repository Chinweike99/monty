#include "monty.h"

/**
 * _pstr - mod top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	int x = 0;
	stack_t *temp = *stack;

	(void)line_number;

	while (temp)
	{
		x = (*temp).n;
		if (x == 0 || _isalphabet(x) == 0)
			break;
		putchar(x);
		temp = (*temp).next;
	}
	putchar('\n');
}

/**
 * rot_l - Function to mod top of stack y second top stack
 * @stack: The pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void rot_l(stack_t **stack, unsigned int line_number)
{
	stack_t *tracker = *stack;
	int aux = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;

	aux = (*tracker).n;

	while ((*tracker).next)
	{
		tracker = (*tracker).next;
		tracker->prev->n = (*tracker).n;
	}

	(*tracker).n = aux;
}

/**
 * rot_r - mod top of stack y second top stacks
 * @stack: The  pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void rot_r(stack_t **stack, unsigned int line_number)
{
	stack_t *tracker = *stack;

	int aux1 = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;

	while (tracker->next)
		tracker = tracker->next;

	aux1 = tracker->n;
	while (tracker->prev)
	{
		tracker = tracker->prev;
		tracker->next->n = tracker->n;
	}

	tracker->n = aux1;
}

/**
 * _nop - nop top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void _nop(__attribute__ ((unused))stack_t **stack,
		                __attribute__ ((unused)) unsigned int line_number)
{
	;
}
