#include "sort.h"

int _max(int *array, int size);

/**
 * counting_sort - function that sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: array of integers.
 * @size: size of the array.
 *
 * Return: void, no return.
 */
void counting_sort(int *array, size_t size)
{
	int i, max, *count, *sorted;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;

	max = _max(array, size);
	count = malloc(sizeof(int) * (max + 1));

	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (i = 0; i < (max + 1); i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (i = 0; i < (max + 1); i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(sorted);
	free(count);
}

/**
 * _max - function get the maximum value in an array of integers.
 * @array: array of integers.
 * @size: size of the array.
 *
 * Return: void, no return.
 */
int _max(int *array, int size)
{
	int i, max;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}

	return (max);
}

