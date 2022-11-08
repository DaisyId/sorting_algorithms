#include "sort.h"

/**
 * bubble_sort - Sorts an array or integers in ascending order
 * @array: array of integers
 * @size: array size
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, n;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				n = array[j];
				array[j] = array[j + 1];
				array[j + 1] = n;
				print_array(array, size);
			}
		}
	}

}
