#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
/**
 * push - Pushes an element to the stack.
 * @stack: Pointer to the stack.
 * @value: Value to be pushed.
 *
 * Return: void
 */
void push(Stack *stack, int value)
{
	if (stack->top >= STACK_SIZE)
	{
		printf("Stack overflow!\n");
		exit(EXIT_FAILURE);
	}
	stack->values[stack->top++] = value;
}
/**
 * pall - Prints all the elements in the stack.
 * @stack: Pointer to the stack.
 *
 * Return: void
 */
void pall(Stack *stack)
{
	int i;

	for (i = stack->top - 1; i >= 0; i--)
	{
		printf("%d\n", stack->values[i]);
	}
}
/**
 * pop - Removes the top element from the stack.
 * @stack: Pointer to the stack.
 *
 * Return: void
 */
void pop(Stack *stack)
{
	if (stack->top <= 0)
	{
		printf("Stack underflow!\n");
		exit(EXIT_FAILURE);
	}
	stack->top--;
}
