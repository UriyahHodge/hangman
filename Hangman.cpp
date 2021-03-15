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
	std::string userInput = "initialString";
	char letterGuessed = 0;

	std::cout << "Welcome to the game Hangman!" << std::endl;

	//while loop until guesses run out or the secret word is guessed
	std::cout << "Please guess a letter: ";
	std::cin >> letterGuessed;

	while (userInput.length() > 2)
	{
		std::cout << "Please guess a letter: ";
		std::cin >> letterGuessed;

	}

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
