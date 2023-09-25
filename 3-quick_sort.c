#include <stdio.h>
#include "sort.h"

/**
 * swap - swaptwo integ in an array and prints the array
 * @array:input
 * @size:input
 * @a:input
 * @b:input
 */
void swap(int *array, size_t size, int *a, int *b)
{
	int tmp;

	if (*a != *b)
	{
		tmp = *a;
		*a = *b;
		*b = tmp;
		print_array(array, size);
	}
}

/**
 * lomuto_partition - lomuto scheme for quicksort
 * @array:input
 * @size:input
 * @LOW:input
 * @HIGH:input
 * Return:the final position of the pivot
 */
int lomuto_partition(int *array, size_t size, int LOW, int HIGH)
{
	int *pivot = &array[HIGH];
	int i = LOW - 1, j;

	for (j = LOW; j <= HIGH - 1; j++)
	{
		if (array[j] < *pivot)
		{
			i++;
			swap(array, size, &array[i], &array[j]);
		}
	}
	swap(array, size, &array[i + 1], pivot);
	return (i + 1);
}

/**
 * quicksort - recursive function to perform quicksort
 * @array:input
 * @size:input
 * @LOW:input
 * @HIGH:input
 */
void quicksort(int *array, size_t size, int LOW, int HIGH)
{
	if (LOW < HIGH)
	{
		int pi = lomuto_partition(array, size, LOW, HIGH);

		quicksort(array, size, LOW, pi - 1);
		quicksort(array, size, pi + 1, HIGH);
	}
}

/**
 * quick_sort - sorts an array og integ in ascending order
 * @array:input
 * @size:input
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, size, 0, size - 1);
}
