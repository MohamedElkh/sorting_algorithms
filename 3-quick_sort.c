#include "sort.h"

/**
 * quick_sort - function to sort the array
 * @array: the function to be checked
 * @size: the size of the array
 *
 * Return: nothing
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
	{
		return;
	}
	sort_rec(array, 0, size - 1, size);
}

/**
 * sort_rec - function to sort the array
 * @array: the array to be checked
 * @low: lower
 * @high: higher
 * @size: the size of the array
 *
 * Return: nothng
 */


