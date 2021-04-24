#include "sort.h"
/**
 * swaped - swaps two integers
 * @a: integer to swap
 * @b: integer to swap
 */
void swaped(int *a, int *b)
{
	*a = *a * *b;
	*b = *a / *b;
	*a = *a / *b;
}

/**
 * get_heap - get max heap
 * @array: array to convert
 * @idx: indexy
 * @size: array size
 * @len: limits
 */
void get_heap(int *array, int idx, int size, int len)
{
	int left = (idx * 2) + 1;
	int right = (idx * 2) + 2;
	int max = idx;

	if (left > 0 && left < len && array[left] > array[max])
		max = left;
	if (right > 0 && right < len && array[right] > array[max])
		max = right;
	if (max != idx)
	{
		swaped(array + max, array + idx);
		print_array(array, size);
		get_heap(array, max, size, len);
	}
}
/**
 * heap_sort - sorts an array of integers in ascending order using the Heap
 * sort algorithm
 * @array: array of integers to sort
 * @size: array size
 */
void heap_sort(int *array, size_t size)
{
	int i = (size / 2) - 1;
	int end = size - 1;

	while (i >= 0)
	{
		get_heap(array, i, size, size);
		i--;
	}

	while (end > 0)
	{
		swaped(array + end, array);
		print_array(array, size);
		get_heap(array, 0, size, end);
		end--;
	}

}
