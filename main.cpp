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
	std::cout << "I'm thinking of a word that is " << thisGame.getWordLegth() << " letters long." << std::endl;


	//while loop until guesses run out or the secret word is guessed
	while ((thisGame.getRemainingGuesses() > 0) & (thisGame.isWordGuessed() == false))
	{
		thisGame.displayGameDetails();

		//get users guess
		std::cout << "Please guess a letter: ";
		std::cin >> userInput;

		if (thisGame.isValidGuess(userInput))	//determine if meets valid criteria
		{
			userInput[0] = std::tolower(userInput[0]);	//convert to lowercase char

			if (thisGame.isDoubleGuess(userInput[0]) == true)	//has the user guessed this letter already?
			{
				thisGame.loseWarning();

				if (thisGame.getRemainingWarnings() > 0)	//does the user have any warnings remaining
				{
					std::cout << "Oops! You've already guessed that letter. You have " << thisGame.getRemainingWarnings() <<  " warnings left" << std::endl;
				}
				else //user is out of warnings -- loses a guess
				{
					//set back to 0 remaining warnings cannot be a negative number
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
			else if (thisGame.isBadGuess(userInput[0]) == true)		//letter guessed is not in secret word
			{
				thisGame.addToLettersGuessed(userInput[0]);			//add to list of letters user has guessed
				thisGame.dropFromLettersRemaining(userInput[0]);	//remove from remaining available letters to guess

				std::cout << "Oops! That letter is not in my word: " << thisGame.getGuessedWord() << std::endl;

				//is the guess a vowel?
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
			else	//must be a valid, good guess
			{
				thisGame.addToLettersGuessed(userInput[0]);			//add to list of letters user has guessed
				thisGame.dropFromLettersRemaining(userInput[0]);	//remove from remaining available letters to guess

				std::cout << "Good guess: " << thisGame.getGuessedWord() << std::endl;
			}
		}
		else	//invalid guess
		{
			thisGame.loseWarning();

			if (thisGame.getRemainingWarnings() > 0)
			{
				std::cout << "Oops! That is not a valid letter. You have " << thisGame.getRemainingWarnings() << " warnings left." << std::endl;
			}
			else
			{
				//set back to 0 remaining warnings cannot be a negative number
				thisGame.resetWarnings();

				std::cout << "Oops! That is not a valid letter. You have no more warnings left" << std::endl;
				std::cout << "so you lose one guess: " << thisGame.getGuessedWord() << std::endl;

				thisGame.loseGuess(1);
			}
		}
	}

	if (thisGame.isWordGuessed() == true)
	{
		std::cout << "\n--------------------" << std::endl;
		std::cout << "Congratulations, you won!" << std::endl;
		std::cout << "Your total score for this game is: " << thisGame.calculateTotal() << std::endl;
	}
	else
	{
		std::cout << "\n--------------------" << std::endl;
		std::cout << "Sorry, you ran out of guesses. The word was " << thisGame.getSecretWord() << "." << std::endl;
	}
	return 0;
}