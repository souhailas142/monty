#include "monty.h"
/**
 * _sub - subtracts the top and the second top element of the stack
 * @head: head of the stack
 * @number: number
 * Return: nothing
 */
void _sub(stack_t **head, unsigned int number)
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
		fprintf(stderr, "L%d: can't sub, stack too short\n", number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	t = *head;
	nbr = t->n - t->next->n;
	nbr = nbr < 0 ? nbr * -1 : nbr;
	t->next->n = nbr;
	(*head) = t->next;
	t->next->prev = NULL;
	free(t);
}
