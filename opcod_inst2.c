#include "monty.h"

/**
 *_queue - sets format dtat to a queue(FIFO)
 *
 *@doubly: linked list head.
 *@nline: line number;
 *Return: 0.
 */

void _queue(stack_t **doubly, unsigned int nline)
{
	(void)doubly;
	(void)nline;

	varglo.lifo = 0;
}

/**
 *_stack - sets format data to a stack (LIFO)
 *
 *@doubly: linked list head.
 *@nline: line number;
 *Return: 0.
 */

void _stack(stack_t **doubly, unsigned int nline)
{
	(void)doubly;
	(void)nline;

	varglo.lifo = 1;
}

/**
 *_add - adds top two elements of the stack.
 *
 *@doubly: linked list head.
 *@nline: line number.
 *Return: 0.
 */

void _add(stack_t **doubly, unsigned int nline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", nline);
		free_varglo();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n += (*doubly)->n;
	_pop(doubly, nline);
}

/**
 *_nop - doesn't do anything.
 *
 *@doubly: linked list head.
 *@nline: line number.
 *Return: 0.
 */

void _nop(stack_t **doubly, unsigned int nline)
{
	(void)doubly;
	(void)nline;
}

/**
 *_sub - substract top element to second element stack.
 *@doubly: linked list head.
 *@nline: line number;
 *Return: 0.
 */

void _sub(stack_t **doubly, unsigned int nline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", nline);
		free_varglo();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n -= (*doubly)->n;
	_pop(doubly, nline);
}
