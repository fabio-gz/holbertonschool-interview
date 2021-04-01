#include "search.h"

/**
 * print_value - print the values
 * @prevskip:  previous node
 * @expskip: endless node
 * @value: value
 *
 * Return: pointer with node value
 */
skiplist_t *print_value(skiplist_t *prevskip, skiplist_t *expskip, int value)
{

	printf("Value found between indexes [%li] and [%li]\n",
	       prevskip->index, expskip->index);
	while (prevskip != expskip->next)
	{
		printf("Value checked at index [%li] = [%d]\n",
		       prevskip->index, prevskip->n);
		if (prevskip->n == value)
			return (prevskip);
		prevskip = prevskip->next;
	}
	return (NULL);
}

/**
 * linear_skip - linear search
 * @list: head of the skip list to search
 * @value: value
 * Return: Always EXIT_SUCCESS
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *prevskip, *nextskip;

	if (!list)
		return (NULL);
	nextskip = list;
	while (nextskip)
	{
		prevskip = nextskip;
		if (nextskip->express)
			nextskip = nextskip->express;
		else

		{
			while (nextskip->next)
				nextskip = nextskip->next;
			break;
		}
		printf("Value checked at index [%lu] = [%i]\n",
		       nextskip->index, nextskip->n);
		if (nextskip->n >= value)
			return (print_value(prevskip, nextskip, value));
	}
	return (print_value(prevskip, nextskip, value));
}
