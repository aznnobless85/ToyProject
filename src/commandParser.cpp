#include "commandParser.h"
#include <iostream>

void commandChecker(std::string str) {

	//std::cout << "COMMAND CHECKER IS CALLED!\n"; //TESTING PURPOSE

	int start = 0;
	int currentLocation = 0;
	int numberOfEmptyChar = 0;
	
	std::string command = "";

	if(hasEmptyCharOffset(str)) { // NOT Command only
		// std::cout << "Number of Empty Char : " << countEmptyChars(str) << std::endl; // TESTING PURPOSE
		numberOfEmptyChar = countEmptyChars(str);
		//std::cout << getFirstWord(str); // TESTING PURPOSE
		std::string firstWord = getFirstWord(str);

		// Figure out special case: LOGIN, DEBUG
		if(firstWord == "LOGIN") {
			if(numberOfEmptyChar == 2)
				singleCommandTwoParam(str);
			else
				doubleCommandOnly(str);
		}else if(firstWord == "DEBUG") {
			int emptyCharOffset = str.find(" ",0);
			int start = emptyCharOffset + 1;
			std::string secondCommand = str.substr(start); // WORKS!
			if(secondCommand == "ON") {
				// functionality here [CODE REQUIRE]
			}else{
				// functionlaity here [CODE REQUIRE]
			}
		}else if( (firstWord == "BUCKET") || (firstWord=="LOAD") ) {
			doubleCommandOnly(str);	
		}else if(firstWord == "MAX"){
			tripleCommandOnly(str);
		} else {
			switch(numberOfEmptyChar) {
				case 2:
					singleCommandTwoParam(str);
					break;
				case 1:
					singleCommandOneParam(str);
					break;
				default: 
					break;
			}
		}

	}
	else { // Command only
		singleCommandOnly(str);

	}

}

std::string getFirstWord(std::string str) {

	int emptyCharOffset = str.find(" ", 0);
	return str.substr(0, emptyCharOffset);

}


// Checks str contains empty char or not.
bool hasEmptyCharOffset(std::string str) {

	int emptyCharOffset = str.find(" ", 0);

	if(emptyCharOffset > 0) 
		return true;
	else
		return false;

}

// WARNING: last empty char is not considered.
int countEmptyChars(std::string str) {

	int counter = 0;
	int start = 0;
	int emptyCharOffset = 0;
	
	do {
		emptyCharOffset = str.find(" ",start);
		if(emptyCharOffset != -1)
			counter++;
			start = emptyCharOffset + 1;
	}while(emptyCharOffset != -1);

	return counter;
}

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


