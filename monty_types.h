#ifndef MONTY_TYPES_H
#define MONTY_TYPES_H

/**
 * struct stack_s- Frees a stack.
 * @n: n
 * @prev: prev
 * By : yousra_boudouft
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
} stack_t;

#endif /* MONTY_TYPES_H */
