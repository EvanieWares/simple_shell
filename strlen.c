#include "shell.h"

/**
 * _strlen - returns the number of characters in a string
 * @src: string to count chars from
 *
 * Return: number of characters
 */
int _strlen(string src)
{
	int len = 0;

	while (src[len] != '\0')
	{
		len++;
	}
	return (len);
}
