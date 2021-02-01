#include "sort.h"

/**
 * selection_sort - Sort values of an array by selection.
 *
 * @array: Array of integers to sort.
 * @size: Size of the given array.
 */

void selection_sort(int *array, size_t size)
{
	unsigned int i, j, x = 0, last_pos = 0;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		last_pos = i;
		for (j = i; j < size; j++)
		{
			if ((array[j] < array[i]) && (array[j] < array[last_pos]))
				last_pos = j;
		}
		if (array[last_pos] != array[i])
		{
			x = array[i];
			array[i] = array[last_pos];
			array[last_pos] = x;
			print_array(array, size);
		}
	}
}
