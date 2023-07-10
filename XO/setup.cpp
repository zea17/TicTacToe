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

// This function prompts the user to choose the number of players for a Tic-Tac-Toe game
// and returns the entered number as an integer.

int choose_number_of_players() {
  int number_of_players;
    
// Use a while loop to repeatedly prompt the user for input until a valid input
    
  while (true) {
      
// Display the options for the number of players
 
    std::cout << "Choose the number of players:" << std::endl;
    std::cout << "1 - Play against the computer" << std::endl;
    std::cout << "2 - Play against a friend" << std::endl;
    std::cin >> number_of_players;

    switch (number_of_players) {
      case 1:
      case 2:
        return number_of_players;
      default:
            
// If the input is anything else, display an error message and ask the user to enter the number of players again

        std::cout << "Invalid input. Please enter 1 or 2." << std::endl;
    }
  }
}
