#include "monty.h"
/**
 * _mod - computes the rest of the division of the second and top
 * @head: head of the stack
 * @number: line number
 * Return: nothing
 */
void _mod(stack_t **head, unsigned int number)
{
	int len = 0;
	int nbr;
	stack_t *tmp, *t;

	tmp = *head;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	t = *head;
	if (t->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	nbr = t->next->n % t->n;
	t->next->n = nbr;
	(*head) = t->next;
	t->next->prev = NULL;
	free(t);
}
