#include "shell.h"

/**
 * split_string - splits string into tokens
 * @buffer: string to split
 * @split_con: delimiter
 *
 * Return: Array of splitted parts terminated by a NULL pointer
 */
array split_string(string buffer, string split_con)
{
	string buf = NULL;
	array parts;
	int i = 0;

	parts = malloc(sizeof(string) * MAX_ARGS);
	if (parts == NULL)
	{
		return (NULL);
	}
	buf = strtok(buffer, split_con);
	while (buf)
	{
		parts[i++] = buf;
		buf = strtok(NULL, split_con);
	}
	parts[i] = NULL;
	return (parts);
}
