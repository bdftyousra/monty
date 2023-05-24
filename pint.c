#include <stdio.h>
#include <stdlib.h>

#include "monty_types.h"
/**
 * pint - Prints the value at the top of the stack, followed by a newline.
 * @stack: Pointer to the top of the stack
 * @top: Current line number in the Monty file
 * @line_number: line_number
 * By : yousra_boudouft
 */
void pint(int line_number, const stack_t **stack, int top)
{
	if (top < 0)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", stack[top]->n);
}
