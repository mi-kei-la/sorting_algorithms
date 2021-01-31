#include "sort.h"

/**
 * bubble_sort - Algorithm for bubble sorting an array.
 * @array: Array to sort.
 * @size: Size of the array.
 */

void bubble_sort(int *array, size_t size)
{
	size_t i;
	int change_count;
	int tmp = 0;

	if (size < 2)
		return;
	if (array == NULL)
		return;

	/* Loop is broken when no changes are made, and the list is in order. */
	while (1)
	{
		change_count = 0;
		/* Loop through the array from the beginning until the second-last. */
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1]) /* Compare current to next value. */
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				change_count++;
				print_array(array, size);
			}
		}
		if (change_count == 0)
			break;
	}
}
