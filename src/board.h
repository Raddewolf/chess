#ifndef _BOARD_H_
#define _BOARD_H_

#include "function.h"
#include <stdbool.h>

extern char **board;

void init_board();
void fill_board();
void clean_board();
void print_board();
bool in_bounds(char ch, char b1, char b2);
bool check_syntax(char *str);
void make_move(log_t *st);

#endif
