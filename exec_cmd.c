#include "shell.h"

/**
 * exec_cmd - executes the command
 * @cmd_args: array of command and it arguments
 * @argv: array of arguments supplied to the program
 */
void exec_cmd(array cmd_args, array argv)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror(argv[0]);
		_free(cmd_args);
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		execve(cmd_args[0], cmd_args, environ);
		perror(argv[0]);
		_free(cmd_args);
		exit(EXIT_FAILURE);
	}
	wait(&status);
	if (WIFEXITED(status))
	{
		status = WEXITSTATUS(status);
	}
	errno = status;
	free(cmd_args);
}
