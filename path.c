#include "shell.h"

/**
 * get_path - gets the path from the environment variables
 *
 * Return: path
 */
string get_path(void)
{
	int i = 0;
	string temp = NULL;
	string temp1 = NULL;
	string paths = NULL;

	while (environ[i])
	{
		if (_strncmp(environ[i], "PATH=", 5) == 0)
		{
			temp = _strdup(environ[i]);
			temp1 = strtok(temp, "=");
			temp1 = strtok(NULL, "\n");
			paths = _strdup(temp1);
			free(temp);
			break;
		}
		i++;
	}

	return (paths);
}

/**
 * get_dirs - gets directories from the path
 *
 * Return: array of directories
 */
array get_dirs(void)
{
	array dirs = NULL;
	string paths = get_path();

	if (paths != NULL)
	{
		dirs = split_string(paths, ":\n");
		free(paths);
	}
	return (dirs);
}

/**
 * search_path - searches for the command in the directories listed in PATH
 * @cmd: command to search for
 *
 * Return: full path to the command if found, NULL otherwise
 */
string search_path(string cmd)
{
	string dir;
	array dirs = get_dirs();
	int i;

	if (dirs == NULL)
	{
		return (NULL);
	}

	for (i = 0; dirs[i] != NULL; i++)
	{
		dir = malloc(sizeof(char) * (_strlen(dirs[i]) + _strlen(cmd) + 2));
		if (dir == NULL)
		{
			free_array(dirs);
			return (NULL);
		}

		/* Combine directory and command name */
		_strcpy(dir, dirs[i]);
		_strcat(dir, "/");
		_strcat(dir, cmd);

		/* Check if the file exists and is executable */
		if (access(dir, X_OK) == 0)
		{
			free_array(dirs);
			return (dir);
		}
		free(dir);
	}

	free_array(dirs);
	return (NULL);
}
