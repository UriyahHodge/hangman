//main.cpp
#include "SecretWord.h"
#include "Hangman.h"
#include <iostream>
#include <string>

int main()
{
	

	//get secret_word from wordlist.txt
	//display number of words imported from the list
	Hangman thisGame("test");
	
	std::string userInput = "initialString";
	std::cout << "Welcome to the game Hangman!" << std::endl;


	//while loop until guesses run out or the secret word is guessed
	while ((thisGame.getRemainingGuesses() > 0) & (thisGame.isWordGuessed() == false))
	{
		
		std::cout << "Please guess a letter: ";
		std::cin >> userInput;

		if (thisGame.isValidGuess(userInput))
		{
			userInput[0] = std::tolower(userInput[0]);

			if (thisGame.isDoubleGuess(userInput[0]) == true)
			{
				if (thisGame.getRemainingWarnings() > 0)
				{
					std::cout << "Oops! You've already guessed that letter. You have " << thisGame.getRemainingWarnings() <<  " warnings left" << std::endl;
				}
				else
				{
					thisGame.resetWarnings();

					std::cout << "Oops! You've already guessed that letter. You have no more warnings left" << std::endl;
					std::cout << "so you lose one guess: " << thisGame.getGuessedWord() << std::endl;

					thisGame.loseGuess(1);
				}

			/*
			elif (userInput == '*')
			{
				
			}
			*/
			}
			else if (thisGame.isBadGuess(userInput[0]) == true)
			{
				thisGame.addToLettersGuessed(userInput[0]);
				thisGame.dropFromLettersRemaining(userInput[0]);

				std::cout << "Oops! That letter is not in my word: " << thisGame.getGuessedWord() << std::endl;

				if (userInput[0] == 'a'
					|| userInput[0] == 'e'
					|| userInput[0] == 'i'
					|| userInput[0] == 'o'
					|| userInput[0] == 'u')
				{
					thisGame.loseGuess(2);
				}
				else
				{
					thisGame.loseGuess(1);
				}
			}
			else
			{
				thisGame.addToLettersGuessed(userInput[0]);
				thisGame.dropFromLettersRemaining(userInput[0]);

				std::cout << "Good guess: " << thisGame.getGuessedWord() << std::endl;
			}
		}
		else
		{
			thisGame.loseWarning();

			if (thisGame.getRemainingWarnings() > 0)
			{
				std::cout << "Oops! That is not a valid letter. You have " << thisGame.getRemainingWarnings() << " warnings left." << std::endl;
			}
			else
			{
				std::cout << "Oops! That is not a valid letter. You have no more warnings left" << std::endl;
				std::cout << "so you lose one guess: " << thisGame.getGuessedWord() << std::endl;

				thisGame.loseGuess(1);
			}
		}

	}
	return 0;
}