#include "sort.h"

/**
 * quick_sort - sort an array with the quicksort method.
 *
 * @array: SAray of integers to sort.
 * @size: Size of the array.
 */

void quick_sort(int *array, size_t size)
{
	int lo, hi;

	lo = 0;
	hi = size - 1;

	quicker(array, lo, hi, size);
}

/**
 * quicker - function to implement the Lomuto partition scheme.
 *
 * @array: Array to sort.
 * @lo: Starting point.
 * @hi: Last index of array.
 * @size: Size of the array.
 */

void quicker(int *array, int lo, int hi, size_t size)
{
	int p;

	if (lo < hi)
	{
		p = part(array, lo, hi, size);
		quicker(array, lo, p - 1, size);
		quicker(array, p + 1, hi, size);
	}
}

/**
 * part - Function to sort sub-arrays and change pivot point.
 *
 * @array: Array to sort.
 * @lo: Index of starting point.
 * @hi: Index of last value of sub-array.
 * @size: Size of the array.
 *
 * Return: new pivot.
 */

int part(int *array, int lo, int hi, size_t size)
{
	int tmp, pivot, i, j;

	pivot = array[hi];
	i = lo;
	for (j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			if (array[j] != array[i])
				print_array(array, size);
			i = i + 1;
		}
	}
	tmp = array[i];
	array[i] = array[hi];
	array[hi] = tmp;
	if (array[i] != array[hi])
		print_array(array, size);
	return (i);
}
