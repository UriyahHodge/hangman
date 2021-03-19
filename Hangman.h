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

	int getWordLegth();

	std::string getGuessedWord();

	int getRemainingGuesses();

	void loseGuess(int);

	int getRemainingWarnings();

	void loseWarning();

	void resetWarnings();

	void addToLettersGuessed(char);

	bool isValidGuess(std::string);

	bool isDoubleGuess(char);

	bool isBadGuess(char);

	void dropFromLettersRemaining(char);

	std::string getLettersRemaining();

	int numUniqueLetters();

	int calculateTotal();

	void displayGameDetails();

};

#endif