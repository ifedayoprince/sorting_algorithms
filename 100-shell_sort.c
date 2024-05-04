#include "sort.h"

/**
 * shell_sort - Shell sort - Knuth Sequence
 * @arr: array to sort
 * @n: size of array
 */
void shell_sort(int *arr, size_t n)
{
	int gap, i, j, temp;

	for (gap = n / 2; gap > 0; gap /= 2)
	{
		for (i = gap; i < n; i++)
		{
			temp = arr[i], j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
				arr[j] = arr[j - gap];
			arr[j] = temp;
		}
		print_array(arr, n);
	}
}
