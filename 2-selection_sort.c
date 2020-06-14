#include "sort.h"

/**
 * selection_sort - selection sort algorithm
 * @array: given array to be sorted
 * @size: size of the array
 *
 * Return: Nothing
 *
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, tmp;
	int swap, min, cond;

	if (!array || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		cond = 0;
		min = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (min > array[j])
			{
				tmp = j;
				min = array[j];
				cond = 1;
			}
		}
		if (cond)
		{
			swap = array[i];
			array[i] = min;
			array[tmp] = swap;
			print_array(array, size);
		}
	}
}
