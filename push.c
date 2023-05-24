#include <stdio.h>
#include <stdlib.h>

#include "monty_types.h"

#define STACK_SIZE 1000
/**
 * push - driver function for monty program
 * @line_number: argc
 * @argument: argv
 * @top: top
 * Return: 0
 */
void push(int line_number, const char *argument, stack_t **top)
{
	int num = atoi(argument);

	if (num == 0 && *argument != '0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*top) >= (STACK_SIZE - 1))
	{
		fprintf(stderr, "L%d: Stack overflow\n", line_number);
		exit(EXIT_FAILURE);
	}
	stack[(*top) + 1] = num;
	(*top)++;
}
