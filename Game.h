// Kendal Kyle
// Lab 7 Out
// multiple choice game using classes
#include <iostream>
using namespace std;
#include "Menu.h"

class Game
{
private:
    Menu menu;
    int no_correct;


public:
    Game();
    int play();
    void setMenu(Menu menu);
    Menu getMenu();
    int getNoCorrect();

};

#pragma once
