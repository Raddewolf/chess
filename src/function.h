#ifndef _FUNCTION_H_
#define _FUNCTION_H_

			  //-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
typedef struct log {      // Listnode created to do more than one turn
	char line[8];     // Line with data of turn
	struct log *next; //
} log_t;                  //-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

extern FILE *in, *out;
extern log_t *log_head;
extern log_t *log_curr;

void open_files();
void close_files();
void exit_program(char *msg, int code);
log_t *create_log(log_t *st);
void init_log();
log_t *add_log(log_t *st);
void clear_log();
void print_log();
void read_log();

#endif
