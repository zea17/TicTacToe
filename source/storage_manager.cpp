#include <fstream>
#include <iostream>
#include <string>

#include "globals.hpp"
#include "storage_manager.hpp"

#define SETTING_FILE_PATH ".zeattt.txt"

bool does_state_exists() {
  std::ifstream settings_file;
  settings_file.open(SETTING_FILE_PATH, std::ios::in);
  return !settings_file.fail();
}
// line 1 = dimension
// line 2 = number of players
// line 3 = game level
//
void load_state() {
  std::ifstream setting_file(SETTING_FILE_PATH);
  setting_file >> dimension >> number_of_players >> game_level;
  for (int row = 0; row < dimension; row++) {
    setting_file >> grid[row];
  }

  setting_file.close();
}

void save_state() {
  std::ofstream setting_file(SETTING_FILE_PATH);
  setting_file << dimension << std::endl
               << number_of_players << std::endl
               << game_level << std::endl;

  for (int row = 0; row < dimension; row++) {
    setting_file << grid[row] << std::endl;
  }

  setting_file.close();
}
