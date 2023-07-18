#include <cmath>
#include <iostream>

#include "globals.hpp"
#include "terminal.hpp"

void print_repeated_text(char *text, int repeat) {
  if (repeat == 0) {
    return;
  }
  std::cout << text;
  print_repeated_text(text, repeat - 1);
}

int compute_cell_width() {
  int max_number = pow(dimension, 2);
  int digits = int(log10(max_number)) + 1;
  return digits + 2;
}

void render_game() {}