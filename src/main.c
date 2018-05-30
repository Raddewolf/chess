#include <stdio.h>

#include "board.h"
#include "function.h"

int main()
{
	open_files();

	init_log();
	init_board();

	read_log();

	print_log();

	turn();

	print_board();

	clear_log();
	close_files();
	clean_board();

	return 0;
}
