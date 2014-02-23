#ifndef PARSINGUTIL_H
#define PARSINGUTIL_H
#include <string>

// general parser
std::string getFirstWord(std::string rawInputStr);
bool hasEmptyCharOffset(std::string rawInputStr);
int positionOfFirstEmptyChar(std::string rawInputStr);
int countEmptyChars(std::string rawInputStr);

// specialized parser
bool isDebugCommand(std::string command);
bool checkValidNumberOfArguments(std::string rawStr, std::string firstWord);


#endif 
