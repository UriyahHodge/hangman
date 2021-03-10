//SecretWord.cpp
//class implementation file

#include "SecretWord.h"
#include <algorithm>

SecretWord::SecretWord() : secretWord(""), length(0)
{
}

SecretWord::SecretWord(std::string word) : secretWord(word), length(word.length())
{

}

std::string SecretWord::getWord()
{
	return secretWord;
}


std::string SecretWord::getWordWithGaps(std::vector<char> letters_guessed)
{
	
	std::string secretWordWithGaps = "";

	for (int i = 0; i < length; ++i)
	{
		if (std::find(letters_guessed.begin(), letters_guessed.end(), secretWord[i]) != letters_guessed.end())
		{
			secretWordWithGaps = secretWordWithGaps + secretWord[i];
		}
		else 
		{
			secretWordWithGaps = secretWordWithGaps + "_ ";
		}
	}
	
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
