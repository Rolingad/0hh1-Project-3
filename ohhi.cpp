/**
 * ohhi.cpp
 *
 * EECS 183
 * Project 3: 0h h1
 * Winter 2018
 *
 * <#Name(s)#>
 * <#uniqname(s)#>
 *
 * <#A description of the project here#>
 */

#include <iostream>
#include <cctype>
#include "utility.h"
#include "ohhi.h"

/**
 * --------------------------------------------------------
 * ---------- UTILITY FUNCTIONS ---------------------------
 * --------------------------------------------------------
 */

int count_unknown_squares(const int board[MAX_SIZE][MAX_SIZE], int size) {
    int numUnknown = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
        {
            if (board[i][j] == 0) {
                numUnknown += 1;
        }

        }
        
    }
    return numUnknown; //TESTED
}


/**
 * --------------------------------------------------------
 * --------- VALIDITY CHECKING FUNCTIONS ------------------
 * --------------------------------------------------------
 */

bool row_has_no_threes_of_color(const int board[MAX_SIZE][MAX_SIZE],
                                int size,
                                int row,
                                int color) {
    bool ThreeOrNot = true;
    int redCounter = 0;
    int blueCounter = 0;

    if (size == 2) {
        return true;
    }

    //red
    if (color == RED) {
        int i = row;
        //iterate through columns in row
            for (int j = 0; j < size - 2; j++) {
                if (ThreeOrNot == true) {
                    if ((board[i][j] == 1) && (board[i][j + 1] == 1) && (board[i][j + 2] == 1)) {
                        ThreeOrNot = false;
                    }
                    else {
                        ThreeOrNot = true;
                    }
                }
            }
        
    }

    //blue
    if (color == BLUE) {
        int i = row;
        //iterate through columns in row
        
            for (int j = 0; j < size - 2; j++) {
                if (ThreeOrNot == true) {

                    if ((board[i][j] == 2) && (board[i][j + 1] == 2) && (board[i][j + 2] == 2)) {

                        ThreeOrNot = false;
                    }
                    else {
                        ThreeOrNot = true;
                    }
                }
            }
       
    }
    return ThreeOrNot;
    //TESTED THANK GOD OMG THAT TOOK SO LONG FUCKING SHIT
}

bool col_has_no_threes_of_color(const int board[MAX_SIZE][MAX_SIZE],
                                int size,
                                int col,
                                int color) {
    bool ThreeOrNot = true;
    int redCounter = 0;
    int blueCounter = 0;

    if (size == 2) {
        return true;
    }

    //red
    if (color == RED) {
        int i = col;
        //iterate through rows in col
        for (int j = 0; j < size - 2; j++) {
            if (ThreeOrNot == true) {
                if ((board[j][i] == 1) && (board[j + 1][i] == 1) && (board[j + 2][i] == 1)) {
                    ThreeOrNot = false;
                }
                else {
                    ThreeOrNot = true;
                }
            }
        }
    }

    //blue
    if (color == BLUE) {
        int i = col;
        //iterate through columns in row
        for (int j = 0; j < size - 2; j++) {
            if (ThreeOrNot == true) {
                if ((board[j][i] == 2) && (board[j + 1][i] == 2) && (board[j + 2][i] == 2)) {
                    ThreeOrNot = false;
                }
                else {
                    ThreeOrNot = true;
                }
            }
        }
    }
    return ThreeOrNot;
    //TESTED
}

bool board_has_no_threes(const int board[MAX_SIZE][MAX_SIZE], int size) {
    //if color is red row
    bool ThreeInRow = true;
    bool ThreeInCol = true;

    for (int row = 0; row < size; row++) {
        if (ThreeInRow == true) {
            if ((row_has_no_threes_of_color(board, size, row, RED))) {
                ThreeInRow = true;
            }
            else {
                ThreeInRow = false;
            }
        }
    }
    //if color is blue row
    for (int row = 0; row < size; row++) {
        if (ThreeInRow == true) {
            if ((row_has_no_threes_of_color(board, size, row, BLUE))) {
                ThreeInRow = true;
            }
            else {
                ThreeInRow = false;
            }
        }
    }
    //if color is RED col
    for (int col = 0; col < size; col++) {
            if (ThreeInCol == true) {
                if ((col_has_no_threes_of_color(board, size, col, RED))) {
                    ThreeInCol = true;
                }
                else {
                    ThreeInCol = false;
                }
            }
        }
    //if color is BLUE col
    for (int col = 0; col < size; col++) {
        if (ThreeInCol == true) {
            if ((col_has_no_threes_of_color(board, size, col, BLUE))) {
                ThreeInCol = true;
            }
            else {
                ThreeInCol = false;
            }
        }
    }
    if (ThreeInCol == true && ThreeInRow == true) {
        return true;
    }
    else {
        return false;
    }
    //TESTED
}

bool rows_are_different(const int board[MAX_SIZE][MAX_SIZE],
                        int size,
                        int row1,
                        int row2) {
    bool isRowDiff = true;
    int rowCounter = 0;
    int col = 0;

    for (col = 0; col < size; col++) {
        if (board[row1][col] == 0 || board[row2][col] == 0) {
            return true;
        }
    }

    for (col = 0; col < size; col++) {
        if (board[row1][col] == board[row2][col]) {
            rowCounter += 1;
        }
    }
    
    if (rowCounter == size) {
        isRowDiff = false;
    }
    else {
        isRowDiff = true;
    }



    return isRowDiff;
    //TESTED
}

bool cols_are_different(const int board[MAX_SIZE][MAX_SIZE],
                        int size,
                        int col1,
                        int col2) {
    bool isColDiff = true;
    int colCounter = 0;
    int row = 0;

    for (row = 0; row < size; row++) {
        if (board[row][col1] == 0 || board[row][col2] == 0) {
            return true;
        }
    }

    for (row = 0; row < size; row++) {
        if (board[row][col1] == board[row][col2]) {
            colCounter += 1;
        }
    }

    if (colCounter == size) {
        isColDiff = false;
    }
    else {
        isColDiff = true;
    }



    return isColDiff;
    //TESTED
}

bool board_has_no_duplicates(const int board[MAX_SIZE][MAX_SIZE], int size) {
    bool NoColDups = true;
    bool NoRowDups = true;


    //rows
    for (int row1 = 0; row1 < size; row1++) {
        for (int row2 = row1 + 1; row2 < size; row2++) {
            if (NoRowDups == true) {
                if (rows_are_different(board, size, row1, row2) == true) {
                    NoRowDups = true;
                }
                else {
                    NoRowDups = false;
                }
            }
        }
    }
    
    //cols
    for (int col1 = 0; col1 < size; col1++) {
        for (int col2 = 0; col2 < size; col2++) {
            if (NoColDups == true) {
                if (cols_are_different(board, size, col1, col2) == true) {
                    NoColDups = true;
                }
                else {
                    NoColDups = false;
                }
            }
        }
    }

    if (NoColDups == true && NoRowDups == true) {
        return true;
    }
    else {
        return false;
    }
    //TESTED (mostly)

}


/**
 * --------------------------------------------------------
 * ---------- SOLVING FUNCTIONS ---------------------------
 * --------------------------------------------------------
 */

void solve_three_in_a_row(int board[MAX_SIZE][MAX_SIZE],
                          int size,
                          int row,
                          bool announce) {
    // write your code here

    return;
}

void solve_three_in_a_column(int board[MAX_SIZE][MAX_SIZE],
                             int size,
                             int col,
                             bool announce) {
    // write your code here

    return;
}


void solve_balance_row(int board[MAX_SIZE][MAX_SIZE],
                       int size,
                       int row,
                       bool announce) {
    // write your code here

    return;
}

void solve_balance_column(int board[MAX_SIZE][MAX_SIZE],
                          int size,
                          int col,
                          bool announce) {
    // write your code here

    return;
}


/**
 * --------------------------------------------------------
 * ---------- GAMEPLAY FUNCTIONS --------------------------
 * --------------------------------------------------------
 */

bool board_is_solved(const int board[MAX_SIZE][MAX_SIZE], int size) {
    // write your code here

    // replace this return statement
    return false;
}

bool check_valid_input(int size, int row_input, char col_input,
                       char color_char, int &row, int &col) {
    // write your code here

    // replace this return statement
    return false;
}

bool check_valid_move(const int original_board[MAX_SIZE][MAX_SIZE],
                      const int current_board[MAX_SIZE][MAX_SIZE],
                      int size, int row, int col, int color) {
    // write your code here

    // replace this return statement
    return false;
}


/**
 * --------------------------------------------------------
 * ---------------- S'MORES FUNCTIONS    ------------------
 * ---------- DO NOT DELETE THESE FUNCTIONS ---------------
 * ------------- FOR THE REGULAR PROJECT ------------------
 * --------------------------------------------------------
 */

void solve_lookahead_row(int board[MAX_SIZE][MAX_SIZE],
                         int size,
                         int row,
                         bool announce) {
    // write your code here

    return;
}

void solve_lookahead_column(int board[MAX_SIZE][MAX_SIZE],
                            int size,
                            int col,
                            bool announce) {
    // write your code here
    return;
}
