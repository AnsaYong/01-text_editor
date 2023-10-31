#include <stdio.h>
#include <unistd.h>

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
