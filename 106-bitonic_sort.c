#include <stdio.h>
#include "sort.h"

/**
 * bitonic_merge - Performs bitonic merge on the array
 * @array: Array to be sorted
 * @size: Size of the array
 * @dir: Sorting direction (UP for ascending, DOWN for descending)
 **/
void bitonic_merge(int *array, size_t size, int dir)
{
    if (size > 1)
    {
        size_t mid = size / 2;
        size_t i;

        printf("Merging [%lu/%lu] (%s):\n", size, size, (dir == UP) ? "UP" : "DOWN");
        print_array(array, size);

        for (i = 0; i < mid; i++)
        {
            if ((array[i] > array[i + mid]) == dir)
            {
                swap(&array[i], &array[i + mid]);
                printf("Result [2/%lu] (%s):\n", size, (dir == UP) ? "UP" : "DOWN");
                print_array(array, size);
            }
        }

        bitonic_merge(array, mid, dir);
        bitonic_merge(array + mid, mid, dir);
    }
}

/**
 * bitonic_sort_recursive - Recursively performs bitonic sort
 * @array: Array to be sorted
 * @size: Size of the array
 * @dir: Sorting direction (UP for ascending, DOWN for descending)
 **/
void bitonic_sort_recursive(int *array, size_t size, int dir)
{
    if (size > 1)
    {
        size_t mid = size / 2;

        bitonic_sort_recursive(array, mid, UP);
        bitonic_sort_recursive(array + mid, mid, DOWN);
        bitonic_merge(array, size, dir);
    }
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using Bitonic sort
 * @array: Array to be sorted
 * @size: Size of the array
 **/
void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    bitonic_sort_recursive(array, size, UP);
}
