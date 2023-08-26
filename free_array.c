#include "shell.h"

/**
 * _free - frees an array
 * @arr: array to free
 */
void _free(array arr)
{
	int i = 0;

	if (arr)
	{
		while (arr[i] != NULL)
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
}
