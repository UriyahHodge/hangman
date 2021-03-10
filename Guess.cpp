#include "Guess.h"

Guess::Guess() : ALPHABET("abcdefghijklmnopqrstuvwxyz")
{

}

Guess::Guess(char cur_guess) : ALPHABET("abcdefghijklmnopqrstuvwxyz")
{
	setLetterGuessed(cur_guess);
}

void Guess::setLetterGuessed(char cur_guess)
{
	letterGuessed = cur_guess;
}

char Guess::getLetterGuessed()
{
	return letterGuessed;
}

bool Guess::isValidGuess()
{
	return (
		((letterGuessed == '*') 
		|| (ALPHABET.find(letterGuessed)))
	);
}

bool Guess::isDoubleGuess(std::vector<char> listLettersGuessed)
{
	return (std::find(listLettersGuessed.begin(), listLettersGuessed.end(), letterGuessed) == listLettersGuessed.end());
}

