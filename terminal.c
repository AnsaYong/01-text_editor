#include "editor.h"
#include <termios.h>    /* Definitions and functions for terminal I/O */

/**
 * struct termios - Stores the terminal attributes
 */
struct termios orig_termios;	/* Global variable */

/**
 * disable_raw_mode - Resets the original terminal settings
 * at the end of the program.
 */
void disable_raw_mode(void)
{
	int n;	/* To check the return value for error handling */

	n = tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
	if (n == -1)
		terminate("tcsetattr");
}

/**
 * enable_raw_mode - configures the terminal to operate in raw mode i.e.
 * the terminal provides minimal input processing, echoing, or line buffering.
 * This is achieved by turning off several flags.
 * This is necessary in an interactive program like a text editor.
 */
void enable_raw_mode(void)
{
	int n;  /* To check the return value for error handling */
	struct termios raw;        /* Declare `struct termios` variable, `raw` */

	n = tcgetattr(STDIN_FILENO, &orig_termios);  /* Current terminal attrs */
	if (n == -1)
		terminate("tcgetattr");

	atexit(disable_raw_mode);	/* Register function to be called at exit */
	raw = orig_termios;						 /* Copy attributes to `raw` */

	/* Use bitwise-NOT and -AND to TURN OFF several `local flags` in c_lflag */
	/* ECHO - display character entered on stdin */
	/* ICANON - canonical mode (where input is read line-by-line) */
	/* ISIG - ctrl-C and ctrl-D terminating/suspending process */
	/* IXON - ctrl-S and ctrl-Q */
	/* IEXTEN - ctrl-V and ctrl-o in macOS */
	/* ICRNL - ctrl-M */
	/* OPOST - all output processing, in this case, "\n" to "\r\n" */
	raw.c_lflag &= ~(ICRNL | IXON | BRKINT | INPCK | ISTRIP);
	raw.c_lflag &= ~(OPOST);
	raw.c_lflag |= (CS8);
	raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
	raw.c_cc[VMIN] = 0;	/* Set min # of input bytes before read() can return */
	raw.c_cc[VTIME] = 1;	/* read() waits for 1/10 of a sec and returns */

	n = tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);	/* Update terminal changes */
	if (n == -1)
		terminate("tcsetattr");
}
