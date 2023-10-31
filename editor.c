#include "editor.h"

/**
 * main - the main entry point of the program
 *
 * Return: 0
*/
int main(void)
{
	char c;

	/* Entering raw mode - process each keypress as it comes in */

	/* Read 1 char(byte) for stdin - continue as long as a char other than 'q' is read */
	while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q');

	return (0);
}
