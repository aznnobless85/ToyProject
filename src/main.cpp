#include <iostream>
#include <string>
#include "commandParser.h"


int main()
{
	std::string command = "";

	do {
		getline(std::cin, command); 
		commandChecker(command);

	}while(command!="QUIT");

	

    return 0;
}

