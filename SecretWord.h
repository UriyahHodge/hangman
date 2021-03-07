//SecretWord.h

#ifndef SECRETWORD_H
#define SECRETWORD_H

#include <string>

class SecretWord
{
private:
	std::string secretWord;
	std::string secretWordWithGaps;
	int length;

public:
	SecretWord();
	SecretWord(string word);

	void setWord(string word);

	std::string getWord(string word);

	void setWordWithGaps();

	std::string getWordWithGaps();

	void setLength();

	int getLength();
};

#endif