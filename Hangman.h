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
	std::vector<char> lettersGuessed;

public:
	Hangman();
	Hangman(std::string);

	bool isWordGuessed();
	std::string getSecretWord();
	std::string getGuessedWord();

	int getRemainingGuesses();
	bool loseGuess(int);

	int getRemainingWarnings();
	bool loseWarning();

	void addToLettersGuessed(char);

	void dropFromLettersRemaining(char);
	std::string getLettersRemaining();


};

#endif