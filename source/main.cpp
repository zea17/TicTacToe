#include <iostream>

#include "globals.hpp"
#include "grid.hpp"
#include "setup.hpp"
#include "storage_manager.hpp"
#include "terminal.hpp"
#include "win_detector.hpp"

int main() {
  // setup();
  setup();
  render_game();
  save_state();
  std::cout << detect_ltr_diagonal_win() << " :  " << winning_ltr_diagonal
            << std::endl;

  std::cout << detect_rtl_diagonal_win() << " :  " << winning_rtl_diagonal
            << std::endl;
  std::cout << detect_column_win() << " :  " << winning_column << std::endl;

  std::cout << detect_row_win() << "  :  " << winning_row << std::endl;
  std::cout << "the winner is : " << win_detector() << std::endl;
}
