#include <stdio.h>

#include "function.h"
#include "board.h"

#include <stdlib.h>
#include <stdbool.h>

FILE *in, *out;

log_t *log_head;
log_t *log_curr;

void open_files()
{
	in = fopen("in.txt", "r");
	out = fopen("out.txt", "r+");

	if ((in == NULL) || (out == NULL)) { exit_program((char *)"Failed open *.txt", 1); }
}

void close_files()
{
	fclose(in);
	fclose(out);
}

void exit_program(char *msg, int code)
{
	printf("%s\n", msg);
	exit(code);
}

void init_log()
{
	log_head = create_log(log_head);
	if (log_head == NULL) exit_program((char *)"Failed to allocate memory", 2);
	log_curr = log_head;
}

log_t *add_log(log_t *st)
{
	log_t *log_next = st->next;
	log_next = create_log(log_next);
	if (log_next == NULL) exit_program((char *)"Failed to allocate memory", 3);
	log_curr->next = log_next;
	return log_curr;
}

void clear_log()
{
	log_t *next = log_head;
	log_curr = log_head;

	while (next != NULL)
	{
		next = log_curr->next;
		free(log_curr);
		log_curr = next;
	}
}

void print_log()
{
	log_t *log_now = log_head;

	while (log_now != NULL)
	{
		fprintf(out, "%s\n", log_now->line);
		log_now = log_now->next;
	}
}

void read_log()
{
	fscanf(in, "%s", log_curr->line);

	if (check_syntax(log_head->line) == false)
	{
		exit_program((char *)"Wrong syntax", 4);
	}

	while (!feof(in))
	{
		log_curr = add_log(log_curr);
		log_curr = log_curr->next;
		fscanf(in, "%s", log_curr->line);

		if (check_syntax(log_head->line) == false)
		{
			exit_program((char *)"Wrong syntax", 5);
		}
	}
}

log_t *create_log(log_t *st)
{
	st = (log_t *)malloc(sizeof(log_t));

	if (st != NULL)
	{
		st->next = NULL;
	}
	else return NULL;

	return st;
}

