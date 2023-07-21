#include "sort.h"

/**
 * func_swap - function to swap two ints
 * @fir: the first int
 * @sec: the second int
 *
 * Return: nothing
 */

void func_swap(int *fir, int *sec)
{
	int tp;

	tp = *fir;
	*fir = *sec;
	*sec = tp;
}

/**
 * h_part - function to order the subset arr
 * @arr: the array to be check
 * @size: the size of the array
 * @first: the first index
 * @last: the last index
 *
 * Return: the result.
 */

int h_part(int *arr, size_t size, int first, int last)
{
	int pi, ab;
	int bel;

	pi = arr[last];

	for (ab = first - 1, bel = last + 1; ab < bel;)
	{
		do {
			ab++;
		} while (arr[ab] < pi);

		do {
			bel--;
		} while (arr[bel] > pi);

		if (ab < bel)
		{
			func_swap(arr + ab, arr + bel);
			print_array(arr, size);
		}
	}
	return (ab);
}

/**
 * h_sort - function to sort the array
 * @arr: the array to be checked
 * @size: the size of the array
 * @first: the first index
 * @last: the last index
 *
 * Return: nothing.
 */

void h_sort(int *arr, size_t size, int first, int last)
{
	int cell;

	if (last - first > 0)
	{
		cell = h_part(arr, size, first, last);

		h_sort(arr, size, first, cell - 1);
		h_sort(arr, size, cell, last);
	}
}

/**
 * quick_sort_hoare - function to sort the array of ints
 * @array: the array to be check
 * @size: the size of the array
 *
 * Return: nothng.
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}

	h_sort(array, size, 0, size - 1);
}
