#include "shell.h"

/**
 * _strlen - returns the number of characters in a string
 * @src: string to count chars from
 *
 * Return: number of characters
 */
size_t _strlen(const string src)
{
	size_t len = 0;

	while (src[len] != '\0')
	{
		len++;
	}

	return (len);
}

char *_strcpyn(char *dest, const char *src, int n)
{
	int i;

	for (i = 0; src[i + n] != '\0'; i++)
	{
		dest[i] = src[i + n];
	}

	dest[i] = '\0';
	return (dest);
}
