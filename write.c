#include "shell.h"

/**
 * _write - prints string to stdout
 * @str: string to print
 *
 * Return: bytes printed
 */
int _write(string str)
{
	return (write(STDOUT_FILENO, str, _strlen(str)));
}

/**
 * _ewrite - prints errors to stderr
 * @str: string to print
 *
 * Return: bytes printed
 */
int _ewrite(string str)
{
	return (write(STDERR_FILENO, str, _strlen(str)));
}
