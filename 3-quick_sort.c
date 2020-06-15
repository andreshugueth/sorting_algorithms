#include "sort.h"
#include <stdlib.h>
/**
 * swap - waps two values
 * @a: first value
 * @b: second value
 *
 * Return: Nothing
 *
 */
void swap(int *a, int *b)
{
	int aux;

	aux = *a;
	*a = *b;
	*b = aux;
}
/**
 * lomuto_partition - bifurcate the array
 * @array: information of the array
 * @size: size of the array
 * @low: low value
 * @high: high value
 *
 * Return: int i
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int i, j, piv;

	i = low - 1;
	piv = array[high];

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] > piv)
			continue;

		i++;
		swap(&array[j], &array[i]);
		if (i  != j)
			print_array(array, size);

	}

	swap(&array[high], &array[i + 1]);
	if (i + 1 != j)
		print_array(array, size);

	return (i + 1);
}
/**
 * sort - sorts an array
 * @array: information of the array
 * @size: size of the array
 * @low: low value
 * @high: high value
 *
 * Return: Nothing
 *
 */
void sort(int *array, size_t size, int low, int high)
{
	if (low < high)
	{
		int p = lomuto_partition(array, size, low, high);

		sort(array, size, low, p - 1); /* Sort left partition */
		sort(array, size, p + 1, high); /* Sort rigth partition */
	}
}

/**
 * quick_sort - quick sort methodology
 * @array: array's information
 * @size: size of the array
 *
 * Return: Nothing
 *
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	sort(array, size, 0, size - 1);
}
