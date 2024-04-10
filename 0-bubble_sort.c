#include "sort.h"
#include <stdlib.h>

/**
 * bubble_sort - sorts array of ints
 * @array: input
 * @size: input
 * Return: 0
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int t;
	int swap;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swap = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				t = array[j];
				array[j] = array[j + 1];
				array[j + 1] = t;
				print_array(array, size);
				swap = 1;
			}
		}
		if (swap == 0)
			break;
	}
}
