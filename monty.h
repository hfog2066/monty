#ifndef _MONTY_
#define _MONTY_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list stack
 * @n: integer
 * @prev: points previous element stack
 * @next: points next element stack
 *
 * Description: doubly linked list node
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct globals - global structure functions
 * @lifo: is stack or queue
 * @cont: current line
 * @arg: second parameter inside line
 * @head: doubly linked list
 * @fd: file descriptor
 * @buffer: input text
 *
 * Description: doubly linked list node structure
 */

typedef struct globals
{
	int lifo;
	unsigned int cont;
	char  *arg;
	stack_t *head;
	FILE *fd;
	char *buffer;
} global_t;

/**
 * struct instruction_s - opcode function
 * @opcode: the opcode
 * @f: function handle opcode
 *
 * Description: opcode function
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern global_t vglo;

/* opcode_instructuions*/
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **doubly, unsigned int nline);
void _pop(stack_t **doubly, unsigned int nline);
void _swap(stack_t **doubly, unsigned int nline);
void _queue(stack_t **doubly, unsigned int nline);
void _stack(stack_t **doubly, unsigned int nline);
void _add(stack_t **doubly, unsigned int nline);
void _nop(stack_t **doubly, unsigned int nline);
void _sub(stack_t **doubly, unsigned int nline);
void _div(stack_t **doubly, unsigned int nline);
void _mul(stack_t **doubly, unsigned int nline);
void _mod(stack_t **doubly, unsigned int nline);
void _pchar(stack_t **doubly, unsigned int nline);
void _pstr(stack_t **doubly, unsigned int nline);
void _rotl(stack_t **doubly, unsigned int nline);
void _rotr(stack_t **doubly, unsigned int nline);

/*get function*/
void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number);

/*imported functions*/
int _sch(char *s, char c);
char *_strtoky(char *s, char *d);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *_calloc(unsigned int nmemb, unsigned int size);
int _strcmp(char *s1, char *s2);

/* doubly linked list functions */
stack_t *add_dnodeint_end(stack_t **head, const int n);
stack_t *add_dnodeint(stack_t **head, const int n);
void free_dlistint(stack_t *head);

/* main */
void free_vglo(void);

#endif
