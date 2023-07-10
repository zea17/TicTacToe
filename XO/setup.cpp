#include <iostream>
#include "setup.hpp"

// This function prompts the user to enter the dimensions of the Tic-Tac-Toe board
// and returns the entered size as an integer.

int dimention(){
    int size;
    std::cout << "Enter the dimensions of the Tic-Tac-Toe board: ";
    std::cin >> size;
    return size;
}
