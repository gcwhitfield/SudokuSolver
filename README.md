# SudokuSolver
A simple c++ program for solving sudoku. It's still a work in progress. It can solve very simple boards but more optimization is needed to solve medium or hard boards.

### Can solve quickly
almost-solved1.txt
almost-solved2.txt
almost-solved3.txt
almost-solved4.txt
empty-rows.txt

### Times out when attempting to solve
easy1.txt
hard1.txt
hard2.txt

# How to run
Apple clang version >= 11.0.0 (clang-1100.0.33.17).

```
g++ --std=c++17 sudoku.cpp main.cpp -Werror -Wall -O3
./a.out boards/almost-solved4.txt
```
