#include "shell.h"

/**
 * _isdigit - checks if a character is a digit
 * @c: char to check
 * Return: 1 if true, 0 if false
 */

int _isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _atoi - converts a string to an integer
 * @s: string to convert
 * Return: int
 */

int _atoi(char *s)
{
	int len = 0;
	int result = 0;
	int sign = 1;
	int started = 0;

	while (s[len] != '\0')
	{
		if (s[len] == '-')
		{
			sign *= -1;
		}
		else if (s[len] == '+')
		{
			sign *= 1;
		}
		else if (_isdigit(s[len]))
		{
			started = 1;
			if (sign > 0)
			{
				result = result * 10 + (s[len] - '0');
			}
			else
			{
				result = result * 10 - (s[len] - '0');
			}
		}
		else if (started && s[len] == ' ')
		{
			break;
		}
		len++;
	}
	return (result);
}