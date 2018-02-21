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
void test_col_has_no_threes_of_color();
void test_board_has_no_threes();
void test_rows_are_different();
void test_cols_are_different();
void test_board_has_no_duplicates();
void test_solve_three_in_a_row();
void test_solve_three_in_a_col();
void test_solve_balance_row();
void test_solve_balance_column();


// declare more test functions here

int main() {
    test_count_unknown_squares();
    cout << endl;

    test_row_has_no_threes_of_color();
    cout << endl;

    test_col_has_no_threes_of_color();
    cout << endl;

    test_board_has_no_threes();
    cout << endl;
    cout << endl;

    test_rows_are_different();
    cout << endl;

    test_cols_are_different();
    cout << endl;

    test_board_has_no_duplicates();
    cout << endl;

    test_solve_three_in_a_row();
    cout << endl;

    test_solve_three_in_a_col();
    cout << endl;

    test_solve_balance_row();
    cout << endl;

    test_solve_balance_column();
    cout << endl;




    // add your calls to test functions here

    return 0;
}


void test_count_unknown_squares() {
    int board[MAX_SIZE][MAX_SIZE];

    // test case 1
    string test_board_1[] = { "XO-O",
        "--OO",
        "---X",
        "--O-" };
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
    cout << "true, " << row_has_no_threes_of_color(board, 4, 0, RED) << endl;

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

void test_col_has_no_threes_of_color() {
    int board[MAX_SIZE][MAX_SIZE];

    //test case 1
    string test_board_1[] = {
        "XO-O",
        "--OO",
        "---X",
        "--O-" };
    read_board_from_string(board, test_board_1, 4);
    cout << "true, " << col_has_no_threes_of_color(board, 4, 0, RED) << endl;

    string test_board_2[] = {
        "XXX-",
        "--OO",
        "---X",
        "--O-" };
    read_board_from_string(board, test_board_2, 4);
    cout << "true, " << col_has_no_threes_of_color(board, 4, 2, RED) << endl;
    cout << "true, " << col_has_no_threes_of_color(board, 4, 2, BLUE) << endl;

    string test_board_3[] = {
        "XOX-",
        "X-OO",
        "X--X",
        "--O-" };
    read_board_from_string(board, test_board_3, 4);
    cout << "false, " << col_has_no_threes_of_color(board, 4, 0, RED) << endl;

    string test_board_4[] = {
        "XOX-O-",
        "X-OOXX",
        "XXXOOO",
        "--O-XX",
        "--O-XX" ,
        "--O-XX" };
    read_board_from_string(board, test_board_4, 6);
    cout << "false, " << col_has_no_threes_of_color(board, 6, 0, RED) << endl;
    cout << "false, " << col_has_no_threes_of_color(board, 6, 2, BLUE) << endl;




}

void test_board_has_no_threes() {
    int board[MAX_SIZE][MAX_SIZE];

    //test case 1
    string test_board_1[] = {
        "XO-O",
        "--OO",
        "---X",
        "--O-" };
    read_board_from_string(board, test_board_1, 4);
    cout << "true, " << board_has_no_threes(board, 4) << endl;

    string test_board_2[] = {
        "XXX-",
        "--OO",
        "---X",
        "--O-" };
    read_board_from_string(board, test_board_2, 4);
    cout << "false, " << board_has_no_threes(board, 4) << endl;
    cout << "false, " << board_has_no_threes(board, 4) << endl;

    string test_board_3[] = {
        "XOX-",
        "X-OO",
        "X--X",
        "--O-" };
    read_board_from_string(board, test_board_3, 4);
    cout << "false, " << board_has_no_threes(board, 4) << endl;

    string test_board_4[] = {
        "XOX-O-",
        "X-OOXX",
        "XXXOOO",
        "--O-XX",
        "--O-XX" ,
        "--O-XX" };
    read_board_from_string(board, test_board_4, 6);
    cout << "false, " << board_has_no_threes(board, 6) << endl;
    cout << "false, " << board_has_no_threes(board, 6) << endl;

    string test_board_5[] = {
        "XOX-O--O",
        "O-OOXXO-",
        "XOXOXO--",
        "--O-OXOO",
        "----XOXO",
        "--O-XXOX",
        "--------",
        "OXOXOXOX" };
    read_board_from_string(board, test_board_5, 8);
    cout << "true, " << board_has_no_threes(board, 8);

}

void test_rows_are_different() {
    int board[MAX_SIZE][MAX_SIZE];

    // test case 2
    string test_board_1[] = {
        "XXOO",
        "XXOO",
        "----",
        "----" };

    read_board_from_string(board, test_board_1, 4);
    cout << "false, " << rows_are_different(board, 4, 0, 1) << endl;

    string test_board_2[] = {
        "XOXO",
        "XOXO",
        "----",
        "----", };

    read_board_from_string(board, test_board_2, 4);
    cout << "false, " << rows_are_different(board, 4, 0, 1) << endl;

    string test_board_3[] = {
        "XOXO",
        "XOX-",
        "----",
        "----", };

    read_board_from_string(board, test_board_3, 4);
    cout << "true, " << rows_are_different(board, 4, 0, 1) << endl;
    cout << "true, " << rows_are_different(board, 4, 1, 2) << endl;

}

void test_cols_are_different() {
    int board[MAX_SIZE][MAX_SIZE];


    string test_board_1[] = { 
        "OOXO",
        "OO-X",
        "XX-O",
        "OO-X" };

    cout << "return false" << endl;
    read_board_from_string(board, test_board_1, 4);
    cout << cols_are_different(board, 4, 0, 1) << endl;

    string test_board_2[] = { 
        "--XX",
        "--XX",
        "--OO",
        "--OO" };

    cout << "return false" << endl;
    read_board_from_string(board, test_board_2, 4);
    cout << cols_are_different(board, 4, 2, 3) << endl;

    string test_board_3[] = { 
        "--XX",
        "--XX",
        "--OO",
        "--OO" };

    cout << "return true" << endl;
    read_board_from_string(board, test_board_3, 4);
    cout << cols_are_different(board, 4, 0, 1) << endl;

    string test_board_4[] = { 
        "XO--",
        "X---",
        "OOO-",
        "-XOO" };

    cout << "return true" << endl;
    read_board_from_string(board, test_board_4, 4);
    cout << cols_are_different(board, 4, 1, 2) << endl;

}

void test_board_has_no_duplicates() {
    int board[MAX_SIZE][MAX_SIZE];

    // test case

    string test_board_1[] = { 
        "XOXO",
        "XOXO",
        "--X-",
        "----" };

    read_board_from_string(board, test_board_1, 4);
    cout << "false, " << board_has_no_duplicates(board, 4) << endl;

    string test_board_2[] = { 
        "XOX-",
        "XOXO",
        "--X-",
        "O---" };

    read_board_from_string(board, test_board_2, 4);
    cout << "true, " << board_has_no_duplicates(board, 4) << endl;

    string test_board_3[] = { 
        "X-X-",
        "X-XO",
        "O-O-",
        "O-O-" };

    read_board_from_string(board, test_board_3, 4);
    cout << "false, " << board_has_no_duplicates(board, 4) << endl;
}

void test_solve_three_in_a_row() {

    int board[MAX_SIZE][MAX_SIZE];

    // test case 1
    string test_board_1[] = { 
        "XO-O",
        "--OO",
        "---X",
        "--O-" };
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    solve_three_in_a_row(board, 4, 1, true);

    string test_board_2[] = {
        "OX-X",
        "XX--",
        "OO--",
        "-OO-" };
    read_board_from_string(board, test_board_2, size_1);
    solve_three_in_a_row(board, 4, 1, true);
    solve_three_in_a_row(board, 4, 2, true);
    solve_three_in_a_row(board, 4, 3, true);
    solve_three_in_a_row(board, 4, 0, true);


    

}

void test_solve_three_in_a_col() {
    int board[MAX_SIZE][MAX_SIZE];

    // test case 1
    string test_board_1[] = {
        "XO-O",
        "--OO",
        "X--X",
        "--O-" };
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    solve_three_in_a_column(board, 4, 0, true);
    cout << endl;

    string test_board_2[] = {
        "OXOX",
        "--OX",
        "OX--",
        "-OX-" };
    read_board_from_string(board, test_board_2, size_1);
    solve_three_in_a_column(board, 4, 1, true);
    solve_three_in_a_column(board, 4, 2, true);
    solve_three_in_a_column(board, 4, 3, true);
    solve_three_in_a_column(board, 4, 0, true);

    //TESTED


}

void test_solve_balance_row() {
    int board[MAX_SIZE][MAX_SIZE];

    // test case 1
    cout << "testing balance row" << endl;

    string test_board_1[] = {
        "XO-O",
        "--OO",
        "X--X",
        "--O-" };
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    solve_balance_row(board, 4, 1, true); 
    cout << endl;
    solve_balance_row(board, 4, 2, true);
    cout << endl;
    cout << endl;

    string test_board_2[] = {
        "XX-X--",
        "O-OO--",
        "X---XX",
        "-OO--O",
        "--XX-X",
        "------"};
    read_board_from_string(board, test_board_2, 6);
    solve_balance_row(board, 6, 0, true);
    cout << endl;
    solve_balance_row(board, 6, 1, true);
    cout << endl;
    solve_balance_row(board, 6, 2, true);
    cout << endl;
    solve_balance_row(board, 6, 3, true);
    cout << endl;
    solve_balance_row(board, 6, 4, true);
    cout << endl;
    solve_balance_row(board, 6, 5, true);
    cout << endl;
}

void test_solve_balance_column() {
    int board[MAX_SIZE][MAX_SIZE];

    // test case 1
    cout << "testing balance column" << endl;

    string test_board_1[] = {
        "XO-O",
        "--OO",
        "X--X",
        "--O-" };
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    solve_balance_column(board, 4, 0, true);
    cout << endl;
    solve_balance_column(board, 4, 3, true);
    cout << endl;
    cout << endl;

    string test_board_2[] = {
        "XO-XO-",
        "XOXOOX",
        "--X---",
        "XO----",
        "--XXOX",
        "-----X" };
    read_board_from_string(board, test_board_2, 6);
    solve_balance_column(board, 6, 0, true);
    cout << endl;
    solve_balance_column(board, 6, 1, true);
    cout << endl;
    solve_balance_column(board, 6, 2, true);
    cout << endl;
    solve_balance_column(board, 6, 3, true);
    cout << endl;
    solve_balance_column(board, 6, 4, true);
    cout << endl;
    solve_balance_column(board, 6, 5, true);
    cout << endl;
   
    //TESTED

}


void test_board_has_no_duplicates() {
    int board[MAX_SIZE][MAX_SIZE];
    
    // test case
    
    string test_board_1[] = {"XOXO",
                             "XOXO",
                             "--X-",
                             "----"};
    
    read_board_from_string(board, test_board_1, 4);
    cout << board_has_no_duplicates(board, 4) << endl;
    
    string test_board_2[] = {"XOX-",
                             "XOXO",
                             "--X-",
                             "O---"};
    
    read_board_from_string(board, test_board_2, 4);
    cout << board_has_no_duplicates(board, 4) << endl;
}

void test_board_is_solved() {
    int board[MAX_SIZE][MAX_SIZE];
    
    string test_board_1[] = {"XXXO",
                             "O--0",
                             "--X-",
                             "-O--"};
    cout << "false" << endl;
    read_board_from_string(board, test_board_1, 4);
    cout << board_is_solved(board, 4) << endl;
    
    string test_board_2[] = {"XOXO",
                             "XOXO",
                             "--X-",
                             "----"};
    
    cout << "false" << endl;
    read_board_from_string(board, test_board_2, 4);
    cout << board_is_solved(board, 4) << endl;
    
    string test_board_3[] = {"XOXO",
                             "XOOX",
                             "X---",
                             "---O"};
    
    cout << "false" << endl;
    read_board_from_string(board, test_board_3, 4);
    cout << board_is_solved(board, 4) << endl;
    
    string test_board_4[] = {"XOOX",
                             "XOXO",
                             "XXOO",
                             "OOXX"};

    cout << "true" << endl;
    read_board_from_string(board, test_board_4, 4);
    cout << board_is_solved(board, 4) << endl;
    
}


