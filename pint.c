#include "monty.h"
/**
 * _pint -  prints the value at the top of the stack
 * @head: head of the stack
 * @number: line_number
 * Return: nothing
 */
void _pint(stack_t **head, unsigned int number)
{
	if (!(*head))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
