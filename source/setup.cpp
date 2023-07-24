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

  std::cout << "───────────────────────────────────────────────────────────────"
            << std::endl
            << "  You didn't finish your previous game. Press 1 to continue"
            << std::endl
            << "  playing that game, and any other number to skip." << std::endl
            << std::endl
            << "  > ";

  std::cin >> should_continue;
  return should_continue == 1;
}

// ─── Dimension Of The Tic-tac-toe ────────────────────────────────────────────

int choose_dimension() {
  int size;

  while (true) {
    std::cout
        << "───────────────────────────────────────────────────────────────"
        << std::endl
        << "  Enter the dimensions of the Tic-Tac-Toe board (3 and above): "
        << std::endl
        << std::endl
        << "  > ";

    std::cin >> size;

    if (size > 2) {
      return size;
    }

    std::cout << std::endl
              << "  ERROR: Dimension must be greater that 3, please try again:"
              << std::endl;
  }

  return size;
}

// ─── Choose The Number Of Players ────────────────────────────────────────────

int choose_number_of_players() {
  int number_of_players;

  while (true) {
    std::cout
        << "───────────────────────────────────────────────────────────────"
        << std::endl
        << "  Choose the number of players:" << std::endl
        << "  • 1 - Play against the computer" << std::endl
        << "  • 2 - Play against a friend" << std::endl
        << "  • 3 - Back" << std::endl
        << std::endl
        << "  > ";

    std::cin >> number_of_players;

    switch (number_of_players) {
    case 1:
    case 2:
    case 3:
      return number_of_players;

    default:
      std::cout << "Invalid input. Please enter 1 or 2." << std::endl;
    }
  }
}

// ─── Choose The Game Level ───────────────────────────────────────────────────

int choose_game_level() {
  int choice;

  while (true) {
    std::cout
        << "───────────────────────────────────────────────────────────────"
        << std::endl
        << "  Choose the game level:" << std::endl
        << "  • 1 - Easy" << std::endl
        << "  • 2 - Medium" << std::endl
        << "  • 3 - Hard" << std::endl
        << "  • 4 - Back" << std::endl
        << std::endl
        << "  > ";
    std::cin >> choice;

    switch (choice) {
    case 1:
    case 2:
    case 3:
    case 4:
      return choice;

    default:
      std::cout << "  ERROR: Invalid input. Please enter 1, 2, or 3."
                << std::endl
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

// ─── Main Setup ──────────────────────────────────────────────────────────────

void setup() {
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
