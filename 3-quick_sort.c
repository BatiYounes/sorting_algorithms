#include "sort.h"

void swap(int *a, int *b);
int lomuto_partition(int *array, size_t size, int low, int high);
void lomuto_sort(int *array, size_t size, int low, int high);
void quick_sort(int *array, size_t size);

/**
 * swap - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 *
 * Return: void, no return.
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - partition scheme.
 * @array: array of integers.
 * @size: size of the array.
 * @low: lowest index of the subset.
 * @high: highest index of the subset.
 *
 * Return: partition index.
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int *pivot = array + high, top, below;

	for (top = below = low; below < high; below++)
	{
		if (array[below] < *pivot)
		{
			if (top < below)
			{
				swap(array + below, array + top);
				print_array(array, size);
			}
			top++;
		}
	}

	if (array[top] > *pivot)
	{
		swap(array + top, pivot);
		print_array(array, size);
	}

	return (top);
}

/**
 * lomuto_sort - quicksort algorithm through recursion.
 * @array: array of integers.
 * @size: size of the array.
 * @low: lowest index of the array partition.
 * @high: highest index of the array partition.
 *
 * Return: void, no return.
 */
void lomuto_sort(int *array, size_t size, int low, int high)
{
	int part;

	if (high - low > 0)
	{
		part = lomuto_partition(array, size, low, high);
		lomuto_sort(array, size, low, part - 1);
		lomuto_sort(array, size, part + 1, high);
	}
}

/**
 * quick_sort - function that sorts an array of integers in ascending order
 * using the Quick sort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 *
 * Return: void, no return.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}

	lomuto_sort(array, size, 0, size - 1);
}

