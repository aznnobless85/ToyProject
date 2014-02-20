#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

#include <string>

void commandChecker(std::string str);
bool hasEmptyCharOffset(std::string str);
int countEmptyChars(std::string str);
std::string getFirstWord(std::string str);
//bool firstWordCheck(std::string str);
//bool secondWordCheck(std::string str, int startPosition);


void singleCommandOnly(std::string str);
void doubleCommandOnly(std::string str);
void tripleCommandOnly(std::string str);
void singleCommandOneParam(std::string str);

void singleCommandTwoParam(std::string str);




#endif