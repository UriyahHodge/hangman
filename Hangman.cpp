#include "Hangman.h"
#include <algorithm>

Hangman::Hangman() : guessesRemaining(6), warningsRemaining(3), lettersRemaining("abcdefghijklmnopqrstuvwxyz"), mySecretWord(SecretWord())
{
	
}

Hangman::Hangman(std::string secretWord) : guessesRemaining(6), warningsRemaining(3), lettersRemaining("abcdefghijklmnopqrstuvwxyz"), mySecretWord(SecretWord(secretWord))
{

}


bool Hangman::isWordGuessed()
{
	
	bool isGuessed = true;
	std::string secretWord = mySecretWord.getWord();
	
	for (int i = 0; i < mySecretWord.getLength(); ++i)
	{
		if (std::find(lettersGuessed.begin(), lettersGuessed.end(), secretWord[i]) == lettersGuessed.end())
			isGuessed = false;
	}
	
	return isGuessed;
	
}


std::string Hangman::getSecretWord()
{
	return mySecretWord.getWord();
}

std::string Hangman::getGuessedWord()
{
	return mySecretWord.getWordWithGaps(lettersGuessed);
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

void Hangman::addToLettersGuessed(char cur_guess)
{
	lettersGuessed.push_back(cur_guess);
}

void Hangman::dropFromLettersRemaining(char cur_guess)
{
	lettersRemaining.erase(lettersRemaining.find(cur_guess));
}

std::string Hangman::getLettersRemaining()
{
	return lettersRemaining;
}

void Hangman::start()
{
	//while loop until guesses run out or the secret word is guessed
}

int Hangman::numUniqueLetters()
{
	std::vector<char> uniqueLetters;

	//iterate through each character of secretWord.
	//for each char, if not alread in uniqueLetters, then add letter to list

	//return length/size of vector
	return 0;
}

int Hangman::calculateTotal()
{
	return guessesRemaining * numUniqueLetters();
}
