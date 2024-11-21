/*
	Name: CLI typing game
	Copyright: MIT
	Author: Jonathan Mengel (digggggg)
	Date: 20/11/24 21:21
	Description: Console Typing game
*/
#include <iostream>
#include "Player.h"
#include "Game.h"
#include <iomanip>
using namespace std;

void printCenteredText(const string& text) {
    // Get the console width (assume 80 columns for simplicity, typical for many terminals)
    const int consoleWidth = 110;

    // Calculate padding needed to center the text
    int padding = (consoleWidth - text.length()) / 2;

    // Print the text with padding
    cout << setw(padding + text.length()) << text << endl;
}

void displayStartMessage(){
	string line1 = "Welcome to CMD Prompt Typing!";
	string line2 = "Enter your name: ";
	printCenteredText(line1);
	printCenteredText(line2);
}

int main(int argc, char** argv) {
	displayStartMessage();
	string name;
	getline(cin, name);
	Player player = Player(name);
	Game game = Game(player);
	game.menu();
	//game.debugWords();	
	return 0;
}