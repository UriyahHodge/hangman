#ifndef HANGMAN_H
#define HANGMAN_H
#include "SecretWord.h"
#include <iostream>
#include <string>
#include <vector>


class Hangman 
{
private:
	SecretWord mySecretWord;
	int guessesRemaining;
	int warningsRemaining;
	std::string lettersRemaining;
	std::vector<std::string> lettersGuessed;

public:
	Hangman();
	Hangman(std::string);

	int getRemainingGuesses();
	bool loseGuess(int);

	int getRemainingWarnings();
	bool loseWarning();

	void addToLettersGuessed(std::string);

	void dropFromLettersRemaining(std::string);
	std::string getLettersRemaining();
};

#endif