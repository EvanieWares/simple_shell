#include "shell.h"

/**
 * exec_cmd - executes the command
 * @cmd_args: array of user command and it arguments
 * @argv: array of arguments supplied to the program
 */
void exec_cmd(array cmd_args, array argv)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid < 0)
	{
		perror(argv[0]);
		exit(-1);
	}
	if (child_pid == 0)
	{
		execve(cmd_args[0], cmd_args, environ);
		perror(argv[0]);
		exit(2);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			status = WEXITSTATUS(status);
		}
		errno = status;
		free_array(cmd_args);
	}
}
