#include "sort.h"
#include <stdio.h>

/**
 * partition - Partitionne le tableau en utilisant
 * le schéma de partition Lomuto
 * @array: Tableau à partitionner
 * @debu: Indice de début de la partition
 * @end: Indice de fin de la partition
 * @size: Taille du tableau
 *
 * Return: Indice de l'élément pivot
 */
int partition(int *array, int debu, int end, int size)
{
	int pivot = array[end];
	int i, temp;
	int partition_index = debu;

	for (i = debu; i < end; i++)
	{
		if (array[i] <= pivot)
		{

			if (partition_index != i)
			{
				temp = array[partition_index];
				array[partition_index] = array[i];
				array[i] = temp;
				print_array(array, size);
			}
			partition_index++;
		}
	}
	if (partition_index != end)
	{
		temp = array[partition_index];
		array[partition_index] = array[end];
		array[end] = temp;
		print_array(array, size);
	}
	return (partition_index);
}

/**
 * quickSort - recursively of array to use quick_sort
 * @array: pointer to tried
 * @debu: indice debut du tableau
 * @end: indice fin du tableau
 * @size: size of array
 */

void quickSort(int *array, int debu, int end, int size)
{
	int parti_index;

	if (debu < end)
	{
		parti_index = partition(array, debu, end, size);
		quickSort(array, debu, parti_index - 1, size);
		quickSort(array, parti_index + 1, end, size);
	}
}


/**
 * quick_sort - function that sorts an array of integers in
 * ascending order using the Quick sort algorithm
 * @array: pointer to tried
 * @size: size of the array
 *
 * Return: no return
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quickSort(array, 0, size - 1, size);
}
