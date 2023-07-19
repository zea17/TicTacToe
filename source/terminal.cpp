#include <cmath>
#include <iostream>

#include "globals.hpp"
#include "terminal.hpp"

// ─── Clears The Screen ───────────────────────────────────────────────────────

void clean_screen() { system("clear"); }

// ─── Prints A Given Text Repeatedly For A Specified Number Of Times ──────────

void print_repeated_text(char *text, int repeat) {
  if (repeat == 0) {
    return;
  }
  std::cout << text;
  print_repeated_text(text, repeat - 1);
}

// ─── Computes The Number Of Digits In A Given Number ─────────────────────────

int compute_number_digits(int number) { return int(log10(number)) + 1; }

// ─── Computes The Width Of Each Cell In The Game Grid ────────────────────────

int compute_cell_width() {
  int max_number = pow(dimension, 2);
  int digits = compute_number_digits(max_number);
  return digits + 2;
}

// ─── Computes The Width Of The Content In A Cell ─────────────────────────────

int compute_content_width(char cell_content, int cell_number) {
  if (cell_content == '-') {
    return compute_number_digits(cell_number);
  }
  return 1;
}

// ─── Computes The Left And Right Padding For A Cell ──────────────────────────

int *compute_cell_padding(int cell_width, int content_width) {
  int left_padding = (cell_width - content_width) / 2;
  int right_padding = cell_width - content_width - left_padding;
  int result[2] = {left_padding, right_padding};
  return result;
}

// ─── Renders A Single Cell In The Game Grid ──────────────────────────────────

void render_cell(int cell_width, int cell_number, char cell_content,
                 bool is_last_column) {

  // sizes
  int content_width = compute_content_width(cell_content, cell_number);
  int *paddings = compute_cell_padding(cell_width, content_width);
  int left_padding = paddings[0];
  int right_padding = paddings[1];

  // ─── Content─────────────────────────────────────────────────────────────

  print_repeated_text(" ", left_padding);
  if (cell_content == '-') {
    std::cout << cell_number;
  } else {
    std::cout << cell_content;
  }
  print_repeated_text(" ", right_padding);

  // ─── New Line Or Boarder ─────────────────────────────────────────────

  if (is_last_column) {
    std::cout << std::endl;
  } else {
    std::cout << "│";
  }
}

// ─── Renders The Horizontal Lines Between Rows In The Game Grid ──────────────

void render_horizontal_lines(int cell_width) {
  for (int column = 0; column < dimension; column++) {
    bool is_last_column = column == dimension - 1;
    print_repeated_text("─", cell_width);
    if (is_last_column) {
      std::cout << std::endl;
    } else {
      std::cout << "┼";
    }
  }
}
// ─── Renders The Entire Game Grid ────────────────────────────────────────────

void render_game() {
  int cell_width = compute_cell_width();
  int cell_number = 1;

  for (int row = 0; row < dimension; row++) {
    bool is_not_last_row = row != dimension - 1;

    // ─── Row Content───────────────────────────────────────────────────────

    for (int column = 0; column < dimension; column++) {
      char cell_content = grid[row][column];
      bool is_last_column = column == dimension - 1;
      render_cell(cell_width, cell_number, cell_content, is_last_column);
      cell_number++;
    }

    // ─── Horinzontal Line───────────────────────────────────────────────

    if (is_not_last_row) {
      render_horizontal_lines(cell_width);
    }
  }
}