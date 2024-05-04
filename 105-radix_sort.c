#include <stdlib.h>


/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer value in the array.
 */
int get_max(int *array, int size)
{
    int max, i;

    for (max = array[0], i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    return (max);
}

/**
 * radix_sort - Sort an array of integers in ascending
 *              order using the LSD radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
    int max, digit, *output, i, j;

    max = get_max(array, size);
    for (digit = 1; max / digit > 0; digit *= 10)
    {
        output = malloc(sizeof(int) * size);
        for (i = 0; i < (int)size; i++)
            output[i] = 0;
        for (i = 0; i < (int)size; i++)
        {
            j = (array[i] / digit) % 10;
            output[j] = output[j] * 10 + (array[i] % (digit * 10)) / digit;
        }
        for (i = 0, j = 0; i < 10; i++)
        {
            while (output[i])
            {
                array[j++] = output[i] % 10;
                output[i] /= 10;
            }
        }
        print_array(array, size);
        free(output);
    }
}
