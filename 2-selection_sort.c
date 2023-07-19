#include "sort.h"

/**
 * selection_sort - function to sort the selection
 * @array: the array to be checked
 * @size: the size of the array
 *
 * Return: nothing.
 */

void selection_sort(int *array, size_t size)
{
	size_t x = 0, a = 1;
	size_t ax = 0, mini = 0;
	size_t lim = size - 1;

	if (size < 2)
	{
		return;
	}

	while (x < lim)
	{
		if (a == size)
		{
			if (x != mini)
			{
				ax = array[x];
				array[x] = array[mini];
				array[mini] = ax;

				print_array(array, size);
			}

			++x;
			mini = x;
			a = x + 1;
			continue;
		}

		if (array[mini] > array[a])
		{
			mini = a;
		}
		++a;
	}
}
