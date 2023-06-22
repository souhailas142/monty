#include "monty.h"
/**
 * _pstr - prints the string starting at the top of the stack
 * @head: head of the stack
 * @number: line number
 * Return: nothing
 */
void _pstr(stack_t **head, unsigned int number)
{
	stack_t *tmp;
	(void)number;

	tmp = *head;
	while (tmp)
	{
		if (tmp->n <= 0 || tmp->n > 127)
		{
			break;
		}
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");

}

