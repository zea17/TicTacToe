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

  std::cout << "Would you like to load your previous game or start a new one?"
            << std::endl
            << "1 for yes" << std::endl
            << "anything else for no" << std::endl;

  std::cin >> should_continue;
  return should_continue == 1;
}

// ─── Dimension Of The Tic-tac-toe ────────────────────────────────────────────

int choose_dimension() {
  int size;

  while (true) {
    std::cout << "Enter the dimensions of the Tic-Tac-Toe board: ";
    std::cin >> size;

    if (size > 2) {
      return size;
    }

    std::cout << "The dimension must be greater that 3." << std::endl;
  }

  return size;
}

// ─── Choose The Number Of Players ────────────────────────────────────────────

int choose_number_of_players() {
  int number_of_players;

  while (true) {
    std::cout << "Choose the number of players:" << std::endl;
    std::cout << "1 - Play against the computer" << std::endl;
    std::cout << "2 - Play against a friend" << std::endl;
    std::cout << "3 - Back" << std::endl;

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
    std::cout << "Choose the game level:" << std::endl;
    std::cout << "1 - Easy" << std::endl;
    std::cout << "2 - Medium" << std::endl;
    std::cout << "3 - Hard" << std::endl;
    std::cout << "4 - Back" << std::endl;
    std::cin >> choice;

    switch (choice) {
    case 1:
    case 2:
    case 3:
    case 4:
      return choice;

    default:
      std::cout << "Invalid input. Please enter 1, 2, or 3." << std::endl
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
