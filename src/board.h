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
int make_move(log_t *st);
int make_kill(log_t *st);
void turn();
bool check(int h1, int v1, int h2, int v2);

#endif
