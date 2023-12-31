#include "shell.h"

/**
 * _print_error - prints errors to stdin
 * @pg_name: program name
 * @cmd_name: command name
 * @process_no: process number
 */
void _print_error(string pg_name, string cmd_name, int process_no)
{
	char process[4];

	num_to_string(process, process_no);
	_ewrite(pg_name);
	_ewrite(": ");
	_ewrite(process);
	_ewrite(": ");
	_ewrite(cmd_name);
	_ewrite(": not found\n");
}

/**
 * _print_atoi_error - prints errors to stdin
 * @pg_name: program name
 * @cmd_args: array of user command and arguments
 * @process_no: process number
 */
void _print_atoi_error(string pg_name, array cmd_args, int process_no)
{
	char process[4];

	num_to_string(process, process_no);
	_ewrite(pg_name);
	_ewrite(": ");
	_ewrite(process);
	_ewrite(": ");
	_ewrite(cmd_args[0]);
	_ewrite(": Illegal number: ");
	_ewrite(cmd_args[1]);
	_ewrite("\n");
}
