#include "shell.h"

/**
 * print_env - prints environment variables
 */
void print_env(void)
{
	int i = 0;

	while (environ[i]	!= NULL)
	{
		_write(environ[i]);
		_write("\n");
		i++;
	}
}

/**
 * is_builtin - checks and executes builtin functions
 * @args: array containing command and arguments
 *
 * Return: 1 if it command matches inbuilt command
 */
int is_builtin(array args)
{
	if (_strcmp(args[0], "exit") == 0)
	{
		free(args);
		exit(0);
	}
	if (_strcmp(args[0], "env") == 0)
	{
		print_env();
		return (1);
	}
	return (0);
}
