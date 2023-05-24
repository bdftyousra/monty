#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "pint.h"
#include "pop.h"

/**
 * process_bytecodes - Process the bytecodes from the file
 * @file: Pointer to the bytecode file
 * @stack: Pointer to the stack
 */
void process_bytecodes(FILE *file, Stack *stack)
{
	char line[100];
	int line_number = 1;

	while (fgets(line, sizeof(line), file))
	{
		char *opcode = strtok(line, " \t\n");

		if (opcode != NULL)
		{
			if (strcmp(opcode, "push") == 0)
			{
				char *arg = strtok(NULL, " \t\n");

				if (arg == NULL)
				{
					printf("L%d: usage: push integer\n", line_number);
					exit(EXIT_FAILURE);
				}
				int value = atoi(arg);

				push(stack, value);
			}
			else if (strcmp(opcode, "pall") == 0)
			{
				pall(stack);
			}
			else if (strcmp(opcode, "pint") == 0)
			{
				pint(stack, line_number);
			}
			else if (strcmp(opcode, "pop") == 0)
			{
				pop(stack, line_number);
			}
		}
		line_number++;
	}
}
/**
 * main - Entry point of the program
 * @argc : argc
 * @argv: argv
 *
 * Return: 0 on success, or EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <bytecode_file>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	Stack stack;

	stack.top = 0;
	FILE *file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Failed to open bytecode file!\n");
		return (EXIT_FAILURE);
	}
	process_bytecodes(file, &stack);

	fclose(file);

	return (0);
}
