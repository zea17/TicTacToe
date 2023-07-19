#include <fstream>
#include <iostream>
#include <string>

#include "globals.hpp"
#include "storage_manager.hpp"

#define SETTING_FILE_PATH "~/.zeattt.txt"

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
  load_grid_state();
  setting_file.close();
}

void load_grid_state() {
  std::ifstream setting_file(SETTING_FILE_PATH);

  for (int row = 0; row < dimension; row++) {
    setting_file.getline(grid[row], dimension);
  }

  setting_file.close();
}

void save_state() {
  std::ofstream setting_file(SETTING_FILE_PATH);
  setting_file << dimension << std::endl
               << number_of_players << std::endl
               << game_level << std::endl;
  save_grid_state();
  setting_file.close();
}

void save_grid_state() {
  std::ofstream setting_file(SETTING_FILE_PATH);

  for (int row = 0; row < dimension; row++) {
    std::cout << grid[row] << std::endl;
  }

  setting_file.close();
}