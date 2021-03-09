#include "Guess.h"

Guess::Guess() : ALPHABET("abcdefghijklmnopqrstuvwxyz")
{

}

Guess::Guess(std::string cur_guess) : ALPHABET("abcdefghijklmnopqrstuvwxyz")
{
	setLetterGuessed(cur_guess);
}

void Guess::setLetterGuessed(std::string cur_guess)
{
	for (unsigned int i = 0; i < cur_guess.length(); ++i)
	{
		cur_guess[i] = tolower(cur_guess[i]);
	}

	letterGuessed = cur_guess;
}

std::string Guess::getLetterGuessed()
{
	return letterGuessed;
}

bool Guess::isValidGuess()
{
	return (
		(letterGuessed.length() == 1) 
		& 
		((letterGuessed == "*") 
		|| (std::find(ALPHABET.begin(), ALPHABET.end(), letterGuessed) == ALPHABET.end()))
		);
}

bool Guess::isDoubleGuess(std::vector<std::string> listLettersGuessed)
{
	return (std::find(listLettersGuessed.begin(), listLettersGuessed.end(), letterGuessed) == listLettersGuessed.end());
}
