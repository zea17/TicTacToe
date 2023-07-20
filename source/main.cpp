#include <iostream>

#include "globals.hpp"
#include "grid.hpp"
#include "setup.hpp"
#include "storage_manager.hpp"
#include "terminal.hpp"

int main() {
  // setup();
  setup();
  render_game();
  save_state();
}
