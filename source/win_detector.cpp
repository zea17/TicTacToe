#include "win_detector.hpp"
#include "globals.hpp"
#include "grid.hpp"

char detect_column_win() {
  for (int column = 0; column < dimension; column++) {
    char first_element = grid[0][column];

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
    char first_element = grid[row][0];

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
  char first_element = grid[0][0];

  if (first_element != EMPTY_VALUE) {
    bool is_tie = true;
    for (int i = 1; i < dimension; i++) {
      if (grid[i][i] != first_element) {
        is_tie = false;
        break;
      }
    }

    if (is_tie) {
      ::winning_ltr_diagonal = true;
      return grid[0][0];
    }
  }

  return EMPTY_VALUE;
}

char detect_rtl_diagonal_win() {
  char first_element = grid[0][dimension - 1];

  if (first_element != EMPTY_VALUE) {
    bool is_tie = true;
    for (int i = 1; i < dimension; i++) {
      if (grid[i][dimension - 1 - i] != first_element) {
        is_tie = false;
        break;
      }
    }

    if (is_tie) {
      winning_rtl_diagonal = true;
      return grid[0][dimension - 1];
    }
  }

  return EMPTY_VALUE;
}

char win_detector() {
  if (winning_ltr_diagonal) {
    return detect_ltr_diagonal_win();
  }
  if (winning_rtl_diagonal) {
    return detect_rtl_diagonal_win();
  }
  if (winning_column != -1) {
    return detect_column_win();
  }
  if (winning_row != -1) {
    return detect_row_win();
  }
  return EMPTY_VALUE;
}
