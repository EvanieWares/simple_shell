#include "shell.h"

/**
 * num_to_string - converts a number to string
 * @num: number to convert
 * @str: char array to store the converted number
 */
void num_to_string(string str, int num)
{
	int j, i = 0;

	do {
		str[i++] = num % 10 + '0';
		num /= 10;
	} while (num > 0);

	/* Reverse the string */
	for (j = 0; j < i / 2; j++)
	{
		char temp = str[j];

		str[j] = str[i - j - 1];
		str[i - j - 1] = temp;
	}

	/* Add null terminator at the end */
	str[i] = '\0';
}

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
