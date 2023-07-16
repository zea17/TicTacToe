#include <fstream>
#include <iostream>
#include <string>
#include "storage_manager.hpp"

#define SETTING_FILE_PATH "~/.zeattt.txt"

bool does_state_exists()
{
    std::ifstream settings_file;
    settings_file.open(SETTING_FILE_PATH, std::ios::in);
    if (settings_file.fail())
    {
        return false;
    }
    return true;
}

void load_state()
{
    std::fstream settings_file;
    settings_file.open(SETTING_FILE_PATH, std::ios::in);
}