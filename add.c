#include "monty.h"
/**
 * _add - adds the top two elements of the stack.
 * @head: head of the stack
 * @number: line number
 */
void _add(stack_t **head, unsigned int number)
{
	unsigned int len = 0;
	unsigned int nbr;
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
	nbr = t->n + t->next->n;
	t->next->n = nbr;
	(*head) = t->next;
	t->next->prev = NULL;
	free(t);
}
