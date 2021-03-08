//main.cpp
#include "SecretWord.h"
#include "Hangman.h"
#include <iostream>
#include <string>

void displayGameDetails(Hangman thisGame) {
	std::cout << "--------------------" << std::endl;
	std::cout << "You have " << thisGame.getRemainingGuesses() << " guesses left." << std::endl;
	std::cout << "Letters remaining: " << thisGame.getLettersRemaining() << std::endl;
}

int main()
{
	std::string letterGuessed = "";

	//get secret_word from wordlist.txt
	//display number of words imported from the list
	std::cout << "Welcome to the game Hangman!" << std::endl;
	std::cin >> letterGuessed;

	Hangman thisGame(letterGuessed);

	std::cout << "letter guessed: " << letterGuessed;

	displayGameDetails(thisGame);


	
	return 0;
}