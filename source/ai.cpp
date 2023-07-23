#include <cstdlib>
#include <ctime>
#include <iostream>

#include "easy_ai.hpp"
#include "globals.hpp"
#include "grid.hpp"
#include "medium_ai.hpp"

int generate_random(int min, int max) {
  srand(time(NULL));
  return min + rand() % (max - min + 1);
}

char choose_random_first_player() {
  if (generate_random(1, 2) == 1) {
    return X_VALUE;
  }
  return O_VALUE;
}

void play_with_ai(char xo) {
  switch (game_level) {
  case 1:
    play_with_easy_ai(xo);
  case 2:
    play_with_medium_ai(xo);
  }
}
