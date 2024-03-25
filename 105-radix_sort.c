#include "sort.h"

int _max(int *array, int size);
void radix_count_sort(int *array, size_t size, int sig, int *buffer);

/**
 * radix_sort - function sort an array of integers in ascending
 * order using the radix sort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 *
 * Return: void, no return.
 */
void radix_sort(int *array, size_t size)
{
	int max, sig, *buffer;

	if (array == NULL || size < 2)
	{
		return;
	}

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
	{
		return;
	}

	max = _max(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_count_sort(array, size, sig, buffer);
		print_array(array, size);
	}

	free(buffer);
}

/**
 * _max - function get the maximum value in an array of integers.
 * @array: array of integers.
 * @size: size of the array.
 *
 * Return: maximum integer in the array.
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

/**
 * radix_count_sort - function sort the significant digits of an array of
 * integers in ascending order using the counting sort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 * @sig: significant digit to sort on.
 * @buffer: buffer to store the sorted array.
 *
 * Return: void, no return
 */
void radix_count_sort(int *array, size_t size, int sig, int *buffer)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
	{
		count[(array[i] / sig) % 10] += 1;
	}

	for (i = 0; i < 10; i++)
	{
		count[i] += count[i - 1];
	}

	for (i = size - 1; (int)i >= 0; i--)
	{
		buffer[count[(array[i] / sig) % 10] - 1] = array[i];
		count[(array[i] / sig) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
	{
		array[i] = buffer[i];
	}
}

