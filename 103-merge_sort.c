#include "sort.h"

/**
 * merge_s - function to sort the subarray of int
 * @arr: the subarray
 * @bf: the buffer
 * @ft: the front of the array
 * @md: the middle of array
 * @bk: the back of the array
 *
 * Return: nothing.
 */

void merge_s(int *arr, int *bf, size_t ft, size_t md, size_t bk)
{
	size_t x, a;
	size_t num = 0;

	printf("Merging...\n[left]: ");
	print_array(arr + ft, md - ft);
	printf("[right]: ");
	print_array(arr + md, bk - md);

	for (x = ft, a = md; x < md && a < bk; num++)
	{
		bf[num] = (arr[x] < arr[a]) ? arr[x++] : arr[a++];
	}
	for (; x < md; x++)
	{
		bf[num++] = arr[x];
	}
	for (; a < bk; a++)
	{
		bf[num++] = arr[a];
	}
	for (x = ft, num = 0; x < bk; x++)
	{
		arr[x] = bf[num++];
	}

	printf("[Done]: ");
	print_array(arr + ft, bk - ft);
}

/**
 * merge_sor - function to implement the merge
 * @arr: the subarray
 * @bf: the buffer to store
 * @ft: the front index of arr
 * @bk: the last index of arr
 *
 * Return: noting.
 */

void merge_sor(int *arr, int *bf, size_t ft, size_t bk)
{
	size_t md;

	if (bk - ft > 1)
	{
		md = ft + (bk - ft) / 2;
		merge_sor(arr, bf, ft, md);
		merge_sor(arr, bf, md, bk);

		merge_s(arr, bf, ft, md, bk);
	}
}

/**
 * merge_sort - function to sort the array of int
 * @array: the array to be checked
 * @size: the size of the array
 *
 * Return: nothing.
 */

void merge_sort(int *array, size_t size)
{
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

	merge_sor(array, bf, 0, size);
	free(bf);
}
