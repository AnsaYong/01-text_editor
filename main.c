#include "editor.h"

/**
 * main - the main entry point of the program
 *
 * Return: 0
*/
int main(void)
{
	char c;	/* To store the user's input character */
	int n;  /* To check the return value for error handling */

	/* Enter raw mode */
	enable_raw_mode();

	/* Read 1 char(byte) from stdin - stop when 'q' is read */
	while (1)
	{
		c = '\0';
		n = read(STDIN_FILENO, &c, 1);
		if (n == -1 && errno != EAGAIN)
			terminate("read");
		if (iscntrl(c))	/* check if input is a control character or not */
		{
			printf("%d\r\n", c);
		}
		else
		{
			printf("%d ('%c')\r\n", c, c);
		}
		if (c == 'q')
			break;
	}

	return (0);
}
