#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

#include <string>
#include "parsingUtil.h"

void commandChecker(std::string str, bool &isDebugMode);

bool checkValidBasicCommand(std::string firstWord);
//bool checkValidFullCommand(std::string firstWord);

void debugModeSwitch(std::string command, bool &isDebugMode);
void debugCommandExecuter(std::string command);

///
void singleCommandOnly(std::string str);
void doubleCommandOnly(std::string str);
void tripleCommandOnly(std::string str);
void singleCommandOneParam(std::string str);
void singleCommandTwoParam(std::string str);




#endif