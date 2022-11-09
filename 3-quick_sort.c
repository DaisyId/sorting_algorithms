#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order
 * @array: array of integers
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	size_t low;

	low = 0;
	if (size < 2 || array == NULL)
		return;
	sort(array, low, size - 1, size);
}

/**
 * sort - Sorting
 * @array: array of integers
 * @beg: lower bound of the array partition
 * @end: upper bound of the array partion
 * @og: The original size of the whole array
 */
void sort(int *array, size_t beg, size_t end, size_t og)
{
	size_t i;
	size_t j;
	int piv;
	int flag;
	int c;

	piv = array[end];
	j = beg;
	i = j - 1;
	flag = 0;

	for (j = beg; j < end; j++)
	{
		if (array[j] <= piv)
		{
			i++;
			flag = swap_int(array, j, i, og);
		}
	}
	i++;
	flag = swap_int(array, j, i, og);

	if (flag == 0)
	{
		c = check(array, beg, end);
		if (c == 1)
			sort(array, beg, end - 1, og);
	}
	else
	{
		sort(array, beg, i, og);
		sort(array, i, end, og);
	}
}

/**
 * swap_int - Swaps the numbers in the array
 * @array: Array of integers that need to be sorted
 * @i: lower bound of the array partition
 * @j: upper bound of the array partion
 * @og: size of the array
 * Return: 1 on success, else 0
 */
int swap_int(int *array, size_t i, size_t j, size_t og)
{
	int tmp;

	if (j != i)
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
		print_array(array, og);
		return (1);
	}
	return (0);
}

/**
 * check - checks if the array portion is already sorted
 * @array: Array of integers that need to be sorted
 * @beg: lower bound of the array partition
 * @end: upper bound of the array partion
 * Return: 1 if the array is not sorted, else 0
 */
int check(int *array, size_t beg, size_t end)
{
	size_t i;

	for (i = beg; i < end; i++)
	{
		if (array[i] > array[i + 1])
			return (1);
	}
	return (0);
}
