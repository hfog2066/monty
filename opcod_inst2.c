#include "monty.h"

/**
 *_queue - sets format dtat to a queue(FIFO)
 *
 *@doubly: linked list head.
 *@cline: line number;
 *Return: no return.
 */

void _queue(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;

	vglo.lifo = 0;
}

/**
 *_stack - sets format data to a stack (LIFO)
 *
 *@doubly: linked list head.
 *@cline: line number.
 *Return: no return.
 */

void _stack(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;

	vglo.lifo = 1;
}

/**
 *_add - adds top two elements of the stack.
 *
 *@doubly: linked list head.
 *@cline: line number.
 *Return: no return.
 */

void _add(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n += (*doubly)->n;
	_pop(doubly, cline);
}

/**
 *_nop - doesn't do anything.
 *
 *@doubly: linked list head.
 *@cline: line number.
 *Return: no return.
 */

void _nop(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;
}

/**
 *_sub - substract top element to second element stack.
 *@doubly: linked list head.
 *@cline: line number;
 *Return: no return.
 */

void _sub(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n -= (*doubly)->n;
	_pop(doubly, cline);
}
