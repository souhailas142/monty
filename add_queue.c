#include "monty.h"
/**
 * _queue - print the top
 * @head: head
 * @number: line_number
 * Return: nothing
 */
void _queue(stack_t **head, unsigned int number)
{
	(void)head;
	(void)number;
	bus.lifi = 1;
}
/**
 * addQueue - add node to the end of the stack
 * @head: head
 * @n: n
 * Return: nothing
 */
void addQueue(stack_t **head, int n)
{
	stack_t	*end_node;
	stack_t	*tmp;

	tmp = *head;
	end_node = malloc(sizeof(stack_t));
	if (!end_node)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	end_node->n = n;
	end_node->next = NULL;
	if (!(*head))
	{
		end_node->prev = NULL;
		(*head) = end_node;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		end_node->next = tmp;
		tmp->next = end_node;
	}
}
