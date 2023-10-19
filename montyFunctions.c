#define _GNU_SOURCE
#include "monty.h"
/**
 * fileRead - Function that reads a bytecode file and runs commands
 * @filename: pathname of file
 * @stack: The pointer to the top of the stack
 */
void fileRead(char *filename, stack_t **stack)
{
	char *queue;
	size_t x = 0;
	int read;
	int queueCount = 1;
	instruct_func k;
	int check;

	var_global.file = fopen(filename, "r");
	if (var_global.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&var_global.buffer, &x, var_global.file)) != -1)
	{
		queue = parseLine(var_global.buffer, stack, queueCount);
		if (queue == NULL || queue[0] == '#')
		{
			queueCount++;
			continue;
		}
		k = get_op_func(queue);
		if (k == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", queueCount, queue);
			exit(EXIT_FAILURE);
		}
		k(stack, queueCount);
		queueCount++;
	}
	free(var_global.buffer);
	check = fclose(var_global.file);
	if (check == -1)
		exit(-1);
}

/**
 * get_op_func -  checks opcode and returns the correct function
 * @ptr: the opcode
 * Return: returns a functions, or NULL on failure
 */
instruct_func get_op_func(char *ptr)
{
	int x;

	instruction_t instruct[] = {
		{"push", pushTo},
		{"pall", print_all},
		{"pint", print_int},
		{"pop", _delete},
		{"swap", _switch},
		{"add", _plus},
		{"nop", _nop},
		{"sub", _subtract},
		{"mul", _multiply},
		{"div", _div},
		{"mod", _modul},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", rot_l},
		{"rotr", rot_r},
		{NULL, NULL},
	};

	x = 0;
	while (instruct[x].f != NULL && strcmp(instruct[x].opcode, ptr) != 0)
	{
		x++;
	}

	return (instruct[x].f);
}

/**
 * _number - Function that checks if a string is a number
 * @str: string being passed
 * Return: returns 1 if string is a number, 0 otherwise
 */
int _number(char *str)
{
	unsigned int x;

	if (str == NULL)
		return (0);
	x = 0;
	while (str[x])
	{
		if (str[0] == '-')
		{
			x++;
			continue;
		}
		if (!isdigit(str[x]))
			return (0);
		x++;
	}
	return (1);
}
