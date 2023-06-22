#include "monty.h"
/**
 * _pchar - prints the char at the top of the stack
 * @head: head of the stack
 * @number: line number
 * Return: nothing
 */
void _pchar(stack_t **head, unsigned int number)
{
	if (!(*head))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n < 0 || (*head)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head)->n);
}
