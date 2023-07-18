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
int compute_number_digits(int number) { return int(log10(number)) + 1; }

int compute_cell_width() {
  int max_number = pow(dimension, 2);
  int digits = compute_number_digits(max_number);
  return digits + 2;
}

int compute_content_width(char cell_content, int cell_number) {
  if (cell_content == '-') {
    return compute_number_digits(cell_number);
  }
  return 1;
}

int *compute_cell_padding(int cell_width, int content_width) {
  int left_padding = (cell_width - content_width) / 2;
  int right_padding = cell_width - content_width - left_padding;
  int result[2] = {left_padding, right_padding};
  return result;
}

void render_cell(int cell_width, int cell_number, char cell_content,
                 bool is_last_column) {

  if (cell_content == '-') {
    std::cout << cell_number;
  } else {
    std::cout << cell_content;
  }
}

void render_game() {}