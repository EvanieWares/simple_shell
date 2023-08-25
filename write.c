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
