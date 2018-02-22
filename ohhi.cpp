/**
* ohhi.cpp
*
* EECS 183
* Project 3: 0h h1
* Winter 2018
*
* <#Nathan Fialkoff and Mary Reiber#>
* <#npfialk reiberm#>
*
* <#Project three, 0hh1, a logic puzzle game with red and blue dots#>
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

// Counts the number of unknown squares in a board
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
    return numUnknown;
    //TESTED
}

// Ensures that a row does not have three moves next to each other in succession 
bool row_has_no_threes_of_color(const int board[MAX_SIZE][MAX_SIZE],
    int size,
    int row,
    int color) {
    bool ThreeOrNot = true;


    if (size == 2) {
        return true;
    }

    // Checking red
    int i = row;

    //iterate through the columns in a row
    for (int j = 0; j < size - 2; j++) {
        if (ThreeOrNot == true) {
            if ((board[i][j] == color) && (board[i][j + 1] == color) && (board[i][j + 2] == color)) {
                ThreeOrNot = false;
            }
            else {
                ThreeOrNot = true;
            }
        }
    }
    return ThreeOrNot;
}

// Ensures that any column does not have three of the same move next to each other in succession 
bool col_has_no_threes_of_color(const int board[MAX_SIZE][MAX_SIZE],
    int size,
    int col,
    int color) {
    bool ThreeOrNot = true;


    if (size == 2) {
        return true;
    }

    // Checking Red
    if (color == RED) {
        int i = col;
        // Iterate through the rows in a column
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

    // Checking blue
    if (color == BLUE) {
        int i = col;
        // Iterate through the columns in a row
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

    if (color == UNKNOWN) {
        int i = col;
        // Iterate through the columns in a row
        for (int j = 0; j < size - 2; j++) {
            if (ThreeOrNot == true) {
                if ((board[j][i] == 0) && (board[j + 1][i] == 0) && (board[j + 2][i] == 0)) {
                    ThreeOrNot = false;
                }
                else {
                    ThreeOrNot = true;
                }
            }
        }
    }
    return ThreeOrNot;
}

// Ensures that a row or column does not have any three moves consecutively in a line
bool board_has_no_threes(const int board[MAX_SIZE][MAX_SIZE], int size) {
    // If the color is red row
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
    // If the color is blue row
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
    // If the color is RED column
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
    // If the color is BLUE column
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
}

// Used in order to make sure that the two rows are not exactly the same if they are complete
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
}

// Verifies that no two columns given are exactly the same if they are complete
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
}

// Makes sure that no two rows or columns are the same if they are complete
bool board_has_no_duplicates(const int board[MAX_SIZE][MAX_SIZE], int size) {
    bool NoColDups = true;
    bool NoRowDups = true;


    // In order to verify rows
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

    // In order to verify columns
    for (int col1 = 0; col1 < size; col1++) {
        for (int col2 = col1 + 1; col2 < size; col2++) {
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
}

/**
* --------------------------------------------------------
* ---------- SOLVING FUNCTIONS ---------------------------
* --------------------------------------------------------
*/

// Ensures that when there are two of one move in a row, the input does not violate the rules of the game
void solve_three_in_a_row(int board[MAX_SIZE][MAX_SIZE],
    int size,
    int row,
    bool announce) {
    int col = 0;

    if (size == 2) {
        return;
    }
    // Checking two in a row 
    for (col = 0; col < size /* - 2? */; col++) {
        for (col = 0; col < size /* - 2? */; col++) {
            if ((board[row][col] == RED) && board[row][col + 1] == RED) {
                if (col == 0 && board[row][col + 2] == UNKNOWN) { 
                    mark_square_as(board, size, row, col + 2, BLUE, announce);

                }
                else if (col == size - 1 && (board[row][col - 2] == UNKNOWN)) {
                    mark_square_as(board, size, row, col - 2, BLUE, announce);
                }

                else if (col == size - 2 && (board[row][col - 1] == UNKNOWN)) {
                    mark_square_as(board, size, row, col - 1, BLUE, announce);
                }
                else {
                    if (board[row][col + 2] == UNKNOWN) {
                        mark_square_as(board, size, row, col + 2, BLUE, announce);
                    }
                    if (board[row][col - 1] == UNKNOWN) {
                        
                        mark_square_as(board, size, row, col - 1, BLUE, announce);
                    }
                }

            }

            else if ((board[row][col] == BLUE) && board[row][col + 1] == BLUE) {
                if (col == 0 && (board[row][col + 2] == UNKNOWN)) { //add marking spot must be equal to unknown
                    mark_square_as(board, size, row, col + 2, RED, announce);

                }
                else if (col == size - 1 && (board[row][col - 2] == UNKNOWN)) {
                    mark_square_as(board, size, row, col - 2, RED, announce);
                }

                else if (col == size - 2 && (board[row][col - 1] == UNKNOWN)) {
                    mark_square_as(board, size, row, col - 1, RED, announce);
                }
                else {
                    if (board[row][col + 2] == UNKNOWN) {
                        mark_square_as(board, size, row, col + 2, RED, announce);
                    }
                    if (board[row][col - 1] == UNKNOWN) {
                        
                        mark_square_as(board, size, row, col - 1, RED, announce);
                    }
                }


            }

            // If the two moves are separate red
            else if (((board[row][col] == BLUE) && board[row][col + 2] == BLUE) 
                && (board[row][col + 1] == UNKNOWN)) {
                mark_square_as(board, size, row, col + 1, RED, announce);

            }

            //If the two moves are separate blue
            else if (((board[row][col] == RED) && board[row][col + 2] == RED) 
                && (board[row][col + 1] == UNKNOWN)) {
                mark_square_as(board, size, row, col + 1, BLUE, announce);

            }



        }
    }
}

// Ensures that when there are two of one move in a column, the input does not violate the rules of the game
void solve_three_in_a_column(int board[MAX_SIZE][MAX_SIZE],
    int size,
    int col,
    bool announce) {
    int row = 0;

    if (size == 2) {
        return;
    }
    //Checking two moves in row
    for (row = 0; row < size /* - 2? */; row++) {
    for (row = 0; row < size /* - 2? */; row++) {
        if ((board[row][col] == RED) && board[row + 1][col] == RED) {
            if ((row == 0) && (board[row + 2][col] == UNKNOWN)) {
                mark_square_as(board, size, row + 2, col, BLUE, announce);

            }
            else if ((row == size - 1) && (board[row - 2][col] == UNKNOWN)) {
                mark_square_as(board, size, row - 2, col, BLUE, announce);
            }

            else if (row == size - 2 && (board[row - 1][col] == UNKNOWN)) {
                mark_square_as(board, size, row - 1, col, BLUE, announce);
            }
            else {
                if ((board[row + 2][col] == UNKNOWN)) {
                    mark_square_as(board, size, row + 2, col, BLUE, announce);
                }
                if ((board[row - 1][col] == UNKNOWN)) {
                    
                    mark_square_as(board, size, row - 1, col, BLUE, announce);
                }
            }

        }

        else if ((board[row][col] == BLUE) && board[row + 1][col] == BLUE) {
            if (row == 0 && (board[row + 2][col] == UNKNOWN)) {
                mark_square_as(board, size, row + 2, col, RED, announce);

            }
            else if (row == size - 1 && (board[row - 2][col] == UNKNOWN)) {
                mark_square_as(board, size, row - 2, col, RED, announce);
            }
            else if (row == size - 2 && (board[row - 1][col] == UNKNOWN)) {
                mark_square_as(board, size, row - 1, col, RED, announce);
            }
            else {
                if ((board[row + 2][col] == UNKNOWN)) {
                    mark_square_as(board, size, row + 2, col, RED, announce);
                    }
                if ((board[row - 1][col] == UNKNOWN)) {
                    mark_square_as(board, size, row - 1, col, RED, announce);
                }
            }


        }

        // Checking two separate blue moves
        else if ((board[row][col] == BLUE) && board[row + 2][col] == BLUE) {
            if (board[row + 1][col] == UNKNOWN) {
                mark_square_as(board, size, row + 1, col, RED, announce);
            }

        }

        // Checking two separate red moves
        else if ((board[row][col] == RED) && board[row + 2][col] == RED) {
            if (board[row + 1][col] == UNKNOWN) {
                mark_square_as(board, size, row + 1, col, BLUE, announce);
            }
        }
    }

    }
    return;
}

// Checks rows to make sure that the number of blue and red colors are equal and balanced
void solve_balance_row(int board[MAX_SIZE][MAX_SIZE],
    int size,
    int row,
    bool announce) {
    int col = 0;
    int redHalfCounter = 0;
    int blueHalfCounter = 0;

    // If half row is RED
    for (col = 0; col < size; col++) {
        if (board[row][col] == RED) {
            redHalfCounter += 1;
        }
    }
    if (redHalfCounter == (size / 2)) {
        for (col = 0; col < size; col++) {
            if (board[row][col] == UNKNOWN) {
                mark_square_as(board, size, row, col, BLUE, announce);
            }
        }
    }

    // If half row is BLUE
    for (col = 0; col < size; col++) {
        if (board[row][col] == BLUE) {
            blueHalfCounter += 1;
        }
    }
    if (blueHalfCounter == (size / 2)) {
        for (col = 0; col < size; col++) {
            if (board[row][col] == UNKNOWN) {
                mark_square_as(board, size, row, col, RED, announce);
            }
        }
    }
    return;
}

// Checks to make sure that half the column is balanced with red and blue moves
void solve_balance_column(int board[MAX_SIZE][MAX_SIZE],
    int size,
    int col,
    bool announce) {
    int row = 0;
    int redHalfCounter = 0;
    int blueHalfCounter = 0;

    // If half row is RED
    for (row = 0; row < size; row++) {
        if (board[row][col] == RED) {
            redHalfCounter += 1;
        }
    }
    if (redHalfCounter == (size / 2)) {
        for (row = 0; row < size; row++) {
            if (board[row][col] == UNKNOWN) {
                mark_square_as(board, size, row, col, BLUE, announce);
            }
        }
    }

    // If half col is BLUE
    for (row = 0; row < size; row++) {
        if (board[row][col] == BLUE) {
            blueHalfCounter += 1;
        }
    }
    if (blueHalfCounter == (size / 2)) {
        for (row = 0; row < size; row++) {
            if (board[row][col] == UNKNOWN) {
                mark_square_as(board, size, row, col, RED, announce);
            }
        }
    }
    return;
}


/**
* --------------------------------------------------------
* ---------- GAMEPLAY FUNCTIONS --------------------------
* --------------------------------------------------------
*/

// Checks if board is solved or not, returns true is board is solved
bool board_is_solved(const int board[MAX_SIZE][MAX_SIZE], int size) {

    if ((board_is_valid(board, size)) && (count_unknown_squares(board, size) == 0)) {
        return true;
    }
    else {
        return false;
    }

}

// Checks user input to confirm that it is valid and matches with the row, column and color
bool check_valid_input(int size, int row_input, char col_input,
    char color_char, int &row, int &col) {
    if (row_input > size || row_input < 1) {

        cout << "Sorry, that's not a valid input.";
        return false;
    }

    else if ((col_input < 'A' || col_input >('A' + size - 1)) &&
        ((col_input < 'a' || col_input >('a' + size - 1)))) {

        cout << "Sorry, that's not a valid input.";
        return false;
    }

    else if (color_char != RED_LETTER && color_char != 'x'
        && color_char != BLUE_LETTER && color_char != 'o' &&
        color_char != '-') {

        cout << "Sorry, that's not a valid input.";
        return false;
    }
    else {
        row = row_input - 1;
        if (isupper(col_input)) {
            col = col_input - 65;
        }
        else {
            col = col_input - 97;
        }
        return true;

    }
}

// Takes the row and column and makes sure that the move is valid
bool check_valid_move(const int original_board[MAX_SIZE][MAX_SIZE],
    const int current_board[MAX_SIZE][MAX_SIZE],
    int size, int row, int col, int color) {

    if (original_board[row][col] != 0) {
        cout << "Sorry, original squares cannot be changed.";
        return false;
    }
    else {
        int checkCurrentBoard[MAX_SIZE][MAX_SIZE];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                checkCurrentBoard[i][j] = current_board[i][j];
            }
        }

        mark_square_as(checkCurrentBoard, size, row, col, color, false);

        if (board_is_valid(checkCurrentBoard, size) == false) {

            cout << "Sorry, that move violates a rule.";
            return false;
        }

        else {
            return true;
        }
    }
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