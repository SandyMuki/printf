#include "main.h"

/**
 * print_int - print integer to stdout and count
 * @n: integer to print
 *
 * Return: integer count
 */

int print_int(int n)
{
	int counter = 0;
	int rev = 0;

	if (n < 0)
	{
		_putchar('-');
		n = -n;
		counter += 1;
	}

	while (n > 0)
	{
		rev = rev * 10 + n % 10;
		n /= 10;
	}

	while (rev > 0)
	{
		_putchar(rev % 10 + '0');
		rev /= 10;
		counter += 1;
	}
	return (counter);
}

