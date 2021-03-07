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
	SecretWord(std::string word);

	void setWord(std::string word);

	std::string getWord();

	void setWordWithGaps(std::string word);

	std::string getWordWithGaps();

	void setLength();

	int getLength();
};

#endif