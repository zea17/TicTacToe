#include <iostream>

#include "game.hpp"
#include "globals.hpp"
#include "grid.hpp"
#include "terminal.hpp"

void prompt_and_play_for_user(char xo) {
  int cell_number = prompt_user_for_play(xo);
  if (get_cell_at(cell_number) == EMPTY_VALUE)
    set_cell_at(cell_number, xo);
  else {
    std::cout << "cell" << cell_number
              << " is already filled. please choose another number"
              << std::endl;
    prompt_and_play_for_user(xo);
  }
}

void game_loop() {
  while (true) {
    clean_screen();
    render_game();
  }
}
