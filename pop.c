#include <stdio.h>
#include "stack.h"

#include <stdlib.h>
/**
 * pop - Removes the top element from the stack.
 * @stack: Pointer to the stack.
 * @line_number: Current line number in the bytecode file.
 */
void pop(Stack *stack, line_number)
{
	if (stack->top == 0)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	stack->top--;
}
