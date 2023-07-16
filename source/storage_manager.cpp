#include <fstream>
#include <iostream>
#include <string>

#include "storage_manager.hpp"
#include "globals.hpp"

#define SETTING_FILE_PATH "~/.zeattt.txt"

//

bool does_state_exists()
{
    std::ifstream settings_file;
    settings_file.open(SETTING_FILE_PATH, std::ios::in);
    return !settings_file.fail();
}

void load_state()
{
    std::fstream settings_file;
    settings_file.open(SETTING_FILE_PATH, std::ios::in);
}

void save_state()
{
    std::ofstream setting_file(SETTING_FILE_PATH);
    setting_file << dimension << std::endl
                 << number_of_players << std::endl
                 << game_level << std::endl;
}
