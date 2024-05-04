/**
 * swap - Swap two integers in an array
 * @a: The first integer to swap
 * @b: The second integer to swap
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bitonic_merge - Merge two bitonic sequences in bitonic order
 * @array: The array containing the bitonic sequences
 * @size: The size of the array
 * @start: The starting index of the first bitonic sequence
 * @seq: The size of each bitonic sequence
 * @dir: The direction to sort the bitonic sequences
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq, char dir)
{
	size_t i, dist;
	char newdir = (dir == UP) ? DOWN : UP;

	dist = seq * 2;

	for (i = start; i < start + seq; i++)
	{
		if (dir == (array[i] >= array[i + seq]))
			swap(&array[i], &array[i + seq]);
	}

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):", seq, size, (dir == UP) ? "UP" : "DOWN");
		print_array(array + start, dist);

		bitonic_merge(array, size, start, seq / 2, dir);
		bitonic_merge(array, size, start + seq, seq / 2, dir);

		bitonic_merge(array, size, start, seq, newdir);
	}
	else
	{
		printf("Result [%lu/%lu] (%s):", seq, size, (dir == UP) ? "UP" : "DOWN");
		print_array(array + start, dist);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending order
 *                using the Bitonic sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	bitonic_merge(array, size, 0, size, UP);
}
