#include "sort.h"

/**
 * selection_sort -  function that sorts an array of integers
 * in ascending order using the Selection sort algorithm
 * @array: pointer to the array
 * @size: size of the array
 * Return: ascending order of an array of integers
 * NIL if size is < 2
 */
void selection_sort(int *array, size_t size)
{
	size_t i;
	size_t j;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		/*  swap = 0; to show that no swap happens here */
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[i])
			{
				int temp = array[i];

				array[i] = array[j];
				array[j] = temp;
				/* swap = 1; shows that swap happened here */

				print_array(array, size);
			}
		}
	}
}
