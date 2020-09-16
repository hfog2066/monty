#include "monty.h"

/**
 *_div - divide second element by top element of the stack.
 *
 *@doubly: linked list head.
 *@nline: line number;
 *Return: 0.
 */

void _div(stack_t **doubly, unsigned int nline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", nline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	if ((*doubly)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", nline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n /= (*doubly)->n;
	_pop(doubly, nline);
}

/**
 *_mul - multiplies top element by second element of the stack.
 *
 *@doubly: linked list head.
 *@nline: line number.
 *Return: 0.
 */

void _mul(stack_t **doubly, unsigned int nline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", nline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n *= (*doubly)->n;
	_pop(doubly, nline);
}

/**
 *_mod - rest of division of the second element.
 *
 *@doubly: linked list head.
 *@nline: line number.
 *Return: 0.
 */

void _mod(stack_t **doubly, unsigned int nline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", nline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	if ((*doubly)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", nline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n %= (*doubly)->n;
	_pop(doubly, nline);
}

/**
 *_pchar - print char value first element.
 *
 *@doubly: linked list head.
 *@nline: line number.
 *Return: 0.
 */

void _pchar(stack_t **doubly, unsigned int nline)
{
	if (doubly == NULL || *doubly == NULL)
	{
		dprintf(2, "L%u: cant't pchar, stack empty\n", nline);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	if ((*doubly)->n < 0 || (*doubly)->n >= 128)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", nline);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*doubly)->n);
}

/**
 *_pstr - print string of the stack.
 *
 *@doubly: linked list head.
 *@nline: line number.
 *Return: 0.
 */

void _pstr(stack_t **doubly, unsigned int nline)
{
	stack_t *aux;
	(void)nline;

	aux = *doubly;

	while (aux && aux->n > 0 && aux->n < 128)
	{
		printf("%c", aux->n);
		aux = aux->next;
	}

	printf("\n");
}
