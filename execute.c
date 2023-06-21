#include "monty.h"
/**
 * execute - executes the opcode
 * @content: line content
 * @head: head of the stack
 * @number: line_number
 * @file: pointer to monty file
 * Return: nothing
 */
int execute(char *content, stack_t **head, unsigned int number, FILE *file)
{
	instruction_t options[] = {
		{"push", _push},
		{"pall", _pall},
		{"stack", _stack},
		{"queue", _queue},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (options[i].opcode && op)
	{
		if (strcmp(op, options[i].opcode) == 0)
		{
			options[i].f(head, number);
			return (0);
		}
		i++;
	}
	if (op && options[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", number, op);
		fclose(file);
		free(content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	return (1);
}
