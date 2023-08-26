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
	string buffer = NULL, full_cmd;
	size_t buffer_length;
	int count = 0, bytes_read, pip_check = isatty(STDIN_FILENO);
	array cmd_args = NULL;

	(void) argc;
	while (1)
	{
		count++;
		if (pip_check)
			_write(PROMPT);

		bytes_read = getline(&buffer, &buffer_length, stdin);
		if (bytes_read == -1)
		{
			free(buffer);
			if (pip_check)
				_write("\n");

			break;
		}
		cmd_args = split_string(buffer, " \n");
		if (cmd_args[0] == NULL)
			continue;
		if (is_builtin(cmd_args))
			continue;
		full_cmd = valid_cmd(cmd_args[0]);
		if (full_cmd == NULL)
		{
			_print_error(argv[0], cmd_args[0], count);
			free(cmd_args);
			errno = 127;
			continue;
		}

		exec_full_cmd(full_cmd, cmd_args, argv);
		/*if (full_cmd != cmd_args[0])
			free(full_cmd);*/
	}
	return (errno);
}

		/**
		* if (access(cmd_args[0], X_OK) == 0)
		{
			exec_cmd(cmd_args, argv);
		}
		else
		{
			string full_cmd = get_full_cmd(cmd_args[0]);
			if (full_cmd == NULL)
			{
				_print_error(argv[0], cmd_args[0], i);
				free(cmd_args);
				errno = 127;
				continue;
			}
			exec_full_cmd(full_cmd, cmd_args, argv);
		}
		*/
