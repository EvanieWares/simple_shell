#include "shell.h"

int count_parts(char *src, char split_char);

char **split_string(char *src, char split_char, int *count)
{
	int i, k, parts_count, start_index = 0, j = 0;
	char **parts;

	parts_count = count_parts(src, split_char);
	parts = malloc((parts_count + 1) * sizeof(char *));
	if (parts == NULL)
	{
		return (NULL);
	}
	while (src[i] != '\0')
	{
		if (src[i] == split_char)
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
	parts[j] = malloc ((i - start_index + 1) * sizeof(char));
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

	*count = parts_count;

	return (parts);
}

int count_parts(char *str, char split_char)
{
	int count = 1, i = 0;

	if (str == NULL)
	{
		return (0);
	}
	while (str[i] != '\0')
	{
		if (str[i] == split_char)
		{
			count++;
		}
		i++;
	}
	return (count);
}
