// Kendal Kyle
// Lab 7 Out
// multiple choice game using classes
#include <iostream>
using namespace std;
#include "Menu.h"
#include "graph1.h"


Menu::Menu()
{
    choices = NULL;
    selection = 0;
}

Menu::~Menu()
{
    delete[] choices;
}

Menu::Menu(const Menu& menu)
{

    this->setConfig(menu.config);
    this->selection = menu.selection;

    // dynamically allocate all pointers of this
    // copy conents of the choices array of menu to the choices array of this

    for (int i = 0; i < config.getNoChoices(); i++)
    {
        this->choices[i] = menu.choices[i]; 
    }
    
}

void Menu::setConfig(Configuration config)
{
    this->config.setNoQuestions(config.getNoQuestions());
    this->config.setNoChoices(config.getNoChoices());
    this->config.setNoFlagNames(config.getNoFlagNames());

    //set each flag name 
    for (int i = 0; i < this->config.getNoFlagNames(); i++)
    {
        this->config.setFlagNameAt(config.getFlagNameAt(i), i);
    }

    this->choices = new string[config.getNoChoices()];
}

void Menu::setSelection(int selection)
{
    this->selection = selection;
}

void Menu::setChoice(int index, string flag_name)
{
    choices[index] = flag_name;
}

string Menu::getChoice(int index)
{
    return choices[index];
}

int Menu::getSelection()
{
    return selection;
}

Configuration Menu::getConfig()
{
    return config;
}

int Menu::displayMenu()
{
    int input = 0;
    int obj = 0;
    int y = 235;
    
        gout << setPos(200, 220) << "Choose from the following: " << endg;
    
        for (int j = 0; j < config.getNoChoices(); j++)
        {
            // draws rectangles
            obj = drawRect(200, y, 300, 20);
            setColor(obj, 128, 128, 128);
            // displays choices
            gout << setPos(200, y + 10) << j + 1 << ": " << getChoice(j) << endg;
            y += 30;
        }

        gout << setPos(200, y + 50) << "Enter choice on console" << endg;
    
    return input;
}

void Menu::displayFlag(string flag_name)
{
    displayBMP(flag_name + ".bmp", 200, 50);
}