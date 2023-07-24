#include "ai.hpp"
#include "globals.hpp"
#include "grid.hpp"
#include "medium_ai.hpp"

bool dimension_is_odd() { return dimension % 2 == 1; }

int get_center() { return dimension / 2; }

void play_first_move(char xo) { grid[0][0] = xo; }

bool play_second_move(char xo) {
  int center_index = get_center();
  if (grid[center_index][center_index] == EMPTY_VALUE && dimension_is_odd()) {
    grid[center_index][center_index] = xo;
    return true;
  }
  grid[0][dimension - 1] = xo;
}

int random_corner_index() {
  if (generate_random(0, 1) == 0) {
    return 0;
  }
  return dimension - 1;
}

bool play_with_fork_strategy() {
  for (int row = 0; row < dimension; row++) {
    /* code */
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
