#include "editor.h"

/**
 * terminate - prints an error message and exits the program.
 * Uses `perror` to print a descriptive error message based
 * on the global `errno` variable set by the failed C
 * library function.
 * @s: A string - the library function that failed
 */
void terminate(const char *s)
{
	perror(s);
	exit(1);
}
