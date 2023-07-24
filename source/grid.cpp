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
      grid[row][column] = EMPTY_VALUE;
    }
  }
}

// ─── Creates The Game Grid By Allocating Memory And Initializing Cells ───────

void create_grid() {
  allocate_grid();
  initialize_grid();
}

// ─── Get And Set Cell ────────────────────────────────────────────────────────

char get_cell_at(int number) {
  number--;
  int row = ceil(number / dimension);
  int column = (number - row * dimension);
  return grid[row][column];
}

void set_cell_at(int number, char value) {
  number--;
  int row = ceil(number / dimension);
  int column = (number - row * dimension);
  grid[row][column] = value;
}

// ─── Count Played Moves ──────────────────────────────────────────────────────

int count_played_moves() {
  int counter = 0;

  for (int row = 0; row < dimension; row++) {
    for (int column = 0; column < dimension; column++) {
      if (grid[row][column] != EMPTY_VALUE) {
        counter++;
      }
    }
  }

  return counter;
}