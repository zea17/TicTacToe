#include "grid.hpp"
#include "globals.hpp"
#include <iostream>

void allocate_grid() {
  grid = new char *[dimension];
  for (int i = 0; i < dimension; i++) {
    grid[i] = new char[dimension];
  }
}

void initialize_grid() {
  for (int row = 0; row < dimension; row++) {
    for (int column = 0; column < dimension; column++) {
      grid[row][column] = '-';
    }
  }
}

void create_grid() {
  allocate_grid();
  initialize_grid();
}
