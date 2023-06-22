#include "monty.h"
/**
 * _rotl - rotates the stack to the top
 * @head: head of the stack
 * @number: line number
 * Return: nothing
 */
void _rotl(stack_t **head, unsigned int number)
{
	stack_t *tmp, *t;
	(void)number;

	if (!(*head) || !((*head)->next))
		return;
	t = *head;
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	(*head) = t->next;
	t->next->prev = NULL;
	tmp->next = t;
	t->prev = tmp;
	t->next = NULL;
}
