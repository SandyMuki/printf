#include "main.h"
#include <unistd.h>

/**
 * _putchar - print a character
 *@c: charcter to print
 *
 * Return: count
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

