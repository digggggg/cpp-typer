#ifndef PLAYER_H
#define PLAYER_H
#include <string>
using namespace std;

class Player {
	private: 
		double score;
		double easyScore;
		double medScore;
		double extremeScore;
		double AIScore;
		string playerName;
	public:
		Player();
		Player(string name);
		string getName();
		void setPlayerName(string name);
		double getScore();
		double getEasyScore();
		double getMedScore();
		double getExtremeScore();
		double getAIScore();
		void setAIScore(double AIScore);
		void setScore(double score);
		void setEasyScore(double easyScore);
		void setMedScore(double medScore);
		void setExtremeScore(double extremeScore);
};

#endif