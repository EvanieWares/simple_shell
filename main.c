#include "shell.h"

/**
 * main - UNIX command line interpreter
 * @argc: number of arguments supplied
 * @argv: list of arguments supplied
 * @envp: list of environment variables
 *
 * Return: 0 (Success)
 */
int main(int argc, array argv, array envp)
{
	string buffer = NULL;
	size_t len = 0;
	string args[2];

	(void) argc;
	while (1)
	{
		_write(PROMPT);

		if (getline(&buffer, &len, stdin) == -1)
		{
			free(buffer);
			break;
		}

		buffer[_strlen(buffer) - 1] = '\0';

		if (fork() == 0)
		{
			args[0] = buffer;
			args[1] = NULL;
			execve(args[0], args, envp);
			perror(argv[0]);
			free(buffer);
			exit(EXIT_FAILURE);
		}
		wait(NULL);
		free(buffer);
		buffer = NULL;
		/*exec_cmd(buffer, info);*/
	}
	return (0);
}
