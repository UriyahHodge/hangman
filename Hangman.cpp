#include "Hangman.h"

Hangman::Hangman() : guessesRemaining(6), warningsRemaining(3), lettersRemaining("abcdefghijklmnopqrstuvwxyz"), mySecretWord(SecretWord())
{
	
}

Hangman::Hangman(std::string secretWord) : guessesRemaining(6), warningsRemaining(3), lettersRemaining("abcdefghijklmnopqrstuvwxyz"), mySecretWord(SecretWord(secretWord))
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

void Hangman::addToLettersGuessed(std::string cur_guess)
{
	lettersGuessed.push_back(cur_guess);
}

void Hangman::dropFromLettersRemaining(std::string cur_guess)
{
	lettersRemaining.erase(lettersRemaining.find(cur_guess));
}

std::string Hangman::getLettersRemaining()
{
	return lettersRemaining;
}
