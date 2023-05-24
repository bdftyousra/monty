#include <stdio.h>
#include <stdlib.h>
/**
 * pop - pop function, which takes the stack and top variables as parameters
 * @top: top
 * @line_number: line_number
 * Return: 0
 * By : yousra_boudouft
 */
void pop(int line_number, int *top)
{
	if (*top < 0)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*top)--;
}
