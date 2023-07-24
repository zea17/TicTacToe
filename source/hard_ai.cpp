#include "globals.hpp"
#include "grid.hpp"
#include "medium_ai.hpp"

bool dimension_is_odd() { return dimension % 2 == 1; }

int get_center() { return dimension / 2; }

void play_first_move(char xo) { grid[0][0] = xo; }

bool play_second_move(char xo) {
  if (dimension_is_odd()) {
    int center_index = get_center();
    grid[center_index][center_index] = xo;
    return true;
  }
  grid[dimension - 1][(dimension - 1)] = xo;
}

void play_with_hard_ai(char xo) {
  int moves_count = count_played_moves();

  if (moves_count == 0) {
    play_first_move(xo);
    return;
  }
}
