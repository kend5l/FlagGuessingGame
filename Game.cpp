// Kendal Kyle
// Lab 7 Out
// multiple choice game using classes
#include <iostream>
#include "Game.h"
#include "graph1.h"
#include "Menu.h"
using namespace std;

Game::Game()
{
	no_correct = 0;
}

void Game::setMenu(Menu menu)
{
	this->menu.setSelection(menu.getSelection());
	this->menu.setConfig(menu.getConfig());

	
}

Menu Game::getMenu()
{
	return menu;
}

int Game::getNoCorrect()
{
	return no_correct;
}

int Game::play() 
{
	srand(time(0));
	
	int no_correct = 0;
	int selection = 0;

	for (int i = 0; i < menu.getConfig().getNoQuestions(); i++)
	{
		for (int j = 0; j < menu.getConfig().getNoChoices(); j++)
		{
			int index = rand() % menu.getConfig().getNoFlagNames();
			string flag_name = menu.getConfig().getFlagNameAt(index);
			menu.setChoice(j, flag_name);

		}
		// picks a correct flag out of the choices array
		int correct_flag = rand() % menu.getConfig().getNoChoices();
		string correct_flag_name = menu.getChoice(correct_flag);

		menu.displayFlag(correct_flag_name);

		gout << setPos(200, 30) << "Question #" << i + 1 << endg;
		menu.displayMenu();

		cout << "Enter selection: ";
		cin >> selection;
		menu.getSelection();

		if (selection - 1 == correct_flag)
		{
			no_correct += 1;
			gout << setPos(200, 450) << "CORRECT!!" << endg;
			Sleep(5000);
		}
		else
		{
			gout << setPos(200, 450) << "INCORRECT!!, The name of the correct flag is " << correct_flag_name << endg;
			Sleep(5000);
		}
		clearGraphics();
	}

	return no_correct;
	
}