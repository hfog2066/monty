#include "monty.h"

/*global_t varglo;*/

/**
 *free_varglo - frees global variables.
 *
 *Return: 0
 */

void free_varglo(void)
{
	free_dlistint(varglo.head);
	free(varglo.buffer);
	fclose(varglo.fd);
}

/**
 *start_varglo - initializes global variables.
 *
 *@fd: file descriptor.
 *Return: 0
 */

void start_varglo(FILE *fd)
{
	varglo.lifo = 1;
	varglo.cont = 1;
	varglo.arg = NULL;
	varglo.head = NULL;
	varglo.fd = fd;
	varglo.buffer = NULL;
}

/**
 *check_input - checks if file exist, and if file
 *can be opened.
 *
 *@argc: argument count.
 *@argv: argument vector.
 *Return: file struct.
 */

FILE *check_input(int argc, char *argv[])
{
	FILE *fd;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (fd);
}

/**
 *main - Entry point.
 *
 *@argc: argument count.
 *@argv: argumen vector.
 *Return: 0
 */

int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *fd;
	size_t size = 256;
	ssize_t nlines = 0;
	char *lines[2] = {NULL, NULL};

	fd = check_input(argc, argv);
	start_varglo(fd);
	nlines = getline(&varglo.buffer, &size, fd);
	while (nlines != -1)
	{
		lines[0] = _strtoky(varglo.buffer, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = get_opcodes(lines[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", varglo.cont);
				dprintf(2, "unknow instruction %s\n", lines[0]);
				free_varglo();
				exit(EXIT_FAILURE);
			}
			varglo.arg = _strtoky(NULL, " \t\n");
			f(&varglo.head, varglo.cont);
		}
		nlines = getline(&varglo.buffer, &size, fd);
		varglo.cont++;
	}

	free_varglo();

	return (0);
}
