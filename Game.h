#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include <string>
#include <vector>
using namespace std;

class Game{
	private:
		int totalQuestions;
		Player player;
		int difficulty;
		vector<string> wordList;
		string getWordDB();
		int getWordDBSize(string fileName);
		void fillWordList(string fileName, int totalWords);
		void displayRules();
		void askDifficulty();
		void debugWords();
		void generateWords();
		void countDown();
		double activeGame();
		void loopQuestions();
		bool checkHighScore();
		void handleMenuSelection();
		void showPlayerHighScores();
		void startGame();
		void completionMessage(bool isHighScore);
	public:
		Game(const Player &player);
		void setDifficulty(int difficulty);
		int getDifficulty();
		void menu();
};

#endif