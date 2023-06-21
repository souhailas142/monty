#include "monty.h"
/**
 * _pall -  prints all the values on the stack
 * @head: head of the stack
 * @number: line_number
 * Return: nothing
 */
void _pall(stack_t **head, unsigned int number)
{
	stack_t *tmp;
	(void)number;

	tmp = *head;
	if (!tmp)
		return;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
