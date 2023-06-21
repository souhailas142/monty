#include "monty.h"
/**
 * _push - pushes an element to the stack.
 * @head: head
 * @number: line_number
 * Return: nothing
 */
void _push(stack_t **head, unsigned int number)
{
	int nbr, i = 0, c = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			i++;
		while (bus.arg[i])
		{
			if (bus.arg[i] < 48 || bus.arg[i] > 57)
			{
				c = 1;
				break;
			}
			i++;
		}
		if (c)
		{
			fprintf(stderr, "L%d: usage: push integer\n", number);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	nbr = atoi(bus.arg);
	if (bus.lifi == 0)
		addStack(head, nbr);
	else
		addQueue(head, nbr);
}
