#include "shell.h"

/**
 * print_env - prints environment variables
 */
void print_env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		_write(environ[i]);
		_write("\n");
		i++;
	}
}

/**
 * is_builtin - checks and executes builtin functions
 * @cmd_args: array containing command and arguments
 * @buffer: input buffer
 *
 * Return: 1 if it command matches inbuilt command
 */
int is_builtin(array cmd_args, string buffer)
{
	int status = 0;

	if (_strcmp(cmd_args[0], "exit") == 0)
	{
		free(buffer);
		free_array(cmd_args);
		exit(errno);
	}
	if (_strcmp(cmd_args[0], "env") == 0)
	{
		print_env();
		buffer = NULL;
		free_array(cmd_args);
		status = 1;
	}
	return (status);
}
