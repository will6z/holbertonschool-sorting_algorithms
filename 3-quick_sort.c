#include <stdio.h>
#include "sort.h"

/**
* quick_sort - Sorts an array of integers in ascending order
* using the Quick sort algorithm.
* @array: The array to sort.
* @size: The size of the array.
*/
void quick_sort(int *array, size_t size)
{
if (size < 2)
return;
lomuto_quick_sort(array, 0, size - 1, size);
}

/**
* lomuto_quick_sort - Helper function that implements the Quick sort algorithm
* using the Lomuto partition scheme.
* @array: The array to sort.
* @low: The starting index of the array segment to sort.
* @high: The ending index of the array segment to sort.
* @size: The total size of the array, used for printing.
*/
void lomuto_quick_sort(int *array, int low, int high, size_t size)
{
if (low < high)
{
int i = low - 1;
int pi;
recursive_partition(array, low, high, &i, size);
pi = i + 1;
swap(&array[pi], &array[high], array, size);
lomuto_quick_sort(array, low, pi - 1, size);
lomuto_quick_sort(array, pi + 1, high, size);
}
}

/**
* recursive_partition - Partitions the array segment recursively using
* the Lomuto partition scheme.
* @array: The array to partition.
* @low: The starting index of the array segment to partition.
* @high: The ending index of the array segment to partition.
* @i: Pointer to the partition index.
* @size: The total size of the array, used for printing.
*/
void recursive_partition(int *array, int low, int high, int *i, size_t size)
{
if (low < high)
{
if (array[low] < array[high])
{
*i = *i + 1;
swap(&array[*i], &array[low], array, size);
}
recursive_partition(array, low + 1, high, i, size);
}
}

/**
* swap - Swaps two elements in the array and prints the array after swapping.
* @a: Pointer to the first element to swap.
* @b: Pointer to the second element to swap.
* @array: The entire array, used for printing.
* @size: The size of the array, used for printing.
*/
void swap(int *a, int *b, int *array, size_t size)
{
if (*a != *b)
{
int tmp = *a;
*a = *b;
*b = tmp;
print_array(array, size);
}
}

