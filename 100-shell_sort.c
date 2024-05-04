#include "sort.h"

/**
 * shell_sort - Shell sort - Knuth Sequence
 * @array: array to sort
 * @size: size of array
 */
void shell_sort(int *arr, size_t n) {
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i], j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
        print_array(arr, n);
    }
}
