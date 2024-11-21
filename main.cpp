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
using namespace std;

void displayStartMessage(){
	cout << "Welcome to CMD Prompt Typing!" << endl;
	cout << "Enter your name: ";
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