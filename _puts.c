#include "main.h"

/**
 * _puts - prints characters of a string
 * @s: string to print
 *
 * Return: count of string
 */
int _puts(char *s)
{
	int counter = 0;

	while (*s++)
	{
		_putchar(*(s - 1));
		counter++;
	}
	return (counter);
}

