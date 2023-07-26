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

void sort_rec(int *array, int low, int high, size_t size)
{
	int idx = 0;

	if (low < high)
	{
		idx = lomuto_partition(array, low, high, size);

		sort_rec(array, low, idx - 1, size);
		sort_rec(array, idx + 1, high, size);
	}
}

/**
 * lomuto_partition - function to define the partition
 * @array: array to be checked
 * @low: the char
 * @high: the char
 * @size: the size to be checked
 *
 * Return: the result.
 */

int lomuto_partition(int *array, int low, int high, size_t size)
{
	int x = 0, a = 0;
	int pi = 0, ax = 0;

	pi = array[high];

	x = low;

	for (a = low; a < high; ++a)
	{
		if (array[a] < pi)
		{
			ax = array[x];
			array[x] = array[a];
			array[a] = ax;

			if (ax != array[x])
			{
				print_array(array, size);
			}
			++x;
		}
	}
	ax = array[x];
	array[x] = array[high];
	array[high] = ax;

	if (ax != array[x])
	{
		print_array(array, size);
	}
	return (x);
}

