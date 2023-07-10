#include <iostream>
#include "setup.hpp"

// This function prompts the user to enter the dimensions of the Tic-Tac-Toe board
// and returns the entered size as an integer.

int choose_dimention(){
    int size;
    std::cout << "Enter the dimensions of the Tic-Tac-Toe board: ";
    std::cin >> size;
    return size;
}

int choose_number_of_players() {
  int number_of_players;

  while (true) {
    std::cout << "Choose the number of players:" << std::endl;
    std::cout << "1 - Play against the computer" << std::endl;
    std::cout << "2 - Play against a friend" << std::endl;
    std::cin >> number_of_players;

    switch (number_of_players) {
      case 1:
      case 2:
        return number_of_players;
      default:
        std::cout << "Invalid input. Please enter 1 or 2." << std::endl;
    }
  }
}
