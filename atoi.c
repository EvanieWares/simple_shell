#include "shell.h"

/**
 * _atoi - converts a string to an integer
 * @str: string to convert
 *
 * Return: integer
 */
int _atoi(const string str)
{
	int number = 0;
	int i = 0;

	if (str[0] == '-')
	{
		return (-1);
	}

	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			number = (number * 10) + (str[i] - '0');
			i++;
		}
		else
		{
			return (-1);
		}
	}

	return (number);
}
