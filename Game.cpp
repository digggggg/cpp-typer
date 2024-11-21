#include "Game.h"
#include "Player.h"
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>
#include <conio.h>
#include <set>
using namespace std;

Game::Game(const Player &player){
	this->player = player;
	difficulty = 0;
	totalQuestions = 20;
}

void Game::setDifficulty(int difficulty){
	this->difficulty = difficulty;
}

Game::getDifficulty(){
	return difficulty;
}

string Game::getWordDB(){
	string wordFileName;
	switch (difficulty){
		case 1:
			wordFileName = "easy.txt";
			break;
		case 2:
			wordFileName = "medium.txt";
			break;
		case 3:
			wordFileName = "extreme.txt";
			break;
		case 4:
			wordFileName = "aihivemind.txt";
			break;
	}
	return wordFileName;
}

int Game::getWordDBSize(string fileName){
	fstream wordFile(fileName, ios::in);
	string line;
	int count = 0;
	while(getline(wordFile, line)){
		count++;
	}
	wordFile.close();
	return count;
}

void Game::fillWordList(string fileName, int totalWords){
	fstream wordDB(fileName, ios::in);
	string line;
	vector<string> allWords;
	while (getline(wordDB, line)){
		allWords.push_back(line);
	}
	wordDB.close();
	srand(time(0));
	int count = 0;
	set<int> wordPos;
	while (count < totalQuestions){
		int pos = rand() % totalWords;
		if (wordPos.find(pos) != wordPos.end()) continue;
		wordList.push_back(allWords[pos]);
		wordPos.insert(pos);
		count++;
	}
}

void Game::generateWords(){
	//cout << "Getting file name" << endl;
	string wordFileName = getWordDB();
	//cout << "Getting file length" << endl;
	int wordFileLength = getWordDBSize(wordFileName);
	//cout << "filling list" << endl;
	fillWordList(wordFileName, wordFileLength);
}

void Game::debugWords(){
	for (int i = 0; i < wordList.size(); i++){
		cout << wordList[i] << endl;
	}
}

void Game::displayRules(){
	cout << "Hello " << player.getName() << "!" << endl;
	cout << "You must try to type all the words within 30 seconds." << endl;
	cout << "If you fail then you will be a loser, haha." << endl;
	cout << "Score is calculated by total seconds taken to complete the typing challenge." << endl;
	cout << "So the lower your score the better you did." << endl;
	cout << "Press the any key to continue..." << endl;
	_getch();
	system("cls");
}

void Game::askDifficulty(){
	cout << "What difficulty would you like to play on" << endl;
	cout << "1. Easy" << endl;
	cout << "2. Medium" << endl;
	cout << "3. Extreme" << endl;
	cout << "4. AI Hive Mind" << endl;
	cout << "Press numbers 1-4 to select difficulty" << endl;
	int answer;
	cin >> answer;
	while(answer < 0 || answer > 4 ){
		cout << "Please enter a valid selection" << endl;
		cout << "Press numbers 1-4 to select difficulty" << endl;
		cin >> answer;
	}
	difficulty = answer;
}

void Game::countDown(){
	system("cls");
	cout << "We will begin shortly" << endl;
	this_thread::sleep_for(std::chrono::seconds(2));
	cout << "3" << endl;
	this_thread::sleep_for(std::chrono::seconds(1));
	cout << "2" << endl;
	this_thread::sleep_for(std::chrono::seconds(1));
	cout << "1" << endl;
	this_thread::sleep_for(std::chrono::seconds(1));
	system("cls");
}

void Game::loopQuestions(){
	string line;
	for (int i = 0; i < wordList.size(); i++){
		cout << "Word " << i + 1 << ": " << wordList[i] << endl;
		if (i == 0) cin.ignore();
		cout << endl <<"Type the word here: " << endl;
		getline(std::cin, line);
		while(line != wordList[i]){
			cout << "Incorrect try again" << endl;
			cout << endl <<"Type the word here: " << endl;
			std::getline(std::cin, line);
		}
		system("cls");
	}
}

double Game::activeGame(){
	auto startTime = chrono::steady_clock::now();
	loopQuestions();
	auto endTime = chrono::steady_clock::now();
	chrono::duration<double> duration = endTime - startTime;
	return duration.count();
}

bool Game::checkHighScore(){
	bool highscore = false;
	double lastPlayerScore = player.getScore();
	switch (difficulty){
		case 1:
			if (lastPlayerScore > player.getEasyScore()){
				player.setEasyScore(lastPlayerScore);
				highscore = true;	
			}
			break;
		case 2:
			if (lastPlayerScore > player.getMedScore()){
				player.setMedScore(lastPlayerScore);
				highscore = true;	
			}
			break;
		case 3:
			if (lastPlayerScore > player.getExtremeScore()){
				player.setExtremeScore(lastPlayerScore);
				highscore = true;	
			}
			break;
		case 4:
			if (lastPlayerScore > player.getAIScore()){
				player.setAIScore(lastPlayerScore);
				highscore = true;	
			}
			break;
	}
	return highscore;
}

void Game::showPlayerHighScores(){
	system("cls");
	cout << player.getName() << " these are your highscores" << endl << endl;
	cout << "Easy Highscore: " << std::fixed << std::setprecision(3) << player.getEasyScore() << endl;
	cout << "Medium Highscore: " << std::fixed << std::setprecision(3) << player.getMedScore() << endl;
	cout << "Extreme Highscore: " << std::fixed << std::setprecision(3) << player.getExtremeScore() << endl;
	cout << "AI Hive Mind Highscore: " << player.getAIScore() << endl;
	cout << endl <<"Press any key to return to the main menu..." << endl;
	_getch();
	menu();
}

void Game::handleMenuSelection(){
	int selection;
	cin >> selection;
	switch (selection){
		case 1: 
			startGame();
			break;
		case 2: 
			showPlayerHighScores();
			break;
		case 4: 
			break;
		default:
			system("cls");
			menu();
			break;
	}
}

void Game::menu(){
	system("cls");
	cout << "CMD Prompt Typing!" << endl;
	cout << "1. New Game" << endl;
	cout << "2. Your Highscores" << endl;
	cout << "3. All-Time Scores (not implemented)" << endl;
	cout << "4. Exit" << endl;
	handleMenuSelection();
}

void Game::completionMessage(bool isHighScore){
	if (isHighScore) cout << "Congrats on the new highscore!" << endl;
	cout << "Your score was " << std::fixed << std::setprecision(3) << player.getScore() << endl;
	if (player.getScore() >= 30) cout << "Im sorry you were just too slow" << endl;
	cout << "Press any key to go back to the main menu..." << endl;
	_getch();
}

void Game::startGame(){
	system("cls");
	displayRules();
	askDifficulty();
	generateWords();
	countDown();
	double score = activeGame();
	player.setScore(score);
	bool isHighScore = checkHighScore();
	completionMessage(isHighScore);
	menu();
}