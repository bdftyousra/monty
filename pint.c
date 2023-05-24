#include <stdio.h>
#include "stack.h"

#include <stdlib.h>

/**
 * pint - Prints the value at the top of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Current line number in the bytecode file.
 */
void pint(Stack *stack, unsigned int line_number)
{
	if (stack->top == 0)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", stack->values[stack->top - 1]);
}
