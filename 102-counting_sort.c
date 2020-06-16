#include "sort.h"
#include <stdlib.h>
/**
 * countintg_sort - counting sort implementation
 * @array: array's information
 * @size: size of the array
 *
 * Return: Nothing
 *
 */
void counting_sort(int *array, size_t size)
{
	int k, i;
	int *count_array, output[size];
	size_t swap, num, j;

	if (!array || size < 2)
		return;

	k = swap = num = 0;
	count_array = NULL;
	for (j = 0; j < size; j++)
	{
		output[j] = array[j];
		if (array[j] > k)
			k = array[j];
	}
	count_array = malloc(sizeof(int) * (k + 1));
	if (!count_array)
		return;

	for (i = 0; i <= k; i++)
		count_array[i] = 0;

	for (j = 0; j < size; j++)
		count_array[array[j]] += 1;

	for (i = 1; i <= k; i++)
	{
		swap = count_array[i];
		count_array[i] = num;
		num += swap;
	}
	for (j = 0; j < size; j++)
	{
		array[count_array[output[j]]] = output[j];
		count_array[output[j]] += 1;
	}

	print_array(count_array, k + 1);
	free(count_array);
}
