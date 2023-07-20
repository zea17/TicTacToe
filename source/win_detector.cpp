#include "win_detector.hpp"
#include "globals.hpp"
#include "grid.hpp"

int check_vertical_tie() {
  for (int column = 0; column < dimension; column++) {
    int first_element = grid[0][column];
    bool is_tie = true;
    for (int row = 1; row < dimension; row++) {
      if (grid[row][column] != first_element) {
        is_tie = false;
        break;
      }
    }
    if (is_tie) {
      return column;
    }
  }
  return -1;
}
