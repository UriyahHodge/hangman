//SecretWord.h

#ifndef SECRETWORD_H
#define SECRETWORD_H
#include <iostream>
#include <string>
#include <vector>

class SecretWord
{
private:
	std::string secretWord;
	int length;

public:
	SecretWord();
	SecretWord(std::string);

	void setWord(std::string);

	std::string getWord();

	std::string getWordWithGaps(std::vector<char>);

	void setLength();

	int getLength();

};

#endif