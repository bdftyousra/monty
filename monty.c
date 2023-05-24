#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "push.c"
#include "pall.c"
#include "pint.c"
#include "pop.c"
#include "swap.c"
#include "monty.h"
#include "add.c"

#define MAX_LINE_LENGTH 100

void process_file(FILE *file, int stack[], int *top);
void process_line(char *line, int line_number, int stack[], int *top);
/**
 * main - I extracted the functionality of processing the file and processing ,
 * each line into two separate functions: process_file and process_line,
 * @argc : argc
 * @argv: argv
 * Return: 0
 * By : yousra_boudouft
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	FILE *file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error opening file: %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	int stack[MAX_LINE_LENGTH];
	int top = -1;

	process_file(file, stack, &top);

	fclose(file);

	return (0);
}
/**
 * process_file - I extracted the functionality
 * of processing the file and processing ,
 * each line into two separate functions: process_file and process_line,
 * @file : file
 * @stack: stack[]
 * @top: top
 * Return: 0
 * By : yousra_boudouft
 */
void process_file(FILE *file, int stack[], int *top)
{
	char line[MAX_LINE_LENGTH];
	int line_number = 0;

	while (fgets(line, sizeof(line), file))
	{
		line_number++;
		line[strcspn(line, "\n")] = '\0';/*Remove trailing newline*/

		process_line(line, line_number, stack, top);
	}
}
/**
 * process_line - I extracted the functionality
 * of processing the file and processing ,
 * each line into two separate functions: process_file and process_line,
 * @line : line
 * @line_number : line_number
 * @stack: stack[]
 * @top: top
 * Return: 0
 * By : yousra_boudouft
 */
void process_line(char *line, int line_number, stack_t **stack, stack_t **top)
{
	char *token = strtok(line, " ");

	if (token != NULL)
	{
		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, " ");
			if (token != NULL)
				push(line_number, token, stack, top);
			else
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
		}
		else if (strcmp(token, "add") == 0)
			add(stack, line_number);
		else if (strcmp(token, "pall") == 0)
			pall((const stack_t **)stack, *top);
		else if (strcmp(token, "pint") == 0)
			pint(line_number, (const stack_t **)stack, *top);
		else if (strcmp(token, "pop") == 0)
			pop(line_number, top);/* Pass the value of top as an argument */
	}
}

