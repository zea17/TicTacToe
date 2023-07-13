#include <iostream>
#include "setup.hpp"

int main()
{
    choose_dimension();
    if (choose_number_of_players() == 1)
    {

        chooseGameLevel();
    }
}
