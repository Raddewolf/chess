#define CTEST_MAIN

#include <function.h>
#include <board.h>

#include <ctest.h>
#include <string.h>

CTEST(Syntax, CorrectSyntaxCheck)
{
	int result = check_syntax("e2-e4");
	int expected = 1;
	ASSERT_EQUAL(expected,result);
}

CTEST(Syntax, IncorrectSyntaxCheck)
{
	int result = check_syntax("k9q64");
	int expected = false;
	ASSERT_EQUAL(expected,result);
}

CTEST(MovePawn0, Correct)
{
	log_t st;
	strcpy(st.line, "e2-e4");
	int result = make_move(&st);
	int expected = 1;
	ASSERT_EQUAL(expected,result);
}

CTEST(MovePawn1, Correct)
{
        log_t st;
        strcpy(st.line, "e7-e5");
        int result = make_move(&st);
        int expected = 1;
        ASSERT_EQUAL(expected,result);
}

CTEST(KillPawn, Correct)
{
        log_t st;
        strcpy(st.line, "e4xe5");
        int result = make_kill(&st);
        int expected = 1;
        ASSERT_EQUAL(expected,result);
}

CTEST(MovePawn2, Incorrect)
{
        log_t st;
        strcpy(st.line, "e5-e4");
        int result = make_move(&st);
        int expected = 0;
        ASSERT_EQUAL(expected,result);
}

CTEST(MovePawn3, Incorrect)
{
        log_t st;
	strcpy(st.line, "e5-e7");
        int result = make_move(&st);
        int expected = 0;
        ASSERT_EQUAL(expected,result);
}

CTEST(MoveKnight, Correct)
{
        log_t st;
	strcpy(st.line, "b1-c3");
        int result = make_move(&st);
        int expected = 1;
        ASSERT_EQUAL(expected,result);
}

CTEST(MoveBishop, Correct)
{
        log_t st;
	strcpy(st.line, "f8-c5");
        int result = make_move(&st);
        int expected = 1;
        ASSERT_EQUAL(expected,result);
}

CTEST(MoveRook, Correct)
{
        log_t st;
	strcpy(st.line, "h1-h6");
        int result = make_move(&st);
        int expected = 1;
        ASSERT_EQUAL(expected,result);
}

int main(int argc, const char** argv)
{
	init_board();
	int test_res = ctest_main(argc, argv);
	clean_board();
	return test_res;
}

