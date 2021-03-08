//main.cpp
#include "SecretWord.h"
#include <iostream>
#include <string>

int main()
{
	std::vector<char> letters_guessed;
	SecretWord mySecretWord("test");

	std::cout << "secret word is: " << mySecretWord.getWord()
		<< "\nword with gaps: " << mySecretWord.getWordWithGaps(letters_guessed);

	return 0;
}