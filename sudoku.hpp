/*
George Whitfield
January 13, 2022
sudoku.hpp

Sudoku solver in c++

g++ --std=c++11 sudoku.cpp main.cpp -O3 -Werror -Wall
*/

#include <string>
#include <iostream>
#include <assert.h>
#include <unordered_set>
#include <set>
#include <fstream>
#include <random>

using namespace std;

const size_t BOARD_SIZE = 9;

// Board is a 2D char array.
class Board {
    private:
        char data[BOARD_SIZE][BOARD_SIZE];

        unsigned numSuccessfulMemoHits = 0; // the number of times that the memo
        // successfully catches a dead board from inside of solveHelper

        unsigned long numBoardsChecked = 0;

        struct move {
            char x;
            char y;
            char val;
        };

        // if the given board is not fortmatted correctly, exit program.
        // read the data from the board
        void readBoard(string filename);

        // returns true if row at index i is solved
        bool isSolvedRow(size_t i);

        // returns true if col at index i is solved
        bool isSolvedCol(size_t i);

        // Returns true if square at index i is solved on board; 
        // The top 3 squares are indecies 0 - 2, the middle three are 3 - 5, and
        // the bottom are 6 - 8.
        bool isSolvedSquare(size_t i);
        
        // returns the number of empty spaces on the board
        unsigned emptySpaces();
        
        // stores the valid moved for data[y][x] inside of a bool array
        bool validMoves(unsigned x, unsigned y, bool *occupied);

        // depth: recursion depth 
        // emptyCells: a set of all of the cells (x,y) in the sudoku board that are
        // open
        // memo: set of all of the dead boards
        bool solveHelper(int depth, std::unordered_set<string> *memo);
        
        // makes the move m on the board.
        // return value: the value of the old position on the board
        void makeMove(unsigned x, unsigned y, unsigned val) {
            this->data[y][x] = val;
        }
        
        void undoMove(unsigned x, unsigned y) {
            this->data[y][x] = 0;
        }

    public:
        // initialize data from file into board
        Board(string filename);

        Board();
        ~Board() {};

        // prints the board to cout
        void print();

        // returns the string representation of the board. Used for memoization
        // of dead boards
        string hash();
        
        // returns true if the board is full and if it is a valid solution
        bool isSolved();

        // returns true if the baord is full
        bool isFull();

        // does nothing if the board is a valid sudoku board
        // raises assertion error if the board is invalid
        // 
        // conditions for valid board:
        // 1) no duplicate numbers in each row, col, and square
        // 2) numbers in each row, col, and square must be between 1-9 (inclusive)
        void checkIsValidBoard();
    
        // attempts to solve the board. returns true if the board has a valid 
        // solution, return false otherwise
        bool solve();
};