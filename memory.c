#include "shell.h"

/**
 * _free - frees an array
 * @args: array to free
 */
void _free(array args)
{
	int i = 0;

	if (args != NULL)
	{
		while (args[i] != NULL)
		{
			free(args[i]);
			i++;
		}
		free(args);
	}
}
