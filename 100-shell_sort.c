#include "sort.h"

/**
 * shell_sort - Sorts an array of integers
 * in ascending order using Shell sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t g = 1, i, j;
	int temp;

	if (array == NULL || size < 2)
		return;

	while (g < size)
		g = g * 3 + 1;

	for (; g > 0; g = (g - 1) / 3)
	{
		for (i = g; i < size; i++)
		{
			temp = array[i];

			for (j = i; j >= g && array[j - g] > temp; j -= g)
			{
				array[j] = array[j - g];
			}
			array[j] = temp;
		}
		if (g < size)
			print_array(array, size);
	}
}
