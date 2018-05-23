#include <stdio.h>

#include "board.h"
#include "function.h"

int main()
{
	log_t *turn;

	open_files();

	init_log();
	init_board();

	read_log();

	print_log();

	turn = log_head;

	while (turn != NULL)
	{
		make_move(turn);
		turn = turn->next;
	}

	print_board();

	clear_log();
	close_files();

    return 0;
}
