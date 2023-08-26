#include "shell.h"

/**
 * check_cmd - validates user commands
 * @cmd_args: array of user command and arguments
 * @argv: array of arguments supplied to the program
 * @process_no: process number
 *
 * Return: 1 if the command is valid, otherwise 0
 */
int check_cmd(array cmd_args, array argv, int process_no)
{
	if (access(cmd_args[0], X_OK) == -1)
	{
		string full_path = search_path(cmd_args[0]);

		if (full_path != NULL)
		{
			free(cmd_args[0]);
			cmd_args[0] = full_path;
			return (1);
		}
		else
		{
			_print_error(argv[0], cmd_args[0], process_no);
			free_array(cmd_args);
			return (0);
		}
	}

	return (1);
}
