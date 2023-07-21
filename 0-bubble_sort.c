#include "sort.h"

/**
 * func_swap - function to swap two ints in array
 * @fir: the first int
 * @sec: the second int
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
 * bubble_sort - function to sort array of elemensts
 * @array: the array to be checked
 * @size: the size of the array
 *
 * Return: nothing
 */

void bubble_sort(int *array, size_t size)
{
	bool check = false;
	size_t x;
	size_t le = size;

	if (array == NULL || size < 2)
	{
		return;
	}

	while (check == false)
	{
		check = true;

		for (x = 0; x < le - 1; x++)
		{
			if (array[x] > array[x + 1])
			{
				func_swap(array + x, array + x + 1);
				print_array(array, size);

				check = false;
			}
		}

		le--;
	}
}
