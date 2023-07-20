#include "sort.h"

/**
 * func_max - function to get the max value
 * @arr: the array of int
 * @size: the size of the array
 *
 * Return: the max result.
 */

int func_max(int *arr, int size)
{
	int x;
	int mx;

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
 * counting_sort - function to sort the array of int
 * @array: the array to be checked
 * @size: the size of the array
 *
 * Return: nothing.
 */

void counting_sort(int *array, size_t size)
{
	int *num, *sort;
	int x, mx;

	if (array == NULL || size < 2)
		return;

	sort = malloc(sizeof(int) * size);

	if (sort == NULL)
		return;

	mx = func_max(array, size);
	num = malloc(sizeof(int) * (mx + 1));
	if (num == NULL)
	{
		free(sort);
		return;
	}
	for (x = 0; x < (mx + 1); x++)
	{
		num[x] = 0;
	}
	for (x = 0; x < (int)size; x++)
	{
		num[array[x]] += 1;
	}
	for (x = 0; x < (mx + 1); x++)
		num[x] += num[x - 1];
	print_array(num, mx + 1);

	for (x = 0; x < (int)size; x++)
	{
		sort[num[array[x]] - 1] = array[x];
		num[array[x]] -= 1;
	}
	for (x = 0; x < (int)size; x++)
		array[x] = sort[x];

	free(sort);
	free(num);
}
