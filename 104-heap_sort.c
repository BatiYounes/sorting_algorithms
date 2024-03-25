#include "sort.h"

void swap(int *a, int *b);
void heapify(int *array, size_t size, size_t base, size_t root);

/**
 * heap_sort - function that sorts an array of integers in ascending
 * order using the Heap sort algorithm.
 * @array: array of integers to sort.
 * @size: size of the array.
 *
 * Return: void, no return.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (i = (size / 2) - 1; i >= 0; i--)
	{
		heapify(array, size, size, i);
	}

	for (i = size - 1; i > 0; i--)
	{
		swap(array, array + i);
		print_array(array, size);
		heapify(array, size, i, 0);
	}
}

/**
 * swap - function swap two integers in an array.
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
 * heapify - heap sort algorithm.
 * @array: array of integers representing a binary tree.
 * @size: size of the array/tree.
 * @base: index of the base row of the tree.
 * @root: root node of the binary tree.
 *
 * Return: void, no return.
 */
void heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
	{
		large = left;
	}

	if (right < base && array[right] > array[large])
	{
		large = right;
	}

	if (large != root)
	{
		swap(array + root, array + large);
		print_array(array, size);
		heapify(array, size, base, large);
	}
}

