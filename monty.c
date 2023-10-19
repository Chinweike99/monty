#include "monty.h"
global_var var_global;
/**
 * main - driver function for monty program
 * @argc: int num of arguments
 * @argv: opcode file
 * Return: 0
 */
int main(int argc, char **argv)
{
	stack_t *stack;

	stack = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fileRead(argv[1], &stack);
	freeDlistint(stack);
	return (0);
}
