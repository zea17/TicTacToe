#include <iostream>
#include <stdlib.h>

#include "globals.hpp"
#include "setup.hpp"
#include "terminal.hpp"

// This function prompts the user to enter the dimensions of the Tic-Tac-Toe
// board and returns the entered size as an integer.

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

// This function prompts the user to choose the number of players for a
// Tic-Tac-Toe game and returns the entered number as an integer. Use a while
// loop to repeatedly prompt the user for input until a valid input Display the
// options for the number of players If the input is anything else, display an
// error message and ask the user to enter the number of players again

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

// This function prompts the user to choose the game level for a Tic-Tac-Toe
// game and returns the entered level as an integer (1 for Easy, 2 for Medium, 3
// for Hard).

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

void setup() {
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