#include "sort.h"
/**
 * shell_sort - sort an array using knuth secuence
 * @array: array's information
 * @size: size of the array
 *
 * Return: Nothing
 *
 */
void shell_sort(int *array, size_t size)
{
	size_t in, out, gap;
	int value;

	if (!array || size < 2)
		return;

	gap = 1;
	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (out = gap; out < size; out++)
		{
			value = array[out];
			in = out;
			while ((in > gap - 1) && (array[in - gap] >= value))
			{
				array[in] = array[in - gap];
				in -= gap;
			}
			array[in] = value;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
