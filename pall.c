#include <stdio.h>
#include "monty_types.h"
/**
 * pall - function takes
 * @stack: stack is array
 * @top: top is parameters
 * Return: 0
 */
void pall(const stack_t **stack, int top)
{
	for (int i = top; i >= 0; i--)
	{
		printf("%d\n", stack[i]->n);
	}
}
