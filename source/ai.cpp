#include <cstdlib>
#include <ctime>
#include <iostream>

#include "ai.hpp"
#include "globals.hpp"
#include "grid.hpp"

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

int generate_random(int min, int max) {
  srand(time(NULL));
  return min + rand() % (max - min + 1);
}

void play_with_ai(char xo) {
  if (game_level == 1) {
    play_with_easy_ai(xo);
  }
}