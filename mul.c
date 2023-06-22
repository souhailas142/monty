#include "monty.h"
/**
 * _mul - multiplies the second with the top element of the stack
 * @head: head of the stack
 * @number: line number
 * Return: nothing
 */
void _mul(stack_t **head, unsigned int number)
{
	int len = 0, nbr;
	stack_t *tmp, *t;

	tmp = *head;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	t = *head;
	nbr = t->next->n * t->n;
	t->next->n = nbr;
	(*head) = t->next;
	t->next->prev = NULL;
	free(t);
}
