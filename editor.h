#ifndef EDITOR_H
#define EDITOR_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <termios.h>
#include <ctype.h>
#include <errno.h>

/***** DATA AND DATA TYPES *****/

#define MAX_LINE 1024

/**
 * struct line_s - stores lines from a file
 * @line: character array to store chars from a line of text
 * @next: pointer to the next node
 * @prev: pointer to the previous node
*/
typedef struct line_s
{
	char line[MAX_LINE];
	struct line_s *next;
	struct line_s *prev;
} line_t;

/***** FUNCTION PROTOTYPES *****/
/***** terminal.c ******/
void disable_raw_mode(void);
void enable_raw_mode(void);

/*** error_handling.c ***/
void terminate(const char *s);

#endif /* EDITOR_H */
