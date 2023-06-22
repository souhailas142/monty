#include "monty.h"
/**
 * add_stack - add node to the stack
 * @head: head od the stack
 * @n: number
 * Return: nothing
 */
void add_stack(stack_t **head, int n)
{
	stack_t *new_node;
	stack_t *tmp;

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
