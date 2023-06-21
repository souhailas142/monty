#include "monty.h"
/**
 * free_stack - free all nodes
 * @head: head of the stack
 * Return: nothing
 */
void free_stack(stack_t *head)
{
	stack_t *tmp = head;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
