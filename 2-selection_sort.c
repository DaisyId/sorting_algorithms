#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * @size: array size
 * @array: array of integers
 */
void selection_sort(int *array, size_t size)
{
	size_t i, k, n;
	int min;

	for (i = 0; i < size; i++)
	{
		min = array[i];
		n = i;
		for (k = i + 1; k < size; k++)
		{
			if (min > array[k])
			{
				n = k;
				min = array[k];
			}
		}
		if (n != i)
		{
			array[n] = array[i];
			array[i] = min;
			print_array(array, size);
		}
	}
}
