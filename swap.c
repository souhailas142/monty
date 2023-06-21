#include "monty.h"
/**
 * _swap - swaps the top two elements of the stack
 * @head: head of the stack
 * @number: line number
 * Return: nothing
 */
void _swap(stack_t **head, unsigned int number)
{
	unsigned int len = 0, nbr;
	stack_t *tmp, *t;

	tmp = *head;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	t = *head;
	nbr = t->n;
	t->n = t->next->n;
	t->next->n = nbr;
}
