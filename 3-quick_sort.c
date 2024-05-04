#include "sort.h"


/**
 * part - array partition
 * @arr: array to sort
 * @start: first position
 * @end: last position
 * @len: array size
 * Return: int pivot index
 */
int part(int *arr, int start, int end, size_t len)
{
	int i = start - 1, tmp, j;

	for (j = start; j <= end - 1; j++)
	{
		if (arr[j] < arr[end])
		{
			i++;
			if (i < j)
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
				print_array(arr, len);
			}
		}
	}
	if (arr[i + 1] > arr[end])
	{
		tmp = arr[i + 1];
		arr[i + 1] = arr[end];
		arr[end] = tmp;
		print_array(arr, len);
	}

	return (i + 1);
}

/**
 * quick_sort - sorts an array of integers recursively
 * @array: array to sort
 * @first: first position
 * @last: last position
 * @size: array size
 */
void quick_sort(int *array, int first, int last, size_t size)
{
	int pivot;

	if (first < last)
	{
		pivot = part(array, first, last, size);
		quick_sort(array, first, pivot - 1, size);
		quick_sort(array, pivot + 1, last, size);
	}
}
