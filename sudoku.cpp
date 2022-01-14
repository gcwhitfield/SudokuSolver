#include "sudoku.hpp"

// prints error and potentially exits program
static void boardError(bool shutdown) {
    cout << "Incorrectly formatted board. " << endl;
    if (shutdown) {
        exit(0);
    }
    return;
}

void Board::readBoard(string filename)
{
    cout << "Reading sudoku file..." << endl;
    ifstream file;
    file.open(filename);
    string buf;
    if (!file) {
        cout << "Could not open file" << endl;
        exit(0);
    }

    size_t i = 0;
    while (file >> buf) {
        if (i > BOARD_SIZE) {
            boardError(true);
        }
        size_t j = 0;

        for (string::iterator it=buf.begin(); it != buf.end(); it++) {
            this->data[i][j] = *it - '0';
            if (j > BOARD_SIZE) {
                boardError(true);
            }
            j++;
        }
        i++;
    }
    file.close();
    cout << "Sudoku file successfully read." << endl;
}

bool Board::isSolvedRow(size_t i) {
    char *row = this->data[i]; // only use up to 9 spots

    // storewhether we have seen number in a temporary array
    bool numberSeen[BOARD_SIZE];
    for (int j = 0; j < BOARD_SIZE; j++) {
        numberSeen[j] = false;
    }

    // loop over row and populate array with booleans corresponding to 
    // whether we have seen number at index (index 0 corresponds to the 
    // number 1, 1 to 2, etc.)
    // if seenIndex is < 0 then the board is not completely full.
    int seenIndex = 0;
    for (int j = 0; j < BOARD_SIZE; j++) {
        seenIndex = row[j] - 1;
        if (seenIndex == -1) {
            return false;
        }
        numberSeen[seenIndex] = true;
    }

    // confirm that all of the numbers are seen.
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (!numberSeen[j]) {
            return false;
        }
    }

    return true;
}

bool Board::isSolvedCol(size_t i) {
    // store whether we have seen number 1 - 9 in a temporary array
    bool numberSeen[BOARD_SIZE];
    for (int j = 0; j < BOARD_SIZE; j++) {
        numberSeen[j] = false;
    }

    // loop over column and populate array with booleans corresponding to 
    // whether we have seen number at index (index 0 corresponds to the 
    // number 1, 1 to 2, etc.)
    // if seenIndex is < 0 then the board is not completely full.
    int seenIndex = 0;
    for (int j = 0; j < BOARD_SIZE; j++) {
        seenIndex = this->data[j][i] - 1;
        if (seenIndex < 0) {
            return false;
        }
        numberSeen[seenIndex] = true;
    }

    // confirm that all of the numbers are seen
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (!numberSeen[j]) {
            return false;
        }
    }

    return true;
}

// Returns true if square at index i is solved on board; 
// The top 3 squares are indecies 0 - 2, the middle three are 3 - 5, and
// the bottom are 6 - 8.
bool Board::isSolvedSquare(size_t i) {
    // row and col corrspond to the large suqare, NOT individual 
    // numbers on the sudoku board.
    char row = i / 3;
    char col = i % 3;

    // store whether we have seen number 1 - 9 in a temporary array
    bool numberSeen[BOARD_SIZE];
    for (int j = 0; j < BOARD_SIZE; j++) {
        numberSeen[j] = false;
    }

    // loop over square and populate array with booleans corresponding to 
    // whether we have seen number at index (index 0 corresponds to the 
    // number 1, 1 to 2, etc.)
    // if seenIndex is < 0 then the board is not completely full.
    size_t seenIndex = 0;
    char val = 0;
    for (int j = 0; j < BOARD_SIZE; j++) {
        val = this->data[row * 3 + (j / 3)][col * 3 + (j % 3)];
        seenIndex = val - 1;
        if (seenIndex < 0) {
            return false;
        }
        numberSeen[seenIndex] = true;
    }

    // confirm that all of the numbers are seen
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (!numberSeen[j]) {
            return false;
        }
    }

    return true;
}

// returns the number of empty spaces on the board
unsigned Board::emptySpaces() {
    unsigned result = 0;
    for (int y = 0; y < BOARD_SIZE; y++) {
        for (int x = 0; x < BOARD_SIZE; x++) {
            if (!this->data[y][x]) {
                result++;
            }
        }
    }
    return result;
}

bool Board::validMoves(unsigned x, unsigned y, bool *occupied) {
    // precondition: array is at least size BOARD_SIZE
    for (unsigned i = 0; i < BOARD_SIZE; i++) {
        occupied[i] = false;
    }

    for (unsigned i = 0; i < BOARD_SIZE; i++) {

        // loop over the row
        if (this->data[y][i] != 0) {
            occupied[this->data[y][i] - 1] = true;
        }

        // loop over the col
        if (this->data[i][x] != 0) {
            occupied[this->data[i][x] - 1] = true;
        }

        // loop over the square
        unsigned char squareX = (x / 3) * 3 + (i % 3);
        unsigned char squareY = (y / 3) * 3 + (i / 3);
        if (this->data[squareY][squareX] != 0) {
            occupied[this->data[squareY][squareX] - 1] = true;
        }
    }

    // returns true if there are any valid moves, false otherwise
    for (unsigned i = 0; i < BOARD_SIZE; i++) {
        if (!occupied[i]) {
            return true;
        }
    }
    return false;
}

bool Board::solveHelper(int depth, std::unordered_set<string> *memo) {

    // memoization: when an invalid board is created, it is put inside 
    // of the memo. if it is found inside the memo when solveHelper is 
    // called, then we can instantly return false 
    if (memo->find(this->hash()) != memo->end()) {
        numSuccessfulMemoHits++;
        return false;
    }

    numBoardsChecked++;
    if (numBoardsChecked % 100000 == 0) {
        cout << "Number of sudoku boards checked: " << numBoardsChecked << endl;
    }

    if (isSolved()) {
        return true;
    } else {
        unsigned randOffset = rand() % 20;
        unsigned xOffset = randOffset % 9;
        unsigned yOffset = randOffset % 17;
        unsigned x,y = 0;
        for (unsigned _y = 0; _y < BOARD_SIZE; _y++) {
            for (unsigned _x = 0; _x < BOARD_SIZE; _x++) {
                x = (_x + xOffset) % 9;
                y = (_y + yOffset) % 9;
                if (this->data[y][x] == 0) { // if free space
                    // store the possible moves inside of 'occupied'
                    bool occupied[BOARD_SIZE];
                    if (validMoves(x, y, occupied)) {
                        for (unsigned val = 1; val < BOARD_SIZE + 1; val++) {
                            if (!occupied[val - 1]) {
                                makeMove(x, y, val);
                                if (solveHelper(depth + 1, memo)) {
                                    return true;
                                }
                                memo->insert(this->hash());
                                undoMove(x, y);
                            }
                        }
                    } else {
                        memo->insert(this->hash());
                        return false; // return false if there exists an 
                        // empty cell without any valid moves
                    }
                }
            }
        }
        memo->insert(this->hash());
        return false; // return false if we've looped over the entire 
        // board and haven't found a solution 
    }
}

Board::Board(string filename) {
    Board();
    readBoard(filename);
}

Board::Board() {
    // initialize board to zeroes
    for (size_t y = 0; y < BOARD_SIZE; y++) {
        for (size_t x = 0; x < BOARD_SIZE; x++) {
            this->data[y][x] = 0;
        }
    }
}

void Board::print() {
    for (size_t y = 0; y < BOARD_SIZE; y++)
    {
        for (size_t x = 0; x < BOARD_SIZE; x++)
        {
            cout << (char)(this->data[y][x] + '0');
            if (x != BOARD_SIZE - 1)
            {
                if (x == 2 || x == 5) {
                    cout << " | ";
                } else {
                    cout << "   ";
                }
            }
        }
        if (y == 2 || y == 5) {
            cout << endl;
            for (size_t x = 0; x < BOARD_SIZE; x++) {
                if (x == 2 || x == 5) {
                    cout << "- * ";
                } else if (x < BOARD_SIZE - 1) {
                    cout << "----";
                } else {
                    cout << "-";
                }
            }
        }
        cout << endl;
    }
    cout << endl;
}

string Board::hash() {
    string result(BOARD_SIZE * BOARD_SIZE, '0');
    for (size_t y = 0; y < BOARD_SIZE; y++) {
        for (size_t x = 0; x < BOARD_SIZE; x++) {
            result[y * BOARD_SIZE + x] = this->data[y][x];
        }
    }
    return result;
}

bool Board::isSolved() {
    for (size_t i = 0; i < 9; i++) {
        if (!isSolvedCol(i) || !isSolvedRow(i) || !isSolvedSquare(i)) {
            return false;
        }
    }
    return true;
}

bool Board::isFull() {
    char val;
    for (size_t y = 0; y < BOARD_SIZE; y++) {
        for (size_t x = 0; x < BOARD_SIZE; x++) {
            val = this->data[y][x];
            if (val == 0) { 
                return false;
            }
        }
    }
    return true;
}

void Board::checkIsValidBoard() {
    bool occupied[BOARD_SIZE];
    auto clearOccArray = [](bool (&occupied)[BOARD_SIZE]) {
        for (unsigned x = 0; x < BOARD_SIZE; x++) {
            occupied[x] = false;
        }
    };
    
    // loop over every row
    for (unsigned y = 0; y < BOARD_SIZE; y++) {
        clearOccArray(occupied);
        for (unsigned x = 0; x < BOARD_SIZE; x++) {
            int idx = this->data[y][x] - 1;
            if (idx != -1) {
                assert(1 <= this->data[y][x] && this->data[y][x] <= 9); // numbers between 1 and 9
                assert(occupied[idx] == false); // no duplicate numbers
                occupied[idx] = true;
            }
        }
    }
    
    // loop over every col
    for (unsigned x = 0; x < BOARD_SIZE; x++) {
        clearOccArray(occupied);
            for (unsigned y = 0; y < BOARD_SIZE; y++) {
            int idx = this->data[y][x] - 1;
            if (idx != -1) {
                assert(1 <= this->data[y][x] && this->data[y][x] <= 9); // numbers between 1 and 9
                assert(occupied[idx] == false); // no duplicate numbers
                occupied[idx] = true;
            }
        }
    }
    // loop over every square
    for (unsigned outer = 0; outer < BOARD_SIZE; outer++) {
        unsigned squareXOuter = outer % 3;
        unsigned squareYOuter = outer / 3;
        clearOccArray(occupied);
        for (unsigned inner = 0; inner < BOARD_SIZE; inner++) {
            unsigned squareXInner = inner % 3;
            unsigned squareYInner = inner / 3;
            unsigned X = squareXOuter * 3 + squareXInner;
            unsigned Y = squareYOuter * 3 + squareYInner;
            int idx = this->data[Y][X] - 1;
            if (idx != -1) {
                assert(1 <= this->data[Y][X] && this->data[Y][X] <= 9); // numbers between 1 and 9
                if (occupied[idx] != false) {
                    std::cout << "X: " << X << std::endl;
                    std::cout << "Y: " << Y << std::endl;
                    std::cout << "idx: " << idx << std::endl;
                    std::cout << this->data[Y][X] << std::endl;
                }
                assert(occupied[idx] == false);
                occupied[idx] = true;
            }
        }
    }
}

bool Board::solve() {
    cout << "Solving..." << endl;
    std::unordered_set<string> memo;
    return this->solveHelper(0, std::addressof(memo));
}