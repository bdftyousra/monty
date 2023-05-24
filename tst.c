#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"
/**
 * createStack - driver function for monty program
 * Return: 0
 */

Stack *createStack(void)
{
	Stack *stack = (Stack *)malloc(sizeof(Stack));

	if (stack == NULL)
	{
		printf("Memory allocation error\n");
		exit(EXIT_FAILURE);
	}
	stack->top = NULL;
	return (stack);
}
/**
 * createNode - driver function for monty program
 *@value: value
 * Return: 0
 */
StackNode *createNode(int value)
{
	StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));

	if (newNode == NULL)
	{
		printf("Memory allocation error\n");
		exit(EXIT_FAILURE);
	}
	newNode->data = value;
	newNode->next = NULL;
	return (newNode);
}
/**
 * push - driver function for monty program
 *@value: value
 *@stack :stack
 * Return: 0
 */
void push(Stack *stack, int value)
{
	StackNode *newNode = createNode(value);

	newNode->next = stack->top;
	stack->top = newNode;
}
/**
 * pall - driver function for monty program
 * @stack :stack
 * Return: 0
 */
void pall(Stack *stack)
{
	StackNode *current = stack->top;

	while (current != NULL)
	{
		printf("%d\n", current->data);
		current = current->next;
	}
}
