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
 * bit_m - function to sort the bitonic seq
 * @arr: the array to be checked
 * @size: the size of the array
 * @st: the first index
 * @sq: the size seq
 * @fw: the direction
 *
 * Return: nothing.
 */

void bit_m(int *arr, size_t size, size_t st, size_t sq, char fw)
{
	size_t mv = sq / 2;
	size_t x;

	if (sq > 1)
	{
		for (x = st; x < st + mv; x++)
		{
			if ((fw == UPP && arr[x] > arr[x + mv]) ||
					(fw == DOWN && arr[x] < arr[x + mv]))

				func_swap(arr + x, arr + x + mv);
		}

		bit_m(arr, size, st, mv, fw);
		bit_m(arr, size, st + mv, mv, fw);
	}
}

/**
 * bit_seq - function to convert array into bitonic seq
 * @arr: the array
 * @size: the size of the array
 * @st: the first index
 * @sq: the sequence
 * @fw: the direction to sort
 *
 * Return: nothing.
 */

void bit_seq(int *arr, size_t size, size_t st, size_t sq, char fw)
{
	size_t div = sq / 2;
	char *string = (fw == UPP) ? "UP" : "DOWN";

	if (sq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", sq, size, string);
		print_array(arr + st, sq);

		bit_seq(arr, size, st, div, UPP);
		bit_seq(arr, size, st + div, div, DOWN);
		bit_m(arr, size, st, sq, fw);

		printf("Result [%lu/%lu] (%s):\n", sq, size, string);
		print_array(arr + st, sq);
	}
}

/**
 * bitonic_sort - function to sort the array
 * @array: the array to be checked
 * @size: the size of the array
 *
 * Return: nothing.
 */

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}

	bit_seq(array, size, 0, size, UPP);
}
