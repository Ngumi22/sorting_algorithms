#include "sort.h"
/**
 * counting_sort - Sorts an array of integers in ascending order using
 * the Counting sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int *output_array, *counting_array;
	size_t max, i;

	if (array == NULL || size < 2)
		return;
	max = array[0];

	for (i = 1; i < size; i++)
	{
		if ((size_t)array[i] > max)
			max = array[i];
	}
	counting_array = malloc((max + 1) * sizeof(int));
	if (counting_array == NULL)
		return;
	for (i = 0; i <= max; i++)
		counting_array[i] = 0;
	for (i = 0; i < size; i++)
		counting_array[array[i]]++;
	for (i = 1; i <= max; i++)
		counting_array[i] += counting_array[i - 1];
	output_array = malloc(size * sizeof(int));
	if (output_array == NULL)
	{
		free(counting_array);
		return;
	}
	for (i = size; i > 0; i--)
	{
		output_array[counting_array[array[i - 1]] - 1] = array[i - 1];
		counting_array[array[i - 1]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output_array[i];
	print_array(counting_array, max + 1);

	free(counting_array);
	free(output_array);
}
