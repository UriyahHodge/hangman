#include "Hangman.h"
#include <algorithm>
#include <cctype>

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

void Hangman::loseGuess(int loseValue)
{
		guessesRemaining = guessesRemaining - loseValue;
}

int Hangman::getRemainingWarnings()
{
	return warningsRemaining;
}

void Hangman::loseWarning()
{
	--warningsRemaining;
}

void Hangman::resetWarnings()
{
	warningsRemaining = 0;
}

void Hangman::addToLettersGuessed(char cur_guess)
{
	lettersGuessed.push_back(cur_guess);
}

bool Hangman::isValidGuess(std::string letterGuessed)
{
	return( (letterGuessed.length() == 1)
			& ((letterGuessed[0] == '*')
			|| (isalpha(letterGuessed[0])))
	);
}

bool Hangman::isDoubleGuess(char letterGuessed)
{
	return (std::find(lettersGuessed.begin(), lettersGuessed.end(), letterGuessed) == lettersGuessed.end());
}

bool Hangman::isBadGuess(char letterGuessed)
{
	bool isBad = false;

	if (std::find(mySecretWord.getWord().begin(), mySecretWord.getWord().end(), letterGuessed) == mySecretWord.getWord().end())
	{
		isBad = true;
	}
		
	return isBad;
}

void Hangman::dropFromLettersRemaining(char cur_guess)
{
	lettersRemaining.erase(lettersRemaining.find(cur_guess));
}

std::string Hangman::getLettersRemaining()
{
	return lettersRemaining;
}

int Hangman::numUniqueLetters()
{
	std::vector<char> uniqueLetters;
	std::string secretWord = mySecretWord.getWord();

	//iterate through each character of secretWord.
	for (int i = 0; i < secretWord.length(); ++i)
	{
		//for each char, if not already in uniqueLetters, then add letter to list of uniqueLetters
		if (std::find(uniqueLetters.begin(), uniqueLetters.end(), secretWord[i]) == uniqueLetters.end())
			uniqueLetters.push_back(secretWord[i]);
	}
	
	
	//return length/size of vector
	return uniqueLetters.size();
}

int Hangman::calculateTotal()
{
	return guessesRemaining * numUniqueLetters();
}

void Hangman::displayGameDetails()
{
	std::cout << "--------------------" << std::endl;
	std::cout << "You have " << guessesRemaining << " guesses left." << std::endl;
	std::cout << "Letters remaining: " << lettersRemaining << std::endl;
}
