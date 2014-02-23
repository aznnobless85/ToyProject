#include "commandParser.h"
#include "parsingUtil.h"
#include <iostream>

void commandChecker(std::string rawStr, bool &isDebugMode) {

	std::string command = "";
	std::string firstWord = getFirstWord(rawStr);

	if(isDebugMode) {

		if(firstWord == "DEBUG") {
			command = rawStr;
			debugModeSwitch(command, isDebugMode);
		}else if(isDebugCommand(rawStr)) {
			command = rawStr;
			debugCommandExecuter(command);
		}else if(checkValidBasicCommand(firstWord) && checkValidNumberOfArguments(rawStr, firstWord)) {
			std::cout << "BASIC COMMAND\n";
		} else {
			std::cout << "INVALID\n";
		}

	}else {
		if(checkValidBasicCommand(firstWord) && checkValidNumberOfArguments(rawStr, firstWord)) {
			if(firstWord == "DEBUG") {
				command = rawStr;
				debugModeSwitch(command, isDebugMode);
			}
		}else {
			std::cout << "INVALID\n";
		}
	}

}

void debugModeSwitch(std::string debugCommand, bool &isDebugMode) {
	if(debugCommand == "DEBUG ON") {
		if(isDebugMode) {
			std::cout << "ON ALREADY\n";
		} else {
			std::cout << "ON NOW\n";
			isDebugMode = true;
		}
	}else if(debugCommand == "DEBUG OFF") {
		if(isDebugMode) {
			std::cout << "OFF NOW\n";
			isDebugMode = false;
		} else {
			std::cout << "OFF ALREADY\n";
		}
	}else {
		std::cout << "INVALID FROM \n";
	}
}

void debugCommandExecuter(std::string command) {
	if(command == "LOGIN COUNT") {
		std::cout << "LOGIN COUNTED!\n";
	} else if(command == "BUCKET COUNT") {
		std::cout << "BUCKET COUNTED!\n";
	} else if(command == "LOAD FACTOR") {
		std::cout << "LOAD FACTORED!\n";
	} else if(command == "MAX BUCKET SIZE") {
		std::cout << "MAX BUCKET SIZED!\n";
	} else {
		std::cout << "Never happen in my bugless program.\n";
	}
}

bool checkValidBasicCommand(std::string firstWord) {
	bool flag = false;
	if(firstWord == "CREATE" ||
		firstWord == "LOGIN" ||
		firstWord == "REMOVE" ||
		firstWord == "CLEAR" ||
		firstWord == "QUIT" ||
		firstWord == "DEBUG") 
		flag = true;

	return flag;
}


/*
bool checkValidNumberOfArguments(std:: string firstWord) {

	if(firstWord == "LOGIN") {
		if( countEmptyChars(firstWord) == 2 )
		{
			// 
		} else if( countEmptyChars(firstWord == 1) ) {

		} 
	} else if(firstWord == "DEBUG") {

	} else if(firstWord == "BUCKET" || firstWord == "LOAD") {

	} else if(firstWord == "MAX") {

	}
}
*/




void singleCommandOnly(std::string str) {
	std::cout << "SINGLE COMMAND ONLY" << std::endl; // TESTING PURPOSE
}

void doubleCommandOnly(std::string str) {
	std::cout << "DOUBLE COMMAND ONLY" << std::endl; // TESTING PURPOSE
}
void tripleCommandOnly(std::string str) {
	std::cout << "TRIPLE COMMAND ONLY" << std::endl; // TESTING PURPOSE	
}

void singleCommandOneParam(std::string str) {
	std::cout << "SINGLE COMMAND ONE PARAM" << std::endl; // TESTING PURPOSE
}

void singleCommandTwoParam(std::string str){
	std::cout << "SINGLE COMMAND TWO PARAM" << std::endl; // TESTING PURPOSE
}


