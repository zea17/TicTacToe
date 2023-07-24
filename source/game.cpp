#include <iostream>

#include "ai.hpp"
#include "game.hpp"
#include "globals.hpp"
#include "grid.hpp"
#include "storage_manager.hpp"
#include "terminal.hpp"
#include "win_detector.hpp"

// ─── Prompting The User ──────────────────────────────────────────────────────

void prompt_and_play_for_user(char xo) {
  int cell_number = prompt_user_for_play(xo);

  if (get_cell_at(cell_number) == EMPTY_VALUE) {
    set_cell_at(cell_number, xo);
  }

  else {
    std::cout << "  Cell" << cell_number << " is already filled." << std::endl
              << "  please choose another number" << std::endl;

    prompt_and_play_for_user(xo);
  }
}

// ─── Win And Tie Messages ────────────────────────────────────────────────────

bool show_win_message_if_win_exist() {
  char winner;
  if ((winner = detect_win()) == EMPTY_VALUE) {
    return false;
  }

  render_game();

  std::cout << "  Winner is : " << winner << " :)" << std::endl << std::endl;

  return true;
}

bool show_tie_message() {
  if (detect_tie() == false) {
    return false;
  }

  render_game();
  std::cout << "  Sorry but nobody won :(" << std::endl
            << "  Maybe next time? " << std::endl
            << std::endl;

  return true;
}

// ─── Main Game Loop ──────────────────────────────────────────────────────────

void game_loop() {
  char winner = EMPTY_VALUE;

  while (true) {
    // Rendering game
    render_game();

    // If it's X's Turn
    if (current_turn == X_VALUE) {
      prompt_and_play_for_user(X_VALUE);
      current_turn = O_VALUE;
    }

    // If it's O's Turn
    else {
      if (number_of_players == 2) {
        prompt_and_play_for_user(O_VALUE);
      } else {
        play_with_ai(O_VALUE);
      }
      current_turn = X_VALUE;
    }

    // Checking if the game has to be stopped:
    if (show_win_message_if_win_exist() || show_tie_message()) {
      delete_state();
      break;
    }

    // saving the state
    save_state();
  }
}
