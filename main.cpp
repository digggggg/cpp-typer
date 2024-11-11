#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <string>
#include <fstream>
#include <iomanip>

/*
Refactor this into a class based OOP style program and add some finishing touches

Game class control the actual game, display text, start, end, etc
Player class get player information like get name, get score
Highscore class grab plyer and write the scores to a text file

*/

using std::cout;
using std::endl;

void showHighscore(){
	// stub
}

void displayStartMessage(){
	cout << "Welcome to CMD Prompt Typing" << endl;
	cout << "Press s to start and q to quit" << endl;
}

void generateWords(std::string wordList[], int size){
	std::fstream wordFile("words.txt", std::ios::in);
	std::string line;
	for (int i = 0; i < size; i++){
		std::getline(wordFile, line);
		wordList[i] = line;
	}
	wordFile.close();
}

void displayRules(){
	cout << "You must try to type all the words within 30 seconds" << endl;
	cout << "If you fail then you will lose" << endl;
	cout << "Score is calculated by total seconds taken to complete the typing challenge" << endl;
	cout << "We will begin shortly" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));
	cout << "3" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	cout << "2" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	cout << "1" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	system("cls");
}

void gameStart(){
	const int QUESTIONS = 5;
	std::string wordList[QUESTIONS];
	generateWords(wordList, QUESTIONS);
	displayRules();
	std::string line;
	auto start = std::chrono::steady_clock::now();
	for (int i = 0; i < QUESTIONS; i++){
		cout << "Word " << i + 1 << ": " << wordList[i] << endl;
		if (i == 0) std::cin.ignore();
		std::getline(std::cin, line);
		cout << endl <<"This is line: " << line << endl;
		while(line != wordList[i]){
			cout << "Incorrect try again" << endl;
			std::getline(std::cin, line);
		}
		system("cls");
	}
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> duration = end - start;
	cout << "You took " << std::fixed << std::setprecision(3) << duration.count() << " seconds to finish" << endl;
	if (duration.count() >= 30) cout << "Im sorry you were just too slow" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(5));
	system("cls");
}

bool validateMenuSelect(char letter){
	if (letter == 's' || letter == 'q' || letter == 'h'){
		return false;
	} else {
		return true;
	}
}

void handleGame(){
	char playerInput;
	std::cin >> playerInput;
	while(validateMenuSelect(playerInput)){
		cout << "Invalid Input" << endl;
		cout << "Please enter 's' 'q' 'h'" << endl;
		std::cin >> playerInput;
	}
	
	switch (playerInput){
		case 's':
			system("cls");
			gameStart();
			displayStartMessage();
			handleGame();
			break;
		case 'q':
			break;
		case 'h':
			showHighscore();
			break;
	}
}

int main(int argc, char** argv) {
	displayStartMessage();
	handleGame();
	return 0;
}