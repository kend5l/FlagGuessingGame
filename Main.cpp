// Kendal Kyle
// Lab 7 Out
// multiple choice game using classes

#include <iostream>
#include <string>
#include "configuration.h"
#include "Menu.h"
#include "Game.h"
#include "graph1.h"
using namespace std;



int main()
{
	// decleration
	string names[] = { "Afghanistan", "Albania", "Algeria", "American_Samoa", "Andorra", "Angola", "Anguilla",
"Antigua_and_Barbuda", "Argentina","Armenia", "Aruba","Australia", "Austria","Azerbaijan",
"Bahamas", "Bahrain", "Bangladesh", "Barbados", "Belarus", "Belgium", "Belize", "Benin",
	  "Bermuda", "Bhutan", "Bolivia", "Bosnia", "Botswana", "Brazil", "British_Virgin_Islands",
 "Brunei", "Bulgaria", "Burkina_Faso", "Burundi", "Cambodia", "Cameroon", "Canada", "Cape_Verde","Cayman_Islands", "Central_African_Republic", "Chad", "Chile", "China","Christmas_Island",
"Colombia","Comoros","Cook_Islands","Costa_Rica","Croatia","Cuba","Cyprus","Cyprus_Northern",
"Czech_Republic","Cte_dIvoire","Democratic_Republic_of_the_Congo","Denmark","Djibouti","Dominica",
"Dominican_Republic","Ecuador","Egypt","El_Salvador","Equatorial_Guinea","Eritrea","Estonia",
"Ethiopia","Falkland_Islands","Faroe_Islands","Fiji","Finland","France","French_Polynesia",
"Gabon","Gambia","Georgia","Germany","Ghana","Gibraltar","Greece","Greenland","Grenada",
"Guam","Guatemala","Guinea","Guinea_Bissau","Guyana","Haiti","Honduras","Hong_Kong","Hungary",
"Iceland", "India","Indonesia","Iran","Iraq", "Ireland","Israel","Italy","Jamaica","Japan",
"Jordan", "Kazakhstan","Kenya","Kiribati","Kuwait","Kyrgyzstan","Laos","Latvia","Lebanon",
"Lesotho","Liberia","Libya","Liechtenstein","Lithuania","Luxembourg","Macao","Macedonia",
"Madagascar","Malawi","Malaysia","Maldives","Mali","Malta","Marshall_Islands","Martinique",
"Mauritania","Mauritius","Mexico","Micronesia","Moldova","Monaco","Mongolia","Montserrat",
"Morocco","Mozambique","Myanmar","Namibia","Nauru","Nepal","Netherlands","Netherlands_Antilles",
"New_Zealand", "Nicaragua","Niger","Nigeria","Niue","Norfolk_Island","North_Korea","Norway",
"Oman","Pakistan","Palau","Panama","Papua_New_Guinea","Paraguay","Peru","Philippines",
"Pitcairn_Islands","Poland","Portugal","Puerto_Rico","Qatar","Republic_of_the_Congo","Romania",
"Russian_Federation","Rwanda","Saint_Kitts_and_Nevis","Saint_Lucia","Saint_Pierre","Saint_Vicent_and_the_Grenadines",
"Samoa","San_Marino","Sao_Tom�_and_Prncipe","Saudi_Arabia","Senegal","Serbia_and_Montenegro",
"Seychelles", "Sierra_Leone", "Singapore","Slovakia","Slovenia","Soloman_Islands","Somalia",
"South_Africa","South_Georgia","South_Korea","Soviet_Union","Spain","Sri_Lanka","Sudan","Suriname",
"Swaziland","Sweden","Switzerland","Syria", "Taiwan","Tajikistan","Tanzania","Thailand",
"Tibet", "Timor-Leste", "Togo","Tonga","Trinidad_and_Tobago","Tunisia", "Turkey","Turkmenistan",
"Turks_and_Caicos_Islands", "Tuvalu","UAE","Uganda","Ukraine","United_Kingdom","United_States_of_America",
"Uruguay","US_Virgin_Islands","Uzbekistan","Vanuatu","Vatican_City","Venezuela","Vietnam",
"Wallis_and_Futuna","Yemen","Zambia","Zimbabwe" };
	int noChoices = 0;
	int noQuestions = 0;
	int no_questions = 0;
	int no_choices = 0;
	string flagNames;
	double no_correct = 0;
	char repeat = 'y';
	srand(time(0));
	displayGraphics();
	// sets configuration
	Configuration config(names, 224);
	// repeat loop
	do
	{
		// prompts for questions
		do
		{
			cout << "Enter # of questions for the quiz: ";
			cin >> no_questions;

		} while (!config.setNoQuestions(no_questions));
		noQuestions = config.getNoQuestions();
		// prompts for choices
		do
		{
			cout << "Enter # of choices per question: ";
			cin >> no_choices;
		} while (!config.setNoChoices(no_choices));
		noChoices = config.getNoChoices();
		// sets menu
		Menu menu;
		// sets config within menu
		menu.setConfig(config);
		// sets game
		Game game;
		// sets menu within game
		game.setMenu(menu);
		// plays game and returns no correct
		no_correct = game.play();
		// displays stats
		gout << setPos(250, 200) << "Quiz Over!" << endg;
		gout << setPos(250, 230) << "Your Percentage: %" << (no_correct / config.getNoQuestions()) * 100 << endg;
		// repeat prompt
		cout << "Wish to repeat? (y or n): ";
		cin >> repeat;

		if (repeat == 'y' || repeat == 'Y')
		{
			clearGraphics();
			system("cls");
		}

	} while (repeat == 'y' || repeat == 'Y');
}