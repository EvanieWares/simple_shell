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
 * @pg_name: name of the program
 * @process_no: process number
 *
 * Return: 1 if it command matches inbuilt command
 */
int is_builtin(array cmd_args, string pg_name, string buffer, int *process_no)
{
	int status = 0;

	if (_strcmp(cmd_args[0], "exit") == 0)
	{
		if (cmd_args[1])
		{
			status = _atoi(cmd_args[1]);
			if (status == -1)
			{
				errno = 2;
				_print_atoi_error(pg_name, cmd_args, *process_no);
				*process_no += 1;
				free_array(cmd_args);
				return (1);
			}
			free(buffer);
			free_array(cmd_args);
			exit(status % 256);
		}
		free(buffer);
		free_array(cmd_args);
		exit(errno);
	}
	if (_strcmp(cmd_args[0], "env") == 0)
	{
		print_env();
		free_array(cmd_args);
		*process_no += 1;
		status = 1;
	}
	return (status);
}
