#include "shell.h"

int count_parts(string src, char split_char);

/**
 * split_string - breaks string into parts according to the delimiter
 * @src: string to split
 * @delim: the argument that delimit the token in parsed string
 *
 * Return: array containing the command and arguments
 */
char **split_string(string src, char delim)
{
	int i = 0, k, parts_count, start_index = 0, j = 0;
	array parts;

	parts_count = count_parts(src, delim);
	parts = malloc((parts_count + 1) * sizeof(char *));
	if (parts == NULL)
	{
		return (NULL);
	}
	while (src[i] != '\0')
	{
		if (src[i] == delim)
		{
			parts[j] = malloc((i - start_index + 1) * sizeof(char));
			if (parts[j] == NULL)
			{
				return (NULL);
			}
			for (k = start_index; k < i; k++)
			{
				parts[j][k - start_index] = src[k];
			}
			parts[j][k - start_index] = '\0';
			start_index = i + 1;
			j++;
		}
		i++;
	}
	parts[j] = malloc((i - start_index + 1) * sizeof(char));
	if (parts[j] == NULL)
	{
		return (NULL);
	}
	for (k = start_index; k < i; k++)
	{
		parts[j][k - start_index] = src[k];
	}
	parts[j][k - start_index] = '\0';
	parts[j + 1] = NULL;

	return (parts);
}

/**
 * count_parts - count the number of parts the string will
 * have after being splitted
 * @str: string to count parts from
 * @delim: the delimiter
 *
 * Return: the number of parts the string will have
 */
int count_parts(string str, char delim)
{
	int count = 1, i = 0;

	if (str == NULL)
	{
		return (0);
	}
	while (str[i] != '\0')
	{
		if (str[i] == delim)
		{
			count++;
		}
		i++;
	}
	return (count);
}
