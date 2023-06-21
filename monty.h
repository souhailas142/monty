#ifndef Monty_H
#define Monty_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct bus_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack/queue
 * Description: carries values through the program
 */
typedef struct bus_s
{
        char *arg;
        FILE *file;
        char *content;
        int lifi;
}  bus_t;
extern bus_t bus;
bus_t bus;

void _push(stack_t **head, unsigned int number);
void free_stack(stack_t *head);
void _stack(stack_t **head, unsigned int number);
void addStack(stack_t **head, int n);
void _queue(stack_t **head, unsigned int number);
void addQueue(stack_t **head, int n);
void _pall(stack_t **head, unsigned int number);
int execute(char *content, stack_t **head, unsigned int number, FILE *file);
void _pint(stack_t **head, unsigned int number);
void _pop(stack_t **head, unsigned int number);
void _swap(stack_t **head, unsigned int number);

#endif
