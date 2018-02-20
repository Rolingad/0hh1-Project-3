/**
 * test.cpp
 *
 * EECS 183
 * Project 3: 0h h1 Test Suite
 * Winter 2018
 *
 * <#Name(s)#>
 * <#uniqname(s)#>
 *
 * <#A description of the project here#>
 */

#include <iostream>
#include "utility.h"
#include "ohhi.h"

void test_count_unknown_squares();
void test_rows_are_different();

int main() {

    test_count_unknown_squares();
    test_rows_are_different();
    
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
  
    }
    
void test_rows_are_different() {
    int board[MAX_SIZE][MAX_SIZE];
    
    // test case 2
    string test_board_1[] = {"XXOO"
                             "XXOO"
                             "----"
                             "----"};
    
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << rows_are_different(board, size_1, 0, 1);
    
    string test_board_2[] = {"XOXO"
                             "XOXO"
                             "----"
                             "----"};
    
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << rows_are_different(board, size_2, 0, 1);
    
}











