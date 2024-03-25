#include "sort.h"

/**
 * selection_sort - function that sorts an array of integers in ascending order
 * using the Selection sort algorithm.
 * @array: array of integers that need to be sorted.
 * @size: size of the array of integers.
 *
 * Return: void, no return.
 */
void selection_sort(int *array, size_t size)
{
	int *min_e, temp, *arr_i;
	size_t i, j;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (i = 0; i < size - 1; i++)
	{
		min_e = array + i;
		arr_i = array + i;

		for (j = i + 1; j < size; j++)
		{
			min_e = (array[j] < *min_e) ? (array + j) : min_e;
		}

		if ((array + i) != min_e)
		{
			temp = *(array + i);
			*arr_i = *min_e;
			*min_e = temp;

			print_array(array, size);
		}
	}
}

