#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/**
 * push - Pushes an element onto the stack.
 * @stack: Pointer to the stack.
 * @value: Value to be pushed.
 * @line_number : line_number
 *
 */
void push(Stack *stack, int value, int line_number)
{
	if (stack->top == STACK_SIZE - 1)
	{
		fprintf(stderr, "L%d: stack overflow\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	stack->top++;
	stack->values[stack->top] = value;
}
