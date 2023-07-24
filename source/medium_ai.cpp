#include "medium_ai.hpp"
#include "easy_ai.hpp"
#include "globals.hpp"
#include "grid.hpp"

// ─── Get Opponent ────────────────────────────────────────────────────────────

char get_opponent(char xo) {
  if (xo == O_VALUE) {
    return X_VALUE;
  }
  return O_VALUE;
}

// ─── Play By Defending ───────────────────────────────────────────────────────

bool play_defend_on_rows_as(char xo) {
  char opponent = get_opponent(xo);

  // for each row
  for (int column = 0; column < dimension; column++) {
    // count how many times the opponent has appeared
    int count = 0;

    // count the opponent
    for (int row = 0; row < dimension; row++) {
      if (grid[row][column] == opponent) {
        count++;
      }
    }

    // if it was enough, try to put your turn in the middle:
    if (count == dimension - 1) {
      for (int row = 0; row < dimension; row++) {
        if (grid[row][column] == EMPTY_VALUE) {
          grid[row][column] = xo;
          return true;
        }
      }
    }
  }

  // tell if you have not played
  return false;
}

bool play_defend_on_columns_as(char xo) {
  char opponent = get_opponent(xo);

  // for each row
  for (int row = 0; row < dimension; row++) {
    // count how many times the opponent has appeared
    int count = 0;

    // count the opponent
    for (int column = 0; column < dimension; column++) {
      if (grid[row][column] == opponent) {
        count++;
      }
    }

    // if it was enough, try to put your turn in the middle:
    if (count == dimension - 1) {
      for (int column = 0; column < dimension; column++) {
        if (grid[row][column] == EMPTY_VALUE) {
          grid[row][column] = xo;
          return true;
        }
      }
    }
  }

  // tell if you have not played
  return false;
}

bool play_defend_on_ltr_diagonal(char xo) {
  int count = 0;
  char opponent = get_opponent(xo);

  for (int index = 0; index < dimension; index++) {
    if (grid[index][index] == opponent) {
      count++;
    }
  }

  if (count == dimension - 1) {
    for (int index = 0; index < dimension; index++) {
      if (grid[index][index] == EMPTY_VALUE) {
        grid[index][index] = xo;
        return true;
      }
    }
  }

  return false;
}

bool lay_defend_on_rtl_diagonal(char xo) {
  int count = 0;
  char opponent = get_opponent(xo);

  for (int index = 0; index < dimension; index++) {
    int column = dimension - 1 - index;

    if (grid[index][column] == opponent) {
      count++;
    }
  }

  if (count == dimension - 1) {
    for (int index = 0; index < dimension; index++) {
      int column = dimension - 1 - index;

      if (grid[index][column] == EMPTY_VALUE) {
        grid[index][column] = xo;
        return true;
      }
    }
  }

  return false;
}

bool play_with_defend(char xo) {
  if (play_defend_on_columns_as(xo)) {
    return true;
  }
  if (play_defend_on_rows_as(xo)) {
    return true;
  }
  if (play_defend_on_ltr_diagonal(xo)) {
    return true;
  }
  if (lay_defend_on_rtl_diagonal(xo)) {
    return true;
  }
  return false;
}

// ─── Medium Ai ───────────────────────────────────────────────────────────────

void play_with_medium_ai(char xo) {
  if (play_with_defend(xo)) {
    return;
  }
  play_with_easy_ai(xo);
}
