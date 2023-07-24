#include <cmath>
#include <iostream>

#include "globals.hpp"
#include "terminal.hpp"

#define LEFT_PADDING "  "

// ─── Clears The Screen ───────────────────────────────────────────────────────

void clean_screen() {
  system("clear");
  std::cout << std::endl;
}

// ─── Prints A Given Text Repeatedly For A Specified Number Of Times ──────────

void print_repeated_text(const char *text, int repeat) {
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
  if (cell_content == EMPTY_VALUE) {
    return compute_number_digits(cell_number);
  }
  return 1;
}

// ─── Renders A Single Cell In The Game Grid ──────────────────────────────────

bool is_cell_a_winner(int cell_number) {
  cell_number--;
  int row = ceil(cell_number / dimension);
  int column = (cell_number - row * dimension);

  if (winning_column == column) {
    return true;
  }
  if (winning_row == row) {
    return true;
  }
  if (winning_ltr_diagonal && row == column) {
    return true;
  }
  if (winning_rtl_diagonal && row == dimension - 1 - column) {
    return true;
  }

  return false;
}

void print_cell_color(int cell_number, char cell_content) {
  if (is_cell_a_winner(cell_number)) {
    std::cout << "\033[1;32m";
  } else if (cell_content == O_VALUE) {
    std::cout << "\033[1;33m";
  } else {
    std::cout << "\033[1;35m";
  }
}

void render_cell(int cell_width, int cell_number, char cell_content,
                 bool is_last_column) {
  // sizes
  int content_width = compute_content_width(cell_content, cell_number);
  int left_padding = (cell_width - content_width) / 2;
  int right_padding = cell_width - content_width - left_padding;

  // ─── Content─────────────────────────────────────────────────────────────

  print_repeated_text(" ", left_padding);

  if (cell_content == EMPTY_VALUE) {
    std::cout << cell_number;
  }

  else {
    print_cell_color(cell_number, cell_content);
    std::cout << cell_content << "\033[0m";
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
  std::cout << LEFT_PADDING;

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
  clean_screen();

  int cell_width = compute_cell_width();
  int cell_number = 1;

  for (int row = 0; row < dimension; row++) {
    bool is_not_last_row = row != dimension - 1;

    std::cout << LEFT_PADDING;

    for (int column = 0; column < dimension; column++) {
      char cell_content = grid[row][column];
      bool is_last_column = column == dimension - 1;
      render_cell(cell_width, cell_number, cell_content, is_last_column);
      cell_number++;
    }

    if (is_not_last_row) {
      render_horizontal_lines(cell_width);
    }
  }
  std::cout << std::endl << std::endl;
}

// ─── Prompt User ─────────────────────────────────────────────────────────────

int prompt_user_for_play(char xo) {
  while (true) {
    int cell_number;
    std::cout << "  Player " << xo << ", enter your move:\n\n  > ";
    std::cin >> cell_number;

    // with help from stack over flow
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      cell_number = 0;
    }

    if (cell_number >= MIN_NUMBER && cell_number <= dimension * dimension) {
      return cell_number;
    }

    std::cout << "\n  Invalid move. Please enter a number between 1 and "
              << dimension * dimension << "\n\n";
  }
}