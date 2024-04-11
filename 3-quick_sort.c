#include <stdio.h>
#include "sort.h" 

void lomuto_quick_sort(int *array, int low, int high, size_t size);
void recursive_partition(int *array, int low, int high, int *i, size_t size);
void swap(int *a, int *b, int *array, size_t size);

/**
 * quick_sort - desc
 * @array: array
 * @size: size
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
        int i = low - 1;
        int pi;
        recursive_partition(array, low, high, &i, size);
        pi = i + 1;
        swap(&array[pi], &array[high], array, size);

        lomuto_quick_sort(array, low, pi - 1, size);
        lomuto_quick_sort(array, pi + 1, high, size);
    }
}


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

