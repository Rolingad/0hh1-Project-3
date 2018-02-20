/**
 * test.cpp
 *
 * EECS 183
 * Project 3: 0h h1 Test Suite
 * Winter 2018
 *
 * <#Nathan Fialkoff and Mary Reiber#>
 * <#npfialk#>
 *
 * <#A description of the project here#>
 */

#include <iostream>
#include "utility.h"
#include "ohhi.h"

void test_count_unknown_squares();
void test_row_has_no_threes_of_color();

// declare more test functions here

int main() {
    test_count_unknown_squares();
    cout << endl;

    test_row_has_no_threes_of_color();
    cout << endl;

   // test_col_has_no_threes_of_color();
    cout << endl;

    // add your calls to test functions here

    return 0;
}


void test_count_unknown_squares() {
    int board[MAX_SIZE][MAX_SIZE];

    // test case 1
    string test_board_1[] = {"XO-O",
                             "--OO",
                             "---X",
                             "--O-"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << count_unknown_squares(board, size_1) << endl;

    // add more tests here
}

void test_row_has_no_threes_of_color() {
    int board[MAX_SIZE][MAX_SIZE];

    //test case 1
    string test_board_1[] = { "XO-O",
        "--OO",
        "---X",
        "--O-" };
    read_board_from_string(board, test_board_1, 4);
    cout << "true, " << row_has_no_threes_of_color(board,4, 0, RED) << endl;

    string test_board_2[] = { "XXX-",
        "--OO",
        "---X",
        "--O-" };
    read_board_from_string(board, test_board_2, 4);
    cout << "false, " << row_has_no_threes_of_color(board, 4, 0, RED) << endl;
    cout << "true, " << row_has_no_threes_of_color(board, 4, 0, BLUE) << endl;

    string test_board_3[] = { "XOX-",
        "X-OO",
        "X--X",
        "--O-" };
    read_board_from_string(board, test_board_3, 4);
    cout << "true, " << row_has_no_threes_of_color(board, 4, 2, BLUE) << endl;

    string test_board_4[] = { "XOX-O-",
        "X-OOXX",
        "XXXOOO",
        "--O-XX",
        "--O-XX" ,
        "--O-XX" };
    read_board_from_string(board, test_board_4, 6);
    cout << "false, " << row_has_no_threes_of_color(board, 6, 2, BLUE) << endl;
    cout << "false, " << row_has_no_threes_of_color(board, 6, 2, RED) << endl;



    
}

// define more test functions here
