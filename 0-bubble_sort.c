#include <stdbool.h>
#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers
 * in ascending order using Bubble sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	int temp;
	bool swapped;

	if (array == NULL || size < 2)
		return;

	do {
		swapped = false;

		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;

				print_array(array, size);
				swapped = true;
			}
		}
		len--;
	} while (swapped);
}
