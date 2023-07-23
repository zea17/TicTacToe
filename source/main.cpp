#include "ai.hpp"
#include "game.hpp"
#include "globals.hpp"
#include "grid.hpp"
#include "setup.hpp"
#include "storage_manager.hpp"
#include "terminal.hpp"
#include "win_detector.hpp"
#include <ctime>
#include <iostream>

int main() {

  setup();
  game_loop();
}
