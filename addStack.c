#include "monty.h"
/**
 * _stack - print the top
 * @head: head of the stack
 * @number: line_number
 * Return: nothing
 */
void _stack(stack_t **head, unsigned int number)
{
	(void)head;
	(void)number;
	bus.lifi = 0;
}
/**
 * addStack - add node to the stack
 * @head: head od the stack
 * @n: number
 * Return: nothing
 */
void addStack(stack_t **head, int n)
{
	stack_t *new_node, *tmp;

	tmp = *head;
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (tmp)
		tmp->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}
