#include "monty.h"
/**
 * _add - adds the top two elements of the stack.
 * @head: head of the stack
 * @number: line number
 */
void _add(stack_t **head, unsigned int number)
{
	unsigned int len = 0, nbr;
	stack_t *add_node, *tmp, *t, *t1;

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
	add_node = malloc(sizeof(stack_t));
	add_node->n = nbr;
	add_node->prev = NULL;
	if (t->next->next != NULL)
	{
		t1 = t->next->next;
		_pop(head, number);
		_pop(head, number);
		t1->prev = add_node;
		add_node->next = t1;
		(*head) = add_node;
	}
	else
	{
		_pop(head, number);
		_pop(head, number);
		add_node->next = NULL;
		(*head) = add_node;
	}
}
