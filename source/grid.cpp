#include "grid.hpp"
#include "globals.hpp"
#include <iostream>

// ─── Allocates Memory For The Game Grid ──────────────────────────────────────

void allocate_grid() {
  grid = new char *[dimension];
  for (int i = 0; i < dimension; i++) {
    grid[i] = new char[dimension];
  }
}

// ─── Initializes The Game Grid With Empty Cells ──────────────────────────────

void initialize_grid() {
  for (int row = 0; row < dimension; row++) {
    for (int column = 0; column < dimension; column++) {
      grid[row][column] = '-';
    }
  }
}
// ─── Creates The Game Grid By Allocating Memory And Initializing Cells ───────

void create_grid() {
  allocate_grid();
  initialize_grid();
}
