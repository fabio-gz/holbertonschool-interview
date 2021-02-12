#include "palindrome.h"
/**
 * is_palindrome - checks whether or not a given unsigned integer is a pali
 * @n: number
 * Return: 1 if n is a palindrome
 */
int is_palindrome(unsigned long n)
{

	unsigned long rev = 0, rem, tmp = n;

	while (tmp != 0)
	{

		rem = tmp % 10;
		rev = rev * 10 + rem;
		tmp = tmp / 10;
	}

	if (rev == n)
		return (1);
	return (0);
}
