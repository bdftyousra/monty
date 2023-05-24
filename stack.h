#ifndef STACK_H
#define STACK_H

#define STACK_SIZE 100
/**
 * struct Stack - A stack data structure
 * @values : An array to store the stack elements
 * @top: The index of the top element in the stack
 */
typedef struct Stack
{
	int values[STACK_SIZE];
	int top;
} Stack;
/**
 * push - Pushes an element onto the stack.
 * @stack: Pointer to the stack.
 * @value: Value to be pushed.
 */
void push(Stack *stack, int value);
/**
 * pall - Prints all the values on the stack.
 * @stack: Pointer to the stack.
 */
void pall(Stack *stack);
/**
 * pop - Removes the top element from the stack.
 * @stack: Pointer to the stack.
 */
void pop(Stack *stack);

#endif /* STACK_H */
