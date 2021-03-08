#include "Hangman.h"

Hangman::Hangman() : guessesRemaining(6), warningsRemaining(3), mySecretWord(SecretWord())
{
}

Hangman::Hangman(std::string secretWord) : guessesRemaining(6), warningsRemaining(3), mySecretWord(SecretWord(secretWord))
{
}

int Hangman::getRemainingGuesses()
{
	return guessesRemaining;
}

bool Hangman::loseGuess(int loseValue)
{
	bool canLoseGuess = guessesRemaining > 0;

	if (canLoseGuess)
		guessesRemaining = guessesRemaining - loseValue;
	
	return canLoseGuess;
}

int Hangman::getRemainingWarnings()
{
	return warningsRemaining;
}

bool Hangman::loseWarning()
{
	bool canLoseWarning = (warningsRemaining - 1 >= 0);

	if (canLoseWarning)
		--warningsRemaining;

	return canLoseWarning;
}

void Hangman::addLetterToLettersGuessed(char cur_guess)
{
	lettersGuessed.push_back(cur_guess);
}
