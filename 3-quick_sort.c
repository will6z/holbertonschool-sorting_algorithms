#include <stdio.h>
#include "sort.h"
void lomuto_quick_sort(int *array, int low, int high, size_t size);
int partition(int *array, int low, int high, size_t size);
void swap(int *a, int *b, int *array, size_t size);

/**
 * quick_sort - sorts an array of integers in ascending order using
 * the Quick sort algorithm with the Lomuto partition scheme.
 * @array: the array to be sorted
 * @size: the number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
    if (size < 2)
        return;

    lomuto_quick_sort(array, 0, size - 1, size);
}

void lomuto_quick_sort(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pi = partition(array, low, high, size);

        lomuto_quick_sort(array, low, pi - 1, size);
        lomuto_quick_sort(array, pi + 1, high, size);
    }
}

int partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            swap(&array[i], &array[j], array, size);
        }
    }
    swap(&array[i + 1], &array[high], array, size);
    return (i + 1);
}

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

