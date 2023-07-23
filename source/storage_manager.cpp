#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>

#include "globals.hpp"
#include "grid.hpp"
#include "storage_manager.hpp"

#define SETTING_FILE_PATH ".zeattt.txt"

// ─── Checks If A Saved Game State Exists ─────────────────────────────────────

bool does_state_exists() {
  std::ifstream settings_file;
  settings_file.open(SETTING_FILE_PATH, std::ios::in);
  return !settings_file.fail();
}

// ─── Storing State ───────────────────────────────────────────────────────────

/// @brief loads the state of the game from the storage file
void load_state() {

  // The first line in the file is the dimension of the game grid
  // The second line in the file is the number of players
  // The third line in the file is the game level
  // The forth line in the file is player who's turn is right now
  // The remaining lines in the file are the contents of the game grid

  std::ifstream setting_file(SETTING_FILE_PATH);

  setting_file >> dimension >> number_of_players >> game_level >> current_turn;

  allocate_grid();
  for (int row = 0; row < dimension; row++) {
    setting_file >> grid[row];
  }

  setting_file.close();
}

void save_state() {
  std::ofstream setting_file(SETTING_FILE_PATH);
  setting_file << dimension << std::endl
               << number_of_players << std::endl
               << game_level << std::endl
               << current_turn << std::endl;

  for (int row = 0; row < dimension; row++) {
    setting_file << grid[row] << std::endl;
  }

  setting_file.close();
}

void delete_state() {
  std::ofstream ofs(SETTING_FILE_PATH);
  ofs.close();
  std::remove(SETTING_FILE_PATH);
}
