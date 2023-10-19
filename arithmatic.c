#include "monty.h"

/**
 * _subtract - Function that subtract top of stack
 * @stack: pointer to lists of the monty stack
 * @line_number: The number of line that opcode occurs on
 */
void _subtract(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	int subtract = 0;
	int x = 0;

	if (top == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (top)
	{
		top = top->next;
		x++;
	}

	if (stack == NULL || (*stack)->next == NULL || x <= 1)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	subtract = (*stack)->next->n - (*stack)->n;
	_delete(stack, line_number);

	(*stack)->n = subtract;
}

/**
 * _multiply - Function that multiply top of stack and y second top stack
 * @stack: pointer to the list of monty stack
 * @line_number: number of line opcode occurs on
 */
void _multiply(stack_t **stack, unsigned int line_number)
{
	int a;

	if (*stack == NULL || (*(*stack)).next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		freeDlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		a = (*(*stack)).n;
		_delete(stack, line_number);
		(*(*stack)).n *= a;
	}
}

/**
 * _div - Function that divides top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @line_number: The number of line opcode occurs on
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int x = 0;

	if (*stack == NULL || (*(*stack)).next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		freeDlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*(*stack)).n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		freeDlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		x = (*(*stack)).n;
		_delete(stack, line_number);
		(*(*stack)).n /= x;
	}
}

/**
 * _modul - Performs modulus on top of stack y second top stack
 * @stack: The pointer to lists for monty stack
 * @line_number: The number of line opcode occurs on
 */
void _modul(stack_t **stack, unsigned int line_number)
{
	int x = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		freeDlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		freeDlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		x = (*stack)->n;
		_delete(stack, line_number);
		(*stack)->n %= x;
	}
}
/**
 * parseLine - Function that parses a line for an opcode and arguments
 * @queue: the line that is to be parsed
 * @stack: The pointer to the head of the stack
 * @line_number: the current line number
 * Return: returns the opcode on success or null on failure
 */
char *parseLine(char *queue, stack_t **stack, unsigned int line_number)
{
	char *op_code, *push, *arg;
	(void)stack;

	push = "push";
	op_code = strtok(queue, "\n ");
	if (op_code == NULL)
		return (NULL);
	if (strcmp(op_code, push) == 0)
	{
		arg = strtok(NULL, "\n ");
		if (_number(arg) == 1 && arg != NULL)
			var_global.push_arg = atoi(arg);
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	return (op_code);
}
