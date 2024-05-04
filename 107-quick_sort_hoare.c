#include "sort.h"


/**
 * swap - Swaps two integers in an array
 * @a: First integer to swap
 * @b: Second integer to swap
 */
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * partition_hoare - Partitions array using Hoare scheme
 * @array: Array to partition
 * @low: Lower index of partition
 * @high: Higher index of partition
 * @size: Size of array
 *
 * Return: Partition index
 */
int partition_hoare(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1, j = high + 1;

    while (1)
    {
        do {
            i++;
        } while (array[i] < pivot);

        do {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return (j);

        swap(&array[i], &array[j]);
        print_array(array, size);
    }
}

/**
 * quick_sort_hoare - Sorts array using Quick Sort (Hoare scheme)
 * @array: Array to sort
 * @low: Lower index of partition to sort
 * @high: Higher index of partition to sort
 * @size: Size of array
 */
void quick_sort_hoare(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int p = partition_hoare(array, low, high, size);
        quick_sort_hoare(array, low, p, size);
        quick_sort_hoare(array, p + 1, high, size);
    }
}
