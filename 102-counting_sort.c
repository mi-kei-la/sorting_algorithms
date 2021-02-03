#include "sort.h"

/**
 * counting_sort - Sort array with counting method.
 *
 * @array: Array to sort.
 * @size: Size of the array.
 */

void counting_sort(int *array, size_t size)
{
	int *new = NULL, *count = NULL;
	int max = array[0], i, int_size;

	int_size = (int)size;

	for (i = 0; i < int_size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

/* Allocate memory for new arrays. */
	new = malloc(sizeof(int) * int_size);
	count = malloc(sizeof(int) * (max + 1));
	if (!new || !count)
		return;

/* Initialize empty array, store count of each element. */
	for (i = 0; i <= max; i++)
		count[i] = 0;
	for (i = 0; i < int_size; i++)
		count[array[i]]++;
/* Add cummulative count. */
	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

/* Find index of original array in count and store in new. */
	for (i = (int_size - 1); i >= 0; i--)
	{
		new[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	for (i = 0; i < int_size; i++)
		array[i] = new[i];

	print_array(count, ((size_t)max + 1));

	free(count);
	free(new);
}
