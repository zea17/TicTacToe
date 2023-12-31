#include <iostream>
#include <stdlib.h>

#include "easy_ai.hpp"
#include "globals.hpp"
#include "grid.hpp"
#include "setup.hpp"
#include "storage_manager.hpp"
#include "terminal.hpp"

// ─── Prompt For Loading Previous Game ────────────────────────────────────────

bool ask_user_should_we_load_previous_game() {
  int should_continue;

  clean_screen();
  print_decoration_line();

  std::cout << LEFT_PADDING << "Previous game save exist" << std::endl
            << std::endl
            << LEFT_PADDING << "• 1     - Continue Previous Game" << std::endl
            << LEFT_PADDING << "• Other - New Game" << std::endl
            << std::endl
            << "  > ";

  std::cin >> should_continue;
  return should_continue == 1;
}

// ─── Dimension Of The Tic-tac-toe ────────────────────────────────────────────

int choose_dimension() {
  int size;

  while (true) {
    print_decoration_line();

    std::cout << LEFT_PADDING << "Enter the dimensions of the" << std::endl
              << LEFT_PADDING << "Tic-Tac-Toe board (min: 3) " << std::endl
              << std::endl
              << "  > ";

    std::cin >> size;

    if (size > 2) {
      return size;
    }

    std::cout << std::endl
              << LEFT_PADDING
              << "ERROR: Dimension must be greater that 3, please try again:"
              << std::endl;
  }

  return size;
}

// ─── Choose The Number Of Players ────────────────────────────────────────────

int choose_number_of_players() {
  int number_of_players;

  while (true) {
    print_decoration_line();
    std::cout << LEFT_PADDING << "Choose the number of players:" << std::endl
              << std::endl
              << LEFT_PADDING << "• 1 - Play against the computer" << std::endl
              << LEFT_PADDING << "• 2 - Play against a friend" << std::endl
              << LEFT_PADDING << "• 3 - Back" << std::endl
              << std::endl
              << LEFT_PADDING << "> ";

    std::cin >> number_of_players;

    switch (number_of_players) {
    case 1:
    case 2:
    case 3:
      return number_of_players;

    default:
      std::cout << LEFT_PADDING << "Invalid input. Please enter 1 or 2."
                << std::endl;
    }
  }
}

// ─── Choose The Game Level ───────────────────────────────────────────────────

int choose_game_level() {
  int choice;

  while (true) {
    print_decoration_line();
    std::cout << LEFT_PADDING << "Choose the game level:" << std::endl
              << std::endl
              << LEFT_PADDING << "• 1 - Easy" << std::endl
              << LEFT_PADDING << "• 2 - Medium" << std::endl
              << LEFT_PADDING << "• 3 - Hard" << std::endl
              << LEFT_PADDING << "• 4 - Back" << std::endl
              << std::endl
              << LEFT_PADDING << "> ";
    std::cin >> choice;

    switch (choice) {
    case 1:
    case 2:
    case 3:
    case 4:
      return choice;

    default:
      std::cout << LEFT_PADDING
                << "ERROR: Invalid input. Please enter 1, 2, or 3." << std::endl
                << std::endl;
    }
  }
}

// ─── Wizard ──────────────────────────────────────────────────────────────────

void game_wizard() {
  int level = 1;
  while (level < 4) {
    clean_screen();

    if (level == 1) {
      dimension = choose_dimension();
    }

    if (level == 2) {
      number_of_players = choose_number_of_players();
      if (number_of_players == 3) {
        level -= 2;
      }

      if (number_of_players == 2) {
        break;
      }
    }

    if (level == 3) {
      game_level = choose_game_level();

      if (game_level == 4) {
        level -= 2;
      }
    }

    level++;
  }
}

// ─── Welcome Message ─────────────────────────────────────────────────────────

void show_welcome_screen() {
  clean_screen();

  std::cout << std::endl << std::endl << std::endl;

  std::cout
      << "  ╭─────┬───────────────────╮" << std::endl
      << "  │ ZEA │                   │" << std::endl
      << "  ├─────╯                   │" << std::endl
      << "  │                         │" << std::endl
      << "  │   \033[1;33mT \033[1;35mI \033[1;33mC  \033[1;35mT \033[1;33mA "
         "\033[1;35mC  \033[1;33mT \033[1;35mO \033[1;33mE \033[0m  │"
      << std::endl
      << "  │      \x1B[3m\x1B[36mFirst Edition\x1B[0m      │" << std::endl
      << "  │                         │" << std::endl
      << "  ├ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ┤" << std::endl
      << "  │    " << TERM_ITALIC << "By Zeynab Akbari" << TERM_RESET
      << "     │" << std::endl
      << "  ╰─────────────────────────╯" << std::endl
      << std::endl
      << std::endl;
  std::cout << "    > Press Enter to Start ";
  getchar();
}

// ─── Main Setup ──────────────────────────────────────────────────────────────

void setup() {
  show_welcome_screen();

  current_turn = choose_random_first_player();

  if (does_state_exists()) {
    if (ask_user_should_we_load_previous_game()) {
      load_state();
      return;
    }
  }

  game_wizard();
  create_grid();
}
