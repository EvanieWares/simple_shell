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

/**
 * _strcpynn - copies string
 * @dest: destination string
 * @src: source string
 * @dest_from: index to start copying to
 * @src_from: index to start copying from
 *
 * Return: pointer to the dstination string
 */
char *_strcpynn(string dest, const string src, int dest_from, int src_from)
{
	int i;

	for (i = 0; src[i + src_from] != '\0'; i++)
	{
		dest[i + dest_from] = src[i + src_from];
	}

	dest[i + dest_from] = '\0';
	return (dest);
}

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: 0 if the strings are equal
 */
int _strcmp(string s1, string s2)
{
	int i;
	int len;
	int result = 0;

	if (_strlen(s1) >= _strlen(s2))
	{
		len = _strlen(s1);
	}
	else
	{
		len = _strlen(s2);
	}

	for (i = 0; i < len; i++)
	{
		if (s1[i] == s2[i])
		{
			continue;
		}
		else
		{
			result = s1[i] - s2[i];
			break;
		}
	}

	return (result);
}
