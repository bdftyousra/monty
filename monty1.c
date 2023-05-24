#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "monty.h"
#include "
/**
 * parse_file - driver function for monty program
 *@filename: filename
 * Return: 0
 */
void parse_file(const char *filename)
{
	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		printf("Error opening file\n");
		exit(EXIT_FAILURE);
	}

	char line[100];
	int line_number = 0;
	/*Stack *stack = createStack();*/

	while (fgets(line, sizeof(line), file))
	{
		line_number++;

		char *opcode = strtok(line, " \t\n");

		if (opcode == NULL || opcode[0] == '#')
			continue;
		if (strcmp(opcode, "push") == 0)
		{
			char *arg = strtok(NULL, " \t\n");

			if (arg == NULL || !isdigit(arg[0]))
			{
				printf("L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			/*push(stack, atoi(arg));*/
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			/*pall(stack);*/
			printf("L%d: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}
	fclose(file);
}
/**
 * main - driver function for monty program
 *@argc: argc
 *@argv: argv
 * Return: 0
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Usage: %s <filename>\n", argv[0]);
		return (EXIT_FAILURE);
	}

	const char *filename = argv[1];

	parse_file(filename);

	return (0);
}
