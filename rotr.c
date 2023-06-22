#include "monty.h"
/**
 * _rotr - rotates the stack to the bottom
 * @head: head of the stack
 * @number: line number
 * Return: nothing
 */
void _rotr(stack_t **head, unsigned int number)
{
	stack_t *tmp;
	(void)number;

	if (!(*head) || !((*head)->next))
		return;
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *head;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*head)->prev = tmp;
	(*head) = tmp;
}
