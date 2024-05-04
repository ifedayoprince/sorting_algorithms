#include "sort.h"
#include <stdlib.h>


/**
 * arr_maximum - finds the maximum value in an array
 * @array: array to search
 * @size: size of the array
 * Return: maximum value
 */
int arr_maximum(int *array, size_t size)
{
	int max_val = array[0];
	size_t i;

	for (i = 1; i < size; i++)
		if (array[i] > max_val)
			max_val = array[i];
	return (max_val);
}

/**
 * counting_sort - sorts an array using the Counting sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count_arr, *sorted_arr, max_val, num;
	size_t i;

	if (size < 2 || !array)
		return;
	max_val = arr_maximum(array, size);

	count_arr = malloc(sizeof(size_t) * (max_val + 1));
	sorted_arr = malloc(sizeof(int) * size);

	for (i = 0; (int)i <= max_val; i++)
		count_arr[i] = 0;
	for (i = 0; i < size; i++)
	{
		num = array[i];
		count_arr[num] += 1;
	}
	for (i = 1; (int)i <= max_val; i++)
		count_arr[i] += count_arr[i - 1];
	print_array(count_arr, max_val + 1);

	for (i = 0; i < size; i++)
	{
		sorted_arr[count_arr[array[i]] - 1] = array[i];
		count_arr[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = sorted_arr[i];
	free(count_arr);
	free(sorted_arr);
}
