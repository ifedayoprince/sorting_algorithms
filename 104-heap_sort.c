#include <stdint.h>
#include "sort.h"
#define getParent(i) (((i) - 1) / 2)
#define getLeft(i) (2 * (i) + 1)
#define getRight(i) (2 * (i) + 2)


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
 * heapify - Heapifies a subtree rooted at given index
 * @array: Array to heapify
 * @size: Size of the array
 * @index: Index of the root node
 * @nth: Index of the last node in the heap
 */
void heapify(int *array, size_t size, size_t index, size_t nth)
{
    size_t largest = index, left = getLeft(index), right = getRight(index);

    if (left <= nth && array[left] > array[largest])
        largest = left;
    if (right <= nth && array[right] > array[largest])
        largest = right;

    if (largest != index)
    {
        swap(&array[index], &array[largest]);
        print_array(array, size);
        heapify(array, size, largest, nth);
    }
}

/**
 * heap_sort - Sorts an array using the Heap Sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
    size_t i;

    if (array == NULL || size < 2)
        return;

    for (i = size / 2 - 1; i < size; i--)
        heapify(array, size, i, size - 1);

    for (i = size - 1; i > 0; i--)
    {
        swap(&array[0], &array[i]);
        print_array(array, size);
        heapify(array, size, 0, i - 1);
    }
}
