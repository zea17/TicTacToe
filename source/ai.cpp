#include <cstdlib>
#include <ctime>
#include <iostream>

#include "ai.hpp"
#include "globals.hpp"

void play_with_easy_ai() {}

int generate_random(int min, int max) {
  srand(time(NULL));
  return min + rand() % (max - min + 1);
}