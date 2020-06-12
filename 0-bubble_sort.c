#include "sort.h"

/**
 * bubble_sort - Compare consecutive items
 * @array: unsorted array
 * @size: size of the array
 *
 * Return: nothing
 *
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int swap;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap = array[j];
				array[j] = array[j + 1];
				array[j + 1] = swap;
				print_array(array, size);
			}
		}
	}
}
