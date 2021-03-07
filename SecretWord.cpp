//SecretWord.cpp
//class implementation file

#include "SecretWord.h"

SecretWord::SecretWord()
{

}

SecretWord::SecretWord(std::string word) : secretWord(word), length(word.length()), secretWordWithGaps(setWordWithGaps(word))
{

}

std::string SecretWord::getWord()
{
	return secretWord;
}

void SecretWord::setWordWithGaps(std::string word)
{
	std::string temp_string = "";

	for (int i = 0; i < length; i++)
	{
		temp_string = temp_string + secretWord[i] + "_ ";
	}

	secretWordWithGaps = temp_string;
}

std::string SecretWord::getWordWithGaps()
{
	return secretWordWithGaps;
}

void SecretWord::setLength()
{
	length = secretWord.length();
}

int SecretWord::getLength()
{
	return length;
}

void SecretWord::setWord(std::string word)
{
	secretWord = word;
}
