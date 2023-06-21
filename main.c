#include "monty.h"
/**
 * main - monty code interpreter
 * @argc: number of arguments
 * @argv: monty dile location
 * Return: SUCCESS
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *content;
	int size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int number = 0;
	bus_t bus = {NULL, NULL, NULL, 0};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &size, file);
		bus.content = content;
		number++;
		if (read_line > 0)
			execute(content, &stack, number, file);
		free(content);
	}
	free_stack(stack);
	fclose(file);
	return (0);
}
