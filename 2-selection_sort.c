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
	size_t min_value;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		min_value = i;
		/*  swap = 0; to show that no swap happens here */
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_value])
			{
				min_value = j;
			}
			if (i != min_value)
			{
				/* swap takes place here */
				int temp = array[i];

				array[i] = array[min_value];
				array[min_value] = temp;
				/* swap = 1; shows that swap happened here */

				print_array(array, size);
			}
		}
	}
}
