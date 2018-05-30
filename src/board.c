#include <stdio.h>

#include "board.h"

#include <stdlib.h>
#include <math.h>

char **board;

void init_board()
{
	board = (char **)malloc(8 * sizeof(char *));

	for (int i = 0; i < 8; ++i)
	{
		board[i] = (char *)malloc(8 * sizeof(char));
		for (int j = 0; j < 8; ++j)
		{
			board[i][j] = ' ';
		}
	}
	fill_board();
}

void fill_board()
{
	for (int i = 0; i < 8; i++)
	{
		board[i][1] = 'P';
		board[i][6] = 'p';
	}

	board[0][0] = 'R';
	board[1][0] = 'N';
	board[2][0] = 'B';
	board[3][0] = 'Q';
	board[4][0] = 'K';
	board[5][0] = 'B';
	board[6][0] = 'N';
	board[7][0] = 'R';
	board[0][7] = 'r';
	board[1][7] = 'n';
	board[2][7] = 'b';
	board[3][7] = 'q';
	board[4][7] = 'k';
	board[5][7] = 'b';
	board[6][7] = 'n';
	board[7][7] = 'r';
}

void clean_board()
{
	for (int i = 0; i < 8; i++)
	{
		free(board[i]);
	}
	free(board);

	board = NULL;
}

void print_board()
{
	for (int i = 7; i >= -1; i--)
	{
		fprintf(out, "  ---------------------------------\n");

		for (int j = 8; j > -1; j--)
		{
			if (j > 7 && i < 0)
			{
				fprintf(out, "   ");
			}
			else  if (j > 7)
			{
				fprintf(out, "%d |", i + 1);
			}
			else if (i < 0)
			{
				fprintf(out, " %c  ", 'H' - j);
			}
			else
			{
				fprintf(out, " %c |", board[7 - j][i]);
			}

		}

		fprintf(out, "\n");
	}
}

bool in_bounds(char ch, char b1, char b2)
{
	return ((b1 <= ch) && (ch <= b2));
}

bool check_syntax(char *str)
{
	return ((in_bounds(str[0], 'a', 'h')) &&
		(in_bounds(str[1], '1', '8')) &&
		((str[2] == '-') || (str[2] == 'x')) &&
		(in_bounds(str[3], 'a', 'h')) &&
		(in_bounds(str[4], '1', '8')));
}

int make_move(log_t *st)
{
	bool allow;
	int h1 = (int)(st->line[0] - 'a');
	int h2 = (int)(st->line[3] - 'a');
	int v1 = (int)(st->line[1] - '1');
	int v2 = (int)(st->line[4] - '1');

	allow = check(h1, v1, h2, v2);

	if (allow == false) { return 0; }

	if (board[h2][v2] == ' ')
	{
		board[h2][v2] = board[h1][v1];
		board[h1][v1] = ' ';
	}
	else return 0;

	return 1;
}

int make_kill(log_t *st)
{
	bool allow;
	int h1 = (int)(st->line[0] - 'a');
	int h2 = (int)(st->line[3] - 'a');
	int v1 = (int)(st->line[1] - '1');
	int v2 = (int)(st->line[4] - '1');

	allow = check(h1, v1, h2, v2);

	if (allow == false) { exit_program((char *)"Wrong turn\n", 8); }

		if (board[h2][v2] != ' ')
	{
		board[h2][v2] = board[h1][v1];
		board[h1][v1] = ' ';
	}
	else return 0;

	return 1;
}

void turn()
{
	log_t *turn;

	turn = log_head;

	while (turn != NULL)
	{
		if (turn->line[2] == '-')
		{
			make_move(turn);
		}
		else if (turn->line[2] == 'x')
		{
			make_kill(turn);
		}

		turn = turn->next;
	}
}

bool check(int h1, int v1, int h2, int v2)
{
	if ((board[h1][v1] == 'p') || (board[h1][v1] == 'P'))
	{
		int difh = fabs(h2 - h1);
		int difv = fabs(v2 - v1);

		if (difh != 0) { return false; }

		if ((v2 > v1) && (board[h1][v1] == 'p')) { return false; }
		if ((v2 < v1) && (board[h1][v1] == 'P')) { return false; }

		if ((board[h1][v1] == 'P') && (v1 == 1) && (difv <= 2)) { return true; }
		else if ((board[h1][v1] == 'p') && (v1 == 6) && (difv <= 2)) { return true; }


		if ((board[h1][v1] == 'P') && (v1 != 1) && (difv == 1)) { return true; }
		else return false;


		if ((board[h1][v1] == 'p') && (v1 != 6) && (difv == 1)) { return true; }
		else return false;
	}

	return true;
}

