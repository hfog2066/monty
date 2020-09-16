#include "monty.h"

/**
 *_strcmp - compares two strings.
 *@s1: type str compare.
 *@s2: type str compare.
 *Return: no return.
 */

int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;
	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}

/**
 *_sch - search char inside string
 *@s: string to review.
 *@c: char to find.
 *Return: no return.
 */

int _sch(char *s, char c)
{
	int cont = 0;

	while (s[cont] != '\0')
	{
		if (s[cont] == c)
		{
			break;
		}
		cont++;
	}
	if (s[cont] == c)
		return (1);
	else
		return (0);
}

/**
 *_strtoky - cut string into tokens depending of delimit
 *@s: string to cut.
 *@d: delimiters.
 *Return: first partition.
 */

char *_strtoky(char *s, char *d)
{
	static char *last;
	int i = 0, j = 0;

	if (!s)
		s = last;
	while (s[i] != '\0')
	{
		if (_sch(d, s[i]) == 0 && s[i + 1] == '\0')
		{
			last = s + i + 1;
			*last = '\0';
			s = s + j;
			return (s);
		}
		else if (_sch(d, s[i]) == 0 && _sch(d, s[i + 1]) == 0)
			i++;
		else if (_sch(d, s[i]) == 0 && _sch(d, s[i + 1]) == 1)
		{
			last = s + i + 1;
			*last = '\0';
			last++;
			s = s + j;
			return (s);
		}
		else if (_sch(d, s[i]) == 1)
		{
			j++;
			i++;
		}
	}
	return (NULL);
}
