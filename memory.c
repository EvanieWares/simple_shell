#include "shell.h"

/**
 * free_array - frees an array
 * @args: array to free
 */
void free_array(array args)
{
	int i = 0;

	if (args)
	{
		while (args[i] != NULL)
		{
			free(args[i]);
			i++;
		}
		free(args);
	}
}
