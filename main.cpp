//main.cpp
#include "SecretWord.h"
#include <iostream>
#include <string>

int main()
{
	SecretWord mySecretWord("test");

	std::cout("secret word is: " + mySecretWord.getWord()
		+ "\nword with gaps: " + mySecretWord.getWordWithGaps());

	return 0;
}