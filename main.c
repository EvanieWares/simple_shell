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
	info_t info;
	string buffer;
	int i = 1;
	bool pipped = false;

	(void) argc;
	info.program_name = argv[0];
	info.envp = envp;
	while (i && !pipped)
	{
		info.process_no = i;
		if (isatty(STDIN_FILENO) == 0)
		{
			pipped = true;
		}
		else
		{
			_write(PROMPT);
		}
		buffer = get_buf();
		exec_cmd(buffer, info);
		free(buffer);
		i++;
	}
	return (0);
}

