#include "monty.h"
/**
 * _pop - removes the top element of the stack.
 * @head: head of the stack
 * @number: line number
 * Return: nothing
 */
void _pop(stack_t **head, unsigned int number)
{
	stack_t *tmp;

	if (!(*head))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = (*head);
	(*head) = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = NULL;
	free(tmp);
}
