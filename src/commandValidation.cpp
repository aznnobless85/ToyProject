//#include "commandValidation.h"
#include "parsingUtil.h"

#include <iostream>

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
