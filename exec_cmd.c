#include "shell.h"

/**
 * print_env - prints the environment variables
 * @envp: environment variables to print
 */
void print_env(array envp)
{
	int i = 0;

	while (envp[i]	!= NULL)
	{
		_write(envp[i]);
		_write("\n");
		i++;
	}
}

/**
 * cmd_exist - checks if the command exist
 * @path: array of paths
 * @args: array containing the command and its arguments
 *
 * Return: true of command exist, otherwise false
 */
bool cmd_exist(char **path, char **args)
{
	string full_cmd, cmd = args[0];
	int i, cmd_len = _strlen(cmd);

	if (access(cmd, F_OK) == 0)
	{
		return (true);
	}
	for (i = 0; path[i] != NULL; i++)
	{
		int path_len = _strlen(path[i]);

		full_cmd = malloc((path_len + cmd_len + 2) * sizeof(char));
		if (full_cmd == NULL)
		{
			perror("malloc");
			exit(errno);
		}
		_strcpynn(full_cmd, path[i], 0, 0);
		full_cmd[path_len++] = '/';
		_strcpynn(full_cmd, cmd, path_len, 0);
		full_cmd[path_len + cmd_len] = '\0';
		if (access(full_cmd, F_OK) == 0)
		{
			free(args[0]);
			args[0] = full_cmd;
			return (true);
		}
		else
		{
			free(full_cmd);
		}
	}
	return (false);
}

/**
 * is_inbuilt - check and execute command if it's inbult
 * @args: array containing the command and arguments
 * @info: a structure
 *
 * Return: true if it's inbuilt, otherwise false
 */
bool is_inbuilt(array args, info_t info)
{
	if (_strcmp(args[0], "exit") == 0)
	{
		exit(0);
	}
	if (_strcmp(args[0], "env") == 0)
	{
		print_env(info.envp);
		return (true);
	}
	if (_strcmp(args[0], "cd") == 0)
	{
		if (chdir(args[1]) != 0)
		{
			perror(info.program_name);
		}
		return (true);
	}
	return (false);
}

/**
 * exec_cmd - execute the command
 * @buffer: a string containing the command
 * @info: a structure containing program info
 */
void exec_cmd(string buffer, info_t info)
{
	pid_t pid;
	array args = split_string(buffer, ' ');
	array path = split_string(getenv("PATH"), ':');

	if (is_inbuilt(args, info))
	{
		return;
	}
	if (cmd_exist(path, args))
	{
		pid = fork();
		if (pid == 0)
		{
			execve(args[0], args, info.envp);
		}
		wait(NULL);
	}
	else
	{
		perror(info.program_name);
	}
}
