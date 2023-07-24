#include "easy_ai.hpp"
#include "ai.hpp"
#include "globals.hpp"
#include "grid.hpp"

// ─── Easy Ai ─────────────────────────────────────────────────────────────────

void play_with_easy_ai(char xo) {
  int max_number = dimension * dimension;
  while (true) {
    int number = generate_random(MIN_NUMBER, max_number);
    if (get_cell_at(number) == EMPTY_VALUE) {
      set_cell_at(number, xo);
      break;
    }
  }
}
