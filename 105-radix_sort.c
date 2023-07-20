#include "sort.h"

/**
 * count_s - function to sort the digits of the array
 * @arr: the array to be checked
 * @size: the size of the array
 * @ig: the char to be checked
 * @bf: the buffer to store
 *
 * Return: nothing.
 */

void count_s(int *arr, size_t size, int ig, int *bf)
{
	size_t x;
	int num[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for (x = 0; x < size; x++)
	{
		num[(arr[x] / ig) % 10] += 1;
	}
	for (x = 0; x < 10; x++)
	{
		num[x] += num[x - 1];
	}
	for (x = size - 1; (int)x >= 0; x--)
	{
		bf[num[(arr[x] / ig) % 10] - 1] = arr[x];

		num[(arr[x] / ig) % 10] -= 1;
	}

	for (x = 0; x < size; x++)
	{
		arr[x] = bf[x];
	}
}

/**
 * g_max - function to get the max value
 * @arr: the array of int
 * @size: the size of the array
 *
 * Return: the result.
 */

int g_max(int *arr, int size)
{
	int x, mx;

	for (mx = arr[0], x = 1; x < size; x++)
	{
		if (arr[x] > mx)
		{
			mx = arr[x];
		}
	}
	return (mx);
}

/**
 * radix_sort - function to sort the array of int
 * @array: the array to be checked
 * @size: the size of the array
 *
 * Return: nothing.
 */

void radix_sort(int *array, size_t size)
{
	int ig, mx;
	int *bf;

	if (array == NULL || size < 2)
	{
		return;
	}

	bf = malloc(sizeof(int) * size);

	if (bf == NULL)
	{
		return;
	}

	mx = g_max(array, size);

	for (ig = 1; mx / ig > 0; ig *= 10)
	{
		count_s(array, size, ig, bf);
		print_array(array, size);
	}
	free(bf);
}
