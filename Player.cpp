#include "Player.h"
using namespace std;

Player::Player(){
	score = 0;
	easyScore = 0;
	medScore = 0;
	extremeScore = 0;
	AIScore = 0;
	this->playerName = "";
};

Player::Player(string name){
	score = 0;
	easyScore = 0;
	medScore = 0;
	extremeScore = 0;
	AIScore = 0;
	this->playerName = name;
};

string Player::getName(){
	return playerName;
};

void Player::setPlayerName(string playerName){
	this->playerName = playerName;
};

double Player::getScore(){
	return score;
}

double Player::getEasyScore(){
	return easyScore;
};

double Player::getMedScore(){
	return medScore;
};

double Player::getExtremeScore(){
	return extremeScore;
};

double Player::getAIScore(){
	return AIScore;
}

void Player::setScore(double score){
	this->score = score;
}

void Player::setEasyScore(double easyScore){
	this->easyScore = easyScore;
};

void Player::setMedScore(double medScore){
	this->medScore = medScore;
};

void Player::setExtremeScore(double extremeScore){
	this->extremeScore = extremeScore;
};

void Player::setAIScore(double AIScore){
	this->AIScore = AIScore;
}