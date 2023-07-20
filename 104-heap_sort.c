#include "sort.h"

/**
 * func_swap - function to swap two int in arr
 * @fir: the first int to swap
 * @sec: the second int to swap
 *
 * Return: nothing.
 */

void func_swap(int *fir, int *sec)
{
	int tp;

	tp = *fir;
	*fir = *sec;

	*sec = tp;
}

/**
 * heap_max - func to trun the binary tree
 * @arr: the array of int
 * @size: the size of the array
 * @bs: the index of base
 * @ro: the root node
 *
 * Return: nothing.
 */

void heap_max(int *arr, size_t size, size_t bs, size_t ro)
{
	size_t lf, rt;
	size_t max;

	lf = 2 * ro + 1;
	rt = 2 * ro + 2;

	max = ro;

	if (lf < bs && arr[lf] > arr[max])
	{
		max = lf;
	}
	if (rt < bs && arr[rt] > arr[max])
	{
		max = rt;
	}

	if (max != ro)
	{
		func_swap(arr + ro, arr + max);

		print_array(arr, size);
		heap_max(arr, size, bs, max);
	}
}

/**
 * heap_sort - function to sort the array of int
 * @array: the array of int
 * @size: the size of the array
 *
 * Return: nothing.
 */

void heap_sort(int *array, size_t size)
{
	int x;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (x = (size / 2) - 1; x >= 0; x--)
	{
		heap_max(array, size, size, x);
	}

	for (x = size - 1; x > 0; x--)
	{
		func_swap(array, array + x);

		print_array(array, size);
		heap_max(array, size, x, 0);
	}
}
