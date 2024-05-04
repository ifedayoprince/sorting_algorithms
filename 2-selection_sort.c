#include "sort.h"


/**
 * selection_sort - sort list with selection_sort
 * @arr: The array to be printed
 * @n: Number of elements in @array
 */
void selection_sort(int *arr, size_t n)
{
	size_t i, j, min;
	int temp;

	if (!arr)
		return;

	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min])
				min = j;

		if (min != i)
		{
			temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
			print_array(arr, n);
		}
	}
}
