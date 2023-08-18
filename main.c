#include "shell.h"

/**
 * main - UNIX command line interpreter
 * @argc: number of arguments supplied
 * @argv: list of arguments supplied
 * @env: list of environment variables
 *
 * Return: 0 (Success)
 */
int main(int argc, char **argv, char **env)
{
	string buffer = NULL;
	int strlen, count, a, i = 1;
	char **args;
	size_t buffer_length;
	pid_t pid;

	while (i)
	{
		if (isatty(STDIN_FILENO) == 0)
		{
			i = 0;
		}
		else
		{
			write(STDOUT_FILENO, PROMPT, sizeof(PROMPT) - 1);
		}
		a = getline(&buffer, &buffer_length, stdin);
		if (a == -1)
		{
			dprintf(STDERR_FILENO, "\nUnable to get input\n");
			exit(ERROR_CODE);
		}
		strlen = _strlen(buffer);
		buffer[strlen - 1] = '\0';
		pid = fork();
		if (pid == 0)
		{
			args = split_string(buffer, ' ', &count);
			execve(args[0], args, env);
			dprintf(STDERR_FILENO, "No such file or directory\n");
			exit(ERROR_CODE);
		}
		wait(NULL);
	}
	return (0);
}
