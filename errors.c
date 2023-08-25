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
	_write(pg_name);
	_write(": ");
	_write(process);
	_write(": ");
	_write(cmd_name);
	_write(": not found\n");
}
