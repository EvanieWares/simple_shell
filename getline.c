#include "shell.h"

/**
 * get_buf - reads input from stdin
 *
 * Return: user input
 */
string get_buf(void)
{
	int len;
	ssize_t bytes_read;
	string buffer = NULL;
	size_t buffer_length;

	bytes_read = getline(&buffer, &buffer_length, stdin);
	if (bytes_read == -1 || feof(stdin))
	{
		exit(0);
	}
	len = _strlen(buffer);
	buffer[len - 1] = '\0';

	return (buffer);
}

/**
 * _write - prints string to stdout
 * @str: string to print
 *
 * Return: number of bytes printed
 */
int _write(string str)
{
	return (write(STDOUT_FILENO, str, _strlen(str)));
}
