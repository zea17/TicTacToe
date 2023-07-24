#include "ai.hpp"
#include "globals.hpp"
#include "grid.hpp"
#include "medium_ai.hpp"

bool dimension_is_odd() { return dimension % 2 == 1; }

int get_center() { return dimension / 2; }

int get_start_or_end(int index) {
  if (index == 0) {
    return 0;
  }
  return dimension - 1;
}
int get_opposite_index(int index) {
  if (index == 0) {
    return dimension - 1;
  }
  return 0;
}

int random_corner_index() { return get_start_or_end(generate_random(0, 1)); }

void play_first_move(char xo) {
  int row = random_corner_index();
  int column = random_corner_index();
  grid[row][column] = xo;
}

bool play_second_move(char xo) {
  int center_index = get_center();
  if (grid[center_index][center_index] == EMPTY_VALUE && dimension_is_odd()) {
    grid[center_index][center_index] = xo;
    return true;
  }
  grid[0][dimension - 1] = xo;
}

bool play_with_fork_strategy(char xo) {
  for (int row = 0; row < 2; row++) {
    int row_index = get_start_or_end(row);

    for (int column = 0; column < 2; column++) {
      int column_index = get_start_or_end(column);

      if (grid[row_index][column_index] == xo) {
        if (grid[get_opposite_index(row_index)][column_index] == EMPTY_VALUE) {
          grid[get_opposite_index(row_index)][column_index] = xo;
          return true;
        }
        if (grid[row_index][get_opposite_index(column_index)] == EMPTY_VALUE) {
          grid[get_opposite_index(row_index)][column_index] = xo;
        }
      }
    }
  }
}

bool play_on_row_win_strategy_(char xo) {
  // for each row
  for (int column = 0; column < dimension; column++) {

    int count = 0;
    for (int row = 0; row < dimension; row++) {
      if (grid[row][column] == xo) {
        count++;
      }
    }
    // if it was enough, try to put your turn in the middle:
    if (count == 2) {
      for (int row = 0; row < dimension; row++) {
        if (grid[row][column] == EMPTY_VALUE) {
          grid[row][column] = xo;
          return true;
        }
      }
    }
  }
  return false;
}

bool play_column_win_strategy(char xo) {
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
    if (count == 2) {
      for (int column = 0; column < dimension; column++) {
        if (grid[row][column] == EMPTY_VALUE) {
          grid[row][column] = xo;
          return true;
        }
      }
    }
  }
}

void play_with_hard_ai(char xo) {
  int moves_count = count_played_moves();

  if (moves_count == 0) {
    play_first_move(xo);
  }

  else if (moves_count <= 2) {
    play_second_move(xo);
  }
}
