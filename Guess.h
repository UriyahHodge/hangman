#ifndef GUESS_H
#define GUESS_H
#include <iostream>
#include <string>
#include <vector>

class Guess
{
private:
	std::string letterGuessed;
	const std::string ALPHABET;

public:
	Guess();
	Guess(std::string);

	void setLetterGuessed(std::string);
	std::string getLetterGuessed();

	bool isValidGuess();
	bool isDoubleGuess(std::vector<std::string>);
};


#endif
