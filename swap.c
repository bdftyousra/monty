#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * swap - Swaps the top two elements of the stack.
 * @line_number: Line number of the opcode.
 * @stack: The stack.
 * By : yousra_boudouft
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack && (*stack)->next)
	{
		temp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = temp;
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
