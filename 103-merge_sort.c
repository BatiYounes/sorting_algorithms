#include "sort.h"
#include <stdio.h>

void merge_sort_rec(int *subarr, int *buffer, size_t head, size_t tail);
void merge_subarr(int *subarr, int *buffer, size_t head, size_t mid,
		size_t tail);

/**
 * merge_sort - function that sorts an array of integers in ascending order
 * using the Merge sort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 *
 * Return: void, no return.
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
	{
		return;
	}

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
	{
		return;
	}

	merge_sort_rec(array, buffer, 0, size);

	free(buffer);
}


/**
 * merge_sort_rec - function merge sort algorithm through recursion.
 * @subarr: subarray of an array of integers to sort.
 * @buffer: buffer to store the sorted array.
 * @head: head index of the subarray.
 * @tail: tail index of the subarray.
 *
 * Return: void, no return.
 */
void merge_sort_rec(int *subarr, int *buffer, size_t head, size_t tail)
{
	size_t i;

	if (tail - head > 1)
	{
		i = head + (tail - head) / 2;
		merge_sort_rec(subarr, buffer, head, i);
		merge_sort_rec(subarr, buffer, i, tail);
		merge_subarr(subarr, buffer, head, i, tail);
	}
}

/**
 * merge_subarr - function merge a subarray of integers.
 * @subarr: subarray of an array of integers to merge.
 * @buffer: buffer to store the merged subarray.
 * @head: The front index of the array.
 * @mid: The middle index of the array.
 * @tail: The back index of the array.
 *
 * Return: void, no return.
 */
void merge_subarr(int *subarr, int *buffer, size_t head, size_t mid,
		size_t tail)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + head, mid - head);

	printf("[right]: ");
	print_array(subarr + mid, tail - mid);

	for (i = head, j = mid; i < mid && j < tail; k++)
		buffer[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
	for (; i < mid; i++)
		buffer[k++] = subarr[i];
	for (; j < tail; j++)
		buffer[k++] = subarr[j];
	for (i = head, k = 0; i < tail; i++)
		subarr[i] = buffer[k++];

	printf("[Done]: ");
	print_array(subarr + head, tail - head);
}

