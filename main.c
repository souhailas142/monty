#include "monty.h"
bus_t bus;
#define _POSIX_C_SOURCE 200809L
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
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
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int number = 0;
	bus.arg = NULL;
	bus.file = NULL;
	bus.content = NULL;
	bus.lifi = 0;
	(void)bus;

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
