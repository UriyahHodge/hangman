#ifndef GUESS_H
#define GUESS_H
#include <iostream>
#include <string>
#include <vector>

class Guess
{
private:
	char letterGuessed;
	const std::string ALPHABET;

public:
	Guess();
	Guess(char);

	void setLetterGuessed(char);
	char getLetterGuessed();

	bool isValidGuess();
	bool isDoubleGuess(std::vector<char>);
};


#endif
