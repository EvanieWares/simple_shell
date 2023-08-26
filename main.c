#include "shell.h"

/**
 * main - UNIX command line interpreter
 * @argc: number of arguments supplied
 * @argv: list of arguments supplied
 *
 * Return: 0 (Success)
 */
int main(int argc, array argv)
{
	string buffer = NULL;
	ssize_t bytes_read;
	size_t buffer_length;
	int i = 1;
	int pip_check = isatty(STDIN_FILENO);
	array cmd_args;

	(void) argc;
	while (i)
	{
		if (pip_check)
		{
			_write(PROMPT);
		}
		bytes_read = getline(&buffer, &buffer_length, stdin);
		if (bytes_read == -1)
		{
			free(buffer);
			break;
		}
		cmd_args = split_string(buffer, " \t\n");
		if (cmd_args[0] == NULL)
		{
			free(cmd_args);
			continue;
		}
		if (access(cmd_args[0], X_OK) == -1)
		{
			_print_error(argv[0], cmd_args[0], i);
			_free(cmd_args);
			free(buffer);
			continue;
		}
		exec_cmd(cmd_args, argv);
		i++;
	}
	return (0);
}
