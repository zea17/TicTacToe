#include "ai.hpp"
#include "easy_ai.hpp"
#include "globals.hpp"
#include "grid.hpp"
#include "medium_ai.hpp"

// ─── Tools ───────────────────────────────────────────────────────────────────

bool dimension_is_odd() { return dimension % 2 == 1; }

int get_center() { return dimension / 2; }

int get_opposite_index(int index) {
  if (index == 0) {
    return dimension - 1;
  }
  return 0;
}

// ─── Compute The Chance To Win ───────────────────────────────────────────────

int compute_row_chance(int row, int column, char xo) {
  char opponent = get_opponent(xo);
  int moves_to_win = dimension - 1;

  for (int column = 0; column < dimension; column++) {
    if (grid[row][column] == xo) {
      moves_to_win--;
    }

    if (grid[row][column] == opponent) {
      return 0;
    }
  }

  return moves_to_win;
}

int compute_column_chance(int row, int column, char xo) {
  char opponent = get_opponent(xo);
  int moves_to_win = dimension - 1;

  for (int row = 0; row < dimension; row++) {
    if (grid[row][column] == xo) {
      moves_to_win--;
    }

    if (grid[row][column] == opponent) {
      return 0;
    }
  }

  return moves_to_win;
}

int compute_ltr_diagonal_chance(int index, char xo) {
  char opponent = get_opponent(xo);
  int moves_to_win = dimension - 1;
  for (int index = 0; index < dimension; index++) {
    if (grid[index][index] == xo) {
      moves_to_win--;
    }
    if (grid[index][index] == opponent) {
      return 0;
    }
  }

  return moves_to_win;
}

int compute_rtl_diagonal_chance(int index, char xo) {
  char opponent = get_opponent(xo);
  int moves_to_win = dimension - 1;
  for (int i = dimension - 1; i >= 0; i--) {
    if (grid[i][dimension - 1 - i] == xo) {
      moves_to_win--;
    }
    if (grid[i][dimension - 1 - i] == opponent) {
      return 0;
    }
  }

  return moves_to_win;
}

int compute_win_chance(int row, int column, char xo) {
  int win_chance = 0;

  win_chance += compute_column_chance(row, column, xo) +
                compute_row_chance(row, column, xo);
  if (column == dimension - row - 1) {
    win_chance += compute_rtl_diagonal_chance(row, xo);
  }
  if (row == column) {
    win_chance += compute_ltr_diagonal_chance(row, xo);
  }
  return win_chance;
}

// ─── Play By Blocking Opponent ───────────────────────────────────────────────

bool play_by_blocking_opponent(char xo) {
  char opponent = get_opponent(xo);
  int threshold = 2 * (dimension - 1);
  for (int row = 0; row < dimension; row++) {
    for (int column = 0; column < dimension; column++) {
      if (grid[row][column] == EMPTY_VALUE) {

        int chance = compute_win_chance(row, column, opponent);
        if (chance >= threshold) {
          grid[row][column] = xo;
          return true;
        }
      }
    }
  }
  return false;
}

// ─── Play The Best Move Possible ─────────────────────────────────────────────

bool play_best_move(char xo) {
  int max_opportunity = 0;
  int row_index = -1;
  int column_index = -1;

  for (int row = 0; row < dimension; row++) {
    for (int column = 0; column < dimension; column++) {
      if (grid[row][column] == EMPTY_VALUE) {

        int chance = compute_win_chance(row, column, xo);
        if (chance > max_opportunity) {
          max_opportunity = chance;
          row_index = row;
          column_index = column;
        }
      }
    }
  }
  if (row_index > -1 && column_index > -1) {
    grid[row_index][column_index] = xo;
    return true;
  }
  return false;
}

// ─── Play The Best First Move ────────────────────────────────────────────────

bool play_the_best_first_move(char xo) {
  int center_index = get_center();
  if (grid[center_index][center_index] == EMPTY_VALUE && dimension_is_odd()) {
    grid[center_index][center_index] = xo;
    return true;
  }
  if (grid[0][dimension - 1] == EMPTY_VALUE) {
    grid[0][dimension - 1] = xo;
    return true;
  }
  return false;
}

// ─── Play By Blocking Opponent ───────────────────────────────────────────────

bool second_move(char xo) {
  char opponent = get_opponent(xo);
  int left = 0;
  int right = 0;
  int top = 0;
  int bottom = 0;

  for (int column = 0; column < dimension; column++) {
    if (grid[0][column] == opponent) {
      top += 1;
    }
    if (grid[dimension - 1][column] == opponent) {
      bottom += 1;
    }
  }
  for (int row = 0; row < dimension; row++) {
    if (grid[row][0] == opponent) {
      left += 1;
    }
    if (grid[row][dimension - 1] == opponent) {
      right += 1;
    }
  }

  // Case of two
  if (top + left == 2 && grid[0][0] == EMPTY_VALUE) {
    grid[0][0] = xo;
    return true;
  }
  if (top + right == 2 && grid[0][dimension - 1] == EMPTY_VALUE) {
    grid[0][dimension - 1] = xo;
    return true;
  }
  if (left + bottom == 2 && grid[dimension - 1][0] == EMPTY_VALUE) {
    grid[dimension - 1][0] = xo;
    return true;
  }
  if (right + bottom == 2 &&
      grid[dimension - 1][dimension - 1] == EMPTY_VALUE) {
    grid[dimension - 1][dimension - 1] = xo;
    return true;
  }

  // case of one
  if (top == 1) {
    if (grid[0][0] == EMPTY_VALUE) {
      grid[0][0] = xo;
      return true;
    }
    if (grid[0][dimension - 1] == EMPTY_VALUE) {
      grid[0][dimension - 1] = xo;
      return true;
    }
  }

  if (bottom == 1) {
    if (grid[dimension - 1][0] == EMPTY_VALUE) {
      grid[dimension - 1][0] = xo;
      return true;
    }
    if (grid[dimension - 1][dimension - 1] == EMPTY_VALUE) {
      grid[dimension - 1][dimension - 1] = xo;
      return true;
    }
  }

  if (left == 1) {
    if (grid[0][0] == EMPTY_VALUE) {
      grid[0][0] = xo;
      return true;
    }
    if (grid[dimension - 1][0] == EMPTY_VALUE) {
      grid[dimension - 1][0] = xo;
      return true;
    }
  }

  if (right == 1) {
    if (grid[0][dimension - 1] == EMPTY_VALUE) {
      grid[0][dimension - 1] = xo;
      return true;
    }
    if (grid[0][dimension - 1] == EMPTY_VALUE) {
      grid[0][dimension - 1] = xo;
      return true;
    }
  }

  return false;
}

// ─── Play The Winning Move ───────────────────────────────────────────────────

bool play_on_row_win_strategy(char xo) {
  char opponent = get_opponent(xo);
  // for each row
  for (int column = 0; column < dimension; column++) {

    int count = 0;
    for (int row = 0; row < dimension; row++) {
      if (grid[row][column] == xo) {
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
        if (grid[row][column] == opponent) {
          return false;
        }
      }
    }
  }
  return false;
}

bool play_on_column_win_strategy(char xo) {
  char opponent = get_opponent(xo);
  // for each row
  for (int row = 0; row < dimension; row++) {
    // count how many times the opponent has appeared
    int count = 0;

    // count the opponent
    for (int column = 0; column < dimension; column++) {
      if (grid[row][column] == xo) {
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
        if (grid[row][column] == opponent) {
          return false;
        }
      }
    }
  }
  return false;
}

bool play_on_rtf_diagonal_win_strategy(char xo) {
  int count = 0;
  char opponent = get_opponent(xo);

  for (int index = 0; index < dimension; index++) {
    int column = dimension - 1 - index;

    if (grid[index][column] == xo) {
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
      if (grid[index][column] == opponent) {
        return false;
      }
    }
  }

  return false;
}

bool play_on_ltr_diagonal_win_strategy(char xo) {
  int count = 0;
  char opponent = get_opponent(xo);

  for (int index = 0; index < dimension; index++) {
    if (grid[index][index] == xo) {
      count++;
    }
  }

  if (count == dimension - 1) {
    for (int index = 0; index < dimension; index++) {
      if (grid[index][index] == EMPTY_VALUE) {
        grid[index][index] = xo;
        return true;
      }
      if (grid[index][index] == opponent) {
        return false;
      }
    }
  }

  return false;
}

bool play_the_move_to_win(char xo) {
  if (play_on_row_win_strategy(xo)) {
    return true;
  }
  if (play_on_column_win_strategy(xo)) {
    return true;
  }
  if (play_on_ltr_diagonal_win_strategy(xo)) {
    return true;
  }
  if (play_on_rtf_diagonal_win_strategy(xo)) {
    return true;
  }
  return false;
}

// ─── Main Playing Function ───────────────────────────────────────────────────

void play_with_hard_ai(char xo) {
  int moves_count = count_played_moves();

  if (moves_count < 2 && play_the_best_first_move(xo)) {
    return;
  }
  if (play_with_defend(xo)) {
    return;
  }
  if (moves_count >= 2 && moves_count < 4 && second_move(xo)) {
    return;
  }
  if (play_the_move_to_win(xo)) {
    return;
  }
  if (play_by_blocking_opponent(xo)) {
    return;
  }
  if (play_best_move(xo)) {
    return;
  }
  play_with_easy_ai(xo);
}
