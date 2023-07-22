#include <iostream>

#include "game.hpp"
#include "globals.hpp"
#include "grid.hpp"
#include "terminal.hpp"
#include "win_detector.hpp"

void prompt_and_play_for_user(char xo) {
  int cell_number = prompt_user_for_play(xo);
  if (get_cell_at(cell_number) == EMPTY_VALUE) {
    set_cell_at(cell_number, xo);
  } else {
    std::cout << "cell" << cell_number
              << " is already filled. please choose another number"
              << std::endl;
    prompt_and_play_for_user(xo);
  }
}

void game_loop() {
  char winner = EMPTY_VALUE;
  while (true) {
    clean_screen();
    render_game();
    prompt_and_play_for_user(X_VALUE);
    if ((winner = win_detector()) != EMPTY_VALUE) {
      std::cout << "winner is : " << winner << " :)" << std::endl;
      break;
    }
    render_game();
    if (number_of_players == 2) {
      prompt_and_play_for_user(O_VALUE);
      render_game();

      if ((winner = win_detector()) != EMPTY_VALUE) {
        std::cout << "winner is : " << winner << " :)" << std::endl;
        break;
      }

      win_detector();
    }
  }
}
