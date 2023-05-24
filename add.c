#include "monty.h"
/**
 * add - Frees a stack.
 * @line_number: line_number
 * @stack: stack
 * By : yousra_boudouft
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	int sum = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = sum;

	stack_t *temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}
