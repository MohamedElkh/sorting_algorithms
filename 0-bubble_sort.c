#include "sort.h"

/**
 * bubble_sort - function to sort array of elemensts
 * @array: the array to be checked
 * @size: the size of the array
 *
 * Return: nothing
 */

void bubble_sort(int *array, size_t size)
{
	size_t tp = 0;
	size_t x, idx;

	if (size < 2)
	{
		return;
	}

	for (x = 0; x < size; x++)
	{
		for (idx = 0; idx < size; idx++)
		{
			if (array[idx] > array[idx + 1] && array[idx + 1])
			{
				tp = array[idx];
				array[idx] = array[idx + 1];

				array[idx + 1] = tp;
				print_array(array, size);
			}
		}
	}
}
