#include "sort.h"


/**
 * partition - array partition
 * @array: array to sort
 * @first: first position
 * @last: last position
 * @size: array size
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


/**
 * partition - array partition
 * @array: array to sort
 * @first: first position
 * @last: last position
 * @size: array size
 * Return: int pivot index
 */
int partition(int *array, int first, int last, size_t size)
{
	int i = first - 1, aux, j;

	for (j = first; j <= last - 1; j++)
	{
		if (array[j] < array[last])
		{
			i++;
			if (i < j)
			{
				aux = array[i];
				array[i] = array[j];
				array[j] = aux;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] > array[last])
	{
		aux = array[i + 1];
		array[i + 1] = array[last];
		array[last] = aux;
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * qs - sorts an array of integers recursively
 * @array: array to sort
 * @first: first position
 * @last: last position
 * @size: array size
 */
void qs(int *array, int first, int last, size_t size)
{
	int pivot;

	if (first < last)
	{
		pivot = partition(array, first, last, size);
		qs(array, first, pivot - 1, size);
		qs(array, pivot + 1, last, size);
	}
}

/**
 * quick_sort - sorts an array of integers using the Quick
 * sort algorithm in ascending order
 * @array: array to sort
 * @size: array size
 */
void quick_sort(int *array, size_t size)
{
	qs(array, 0, size - 1, size);
}
