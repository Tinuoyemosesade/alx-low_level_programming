#include "main.h"

/**
 * flip_bits - returns the number of bits that need to be flipped to get from
 *             one number to another
 * @n: the first number
 * @m: the second number
 *
 * Return: the number of bits that need to be flipped
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int diff = n ^ m;
	unsigned int count = 0;

	while (diff)
	{
		count += (diff & 1);
		diff >>= 1;
	}

	return (count);
}
