#include <iostream>

#include "globals.hpp"
#include "grid.hpp"
#include "setup.hpp"
#include "storage_manager.hpp"
#include "terminal.hpp"

int main() {
  // setup();
  setup();
  create_grid();
  render_game();
}
