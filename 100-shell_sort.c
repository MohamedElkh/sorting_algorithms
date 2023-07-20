#include "sort.h"

/**
 * shell_sort - function to sort the array with shell method
 * @array: the array to sort
 * @size: the size of the array
 *
 * Return: nothing
 */

void shell_sort(int *array, size_t size)
{
	int into = 0, outo = 0;
	int rg = 1, ax = 0;

	if (!array || size < 2)
	{
		return;
	}

	while (rg < (int) size / 3)
	{
		rg = rg * 3 + 1;
	}

	while (rg > 0)
	{
		outo = rg;

		while (outo < (int) size)
		{
			ax = array[outo];
			into = outo;

			while (into > rg - 1 && array[into - rg] >= ax)
			{
				array[into] = array[into - rg];
				into = into - rg;
			}
			array[into] = ax;
			outo++;
		}
		print_array(array, size);

		rg = (rg - 1) / 3;
	}
}
