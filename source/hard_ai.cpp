#include "globals.hpp"
#include "grid.hpp"
#include "medium_ai.hpp"

void play_first_move(char xo) { grid[0][0] = xo; }

void play_with_hard_ai(char xo) {
  int moves_count = count_played_moves();

  if (moves_count == 0) {
    play_first_move(xo);
    return;
  }
}
