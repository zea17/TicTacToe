#include "win_detector.hpp"
#include "globals.hpp"
#include "grid.hpp"

char detect_column_win() {
  for (int column = 0; column < dimension; column++) {
    int first_element = grid[0][column];

    if (first_element != EMPTY_VALUE) {
      bool is_tie = true;

      for (int row = 1; row < dimension; row++) {
        if (grid[row][column] != first_element) {
          is_tie = false;
          break;
        }
      }

      if (is_tie) {
        winning_column = column;
        return grid[0][column];
      }
    }
  }
  return EMPTY_VALUE;
}

char detect_row_win() {
  for (int row = 0; row < dimension; row++) {
    int first_element = grid[row][0];

    if (first_element != EMPTY_VALUE) {
      bool is_tie = true;

      for (int column = 1; column < dimension; column++) {
        if (grid[row][column] != first_element) {
          is_tie = false;
          break;
        }
      }

      if (is_tie) {
        winning_row = row;
        return grid[row][0];
      }
    }
  }
  return EMPTY_VALUE;
}

char detect_ltr_diagonal_win() {
  for (int row = 0; row < dimension; row++) {
    for (int column = 0; column < dimension; column++) {
      int first_element
    }
  }
}

bool detect_win() {}