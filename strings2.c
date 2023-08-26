#include "shell.h"

/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: source string
 *
 * Return: pointer to the destination string
 */
char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}

	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}

	dest[i + j] = '\0';
	return (dest);
}

/**
 * _strcpy - copies a string to another string
 * @dest: destination string
 * @src: source string
 *
 * Return: pointer to the destination string
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}

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
	array parts = NULL;
	int i = 0;

	if (buffer == NULL)
	{
		return (NULL);
	}

	parts = malloc(sizeof(string) * MAX_ARGS);
	if (parts == NULL)
	{
		return (NULL);
	}
	buf = strtok(buffer, split_con);
	while (buf != NULL && i < MAX_ARGS - 1)
	{
		parts[i] = buf;
		buf = strtok(NULL, split_con);
		i++;
	}
	parts[i] = NULL;
	return (parts);
}
