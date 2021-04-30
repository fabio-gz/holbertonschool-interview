#include "search_algos.h"
/**
 * searchb - Recursively searches for a value
 * @array: first element
 * @value: value
 * @l: left limit
 * @r: right limit
 * Return: value index
 */
int searchb(int *array, int l, int r, int value)
{
	int i, mid;

	mid = l + (r - l) / 2;
	if (l == r)
	{
		if (value < array[l] || value > array[r])
		{
			printf("Searching in array: %d\n", array[mid]);
			return (-1);
		}
		return (l);
	}
	printf("Searching in array:");
	for (i = l; i <= r; i++)
	{
		if (i != r)
			printf(" %d,", array[i]);
		else
			printf(" %d\n", array[i]);
	}

	if (array[mid] < value)
		return (searchb(array, mid + 1, r, value));
	else
		return (searchb(array, l, mid, value));
}

/**
 * advanced_binary - binary search
 * @array: first element
 * @size: number of elements
 * @value: value
 * Return: value index
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array)
		return (-1);
	return (searchb(array, 0, size - 1, value));
}
