#include "sort.h"

void swap(int *a, int *b);

/**
 * shell_sort - function that sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence
 * @array: array of integers.
 * @size: size of the array.
 *
 * Return: void, no return.
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, gap_size;

	if (array == NULL || size < 2)
		return;

	for (gap_size = 1; gap_size < (size / 3);)
		gap_size = gap_size * 3 + 1;

	for (; gap_size >= 1; gap_size /= 3)
	{
		for (i = gap_size; i < size; i++)
		{
			j = i;
			while (j >= gap_size && array[j - gap_size] > array[j])
			{
				swap(array + j, array + (j - gap_size));
				j = j - gap_size;
			}
		}
		print_array(array, size);
	}
}

/**
 * swap - function swap two integers.
 * @a: first integer to swap.
 * @b: second integer to swap.
 *
 * Return: void, no return.
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

