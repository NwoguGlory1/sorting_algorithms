#include "sort.h"

/**
 * _swap - this swaps two values in an array
 * @array: array of integers
 * @i: first value of the array
 * @j: second value of array
 * @size: size of array
 * Return: No Return
 */
void _swap(int *array, int i, int j, int size)
{
	int tmp;

	if (array[i] != array[j])
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
		print_array(array, size);
	}
}

/**
 * partition - sorts a partition of data in relation to a pivot
 * @array: array of integers
 * @size: size of the array
 * @min: left wall
 * @max: right wall
 * Return: New pivot
 */
int partition(int *array, int min, int max, size_t size)
{
	int i = min, j, pivot = array[max];

	for (j = min; j <= max; j++)
	{
		if (array[j] < pivot)
		{
			_swap(array, i, j, size);
			i++;

		}
	}
	_swap(array, i, max, size);
	return (i);
}

/**
 * quicksort -  function that sorts an array of integers
 * in ascending order using the Quick sort algorithm Lomuto partition scheme
 * @array: array of integers
 * @size: size of the array
 * @min: left wall
 * @max: right wall
 * Return: No return
 */
void quicksort(int *array, int min, int max, size_t size)
{
	int x;

	if (min < max)
	{
		x = partition(array, min, max, size);
		quicksort(array, min, x - 1, size);
			quicksort(array, x + 1, max, size);
	}
}

/**
 * quick_sort -  function that sorts an array of integers
 * in ascending order using the Quick sort algorithm Lomuto partition scheme
 * that always takes the last element as the pivot
 * @array: array of integers
 * @size: size of the array
 *
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
