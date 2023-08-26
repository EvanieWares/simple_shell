#include "shell.h"

/**
 * get_path - retrieves the path
 *
 * Return: array of paths
 */
array get_paths(void)
{
	int i = 0;
	string path, temp = NULL;
	array paths = NULL;

	while (environ[i])
	{
		if (_strncmp(environ[i], "PATH=", 5) == 0)
		{
			temp = _strdup(environ[i]);
			break;
		}
		i++;
	}

	if (temp != NULL)
	{
		path = strtok(temp, "=");
		path = strtok(NULL, "=");

		paths = split_string(path, ":");
		free(temp);
	}
	return (paths);
}

string get_full_cmd(string cmd)
{
	int i = 0;
	string path = NULL;
	array paths = get_paths();

	if (paths != NULL)
	{
		while (paths[i])
		{
			path = _concatenate(paths[i], "/", cmd);
			if (access(path, X_OK) == 0)
			{
				free(paths);
				return (path);
			}
			free(path);
			path = NULL;
			i++;
		}
		if (paths != NULL)
		{
			free(paths);
		}
	}

	return (NULL);
}

/**
 * is_command_valid - checks if a command is a valid command
 * @command: command to check
 *
 * Return: 1 if true, 0 if false
 */
int is_command_valid(const string command)
{
	struct stat buffer;

	if (command == NULL || stat(command, &buffer))
	{
		return (0);
	}

	if (buffer.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * valid_cmd - check if the command is valid
 * @cmd: commmand
 *
 * Return: valid command, otherwise NULL
 */
string valid_cmd(string cmd)
{
	string full_cmd;

	if (is_command_valid(cmd))
	{
		return (cmd);
	}
	else
	{
		full_cmd = get_full_cmd(cmd);
		if (is_command_valid(full_cmd))
		{
			return (full_cmd);
		}
		else
		{
			return (NULL);
		}
	}
}
