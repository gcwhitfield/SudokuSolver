#include "sudoku.hpp"

int main(int argc, char** argv)
{
    if (argc != 2) {
        std::cerr << "Usage: ./a.out <sudoku board file path>" << std::endl;
        exit(0);
    }

    Board *board = new Board(argv[1]);
    board->print();
    board->solve();
    board->print();

    return 0;
}