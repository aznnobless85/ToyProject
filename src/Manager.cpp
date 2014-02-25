#include "Manager.hpp"

Manager::Manager() {

	isDebugMode = false;
    command = "";
    
}

Manager::~Manager() {


}

void Manager::runCommand() {

	do {
		getline(std::cin, command);
		commandChecker(command, isDebugMode);
		//std::cout << myHashMap.loadFactor() << std::endl;
	}while(command != "QUIT");


}

void Manager::commandChecker(std::string rawStr, bool &isDebugMode) {

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
			basicCommandExecutor(rawStr, isDebugMode);
		} else {
			std::cout << "INVALID\n";
		}

	}else {
		if(checkValidBasicCommand(firstWord) && checkValidNumberOfArguments(rawStr, firstWord)) {
			if(firstWord == "DEBUG") {
				command = rawStr;
				debugModeSwitch(command, isDebugMode);
			}else {
				basicCommandExecutor(rawStr, isDebugMode);
			}
		}else {
			std::cout << "INVALID\n";
		}
	}
}

void Manager::debugModeSwitch(std::string debugCommand, bool &isDebugMode) {
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
		std::cout << "INVALID FORM \n";
	}
}

void Manager::debugCommandExecuter(std::string command) {
	if(command == "LOGIN COUNT") {
		std::cout << myHashMap.size() << std::endl;
	} else if(command == "BUCKET COUNT") {
		std::cout << myHashMap.bucketCount() << std::endl;
	} else if(command == "LOAD FACTOR") {
		std::cout << myHashMap.loadFactor() << std::endl;
	} else if(command == "MAX BUCKET SIZE") {
		std::cout << myHashMap.maxBucketSize() << std::endl;
	} else if (command == "SHOW ALL") {
		myHashMap.showAllLinkedList("Hello");
	} else if(command == "SHOW HASHMAP"){
		myHashMap.showAllHashmap();
	}else if(command == "ADD 100DATA"){
		myHashMap.temp();
	}else {
		std::cout << "Never happen in my bugless program.\n";
	}
}

void Manager::basicCommandExecutor(std::string str, bool isDebugMode) {

	std::string firstWord = getFirstWord(str);

	if(firstWord == "CREATE") {

		std::string* pParameters = twoParamParser(str);
	
		std::string username = pParameters[0];
		std::string password = pParameters[1];

		myHashMap.add(username, password);
		delete [] pParameters;

	}else if(firstWord == "LOGIN" && !isDebugMode) {

		std::string* pParameters = twoParamParser(str);

		std::string username = pParameters[0];
		std::string password = pParameters[1];

		if(myHashMap.contains(username)) {
			std::string query = myHashMap.value(username);
			if(query == password) 
				std::cout << "SUCCEEDED" << std::endl;
			else
				std::cout << "FAILED" << std::endl;
		}else {
				std::cout << "FAILED" << std::endl;
		}
		delete [] pParameters;
	
	}else if(firstWord =="LOGIN" && isDebugMode) {
		int numberOfEmptyChar = countEmptyChars(str);
		
		if(numberOfEmptyChar != 2) 
			std::cout << "INVALID";
		else {
			std::string* pParameters = twoParamParser(str);

			std::string username = pParameters[0];
			std::string password = pParameters[1];

			if(myHashMap.contains(username)) {
				std::string query = myHashMap.value(username);
				if(query == password) 
					std::cout << "SUCCEEDED" << std::endl;
				else
					std::cout << "FAILED" << std::endl;
			} 
			else 
				std::cout << "FAILED" << std::endl;
			delete [] pParameters;
		}	
	

	}else if(firstWord == "REMOVE") {

		std::string username = oneParamParser(str);

		if(myHashMap.contains(username)) {
			myHashMap.remove(username);
			std::cout << "REMOVED" <<std::endl;
		}else {
			std::cout << "NONEXISTENT" <<std::endl;
		}

	}else if(firstWord == "CLEAR") {
		myHashMap.clearHashMap();
	}else if(firstWord == "QUIT") {
		std::cout << "GOODBYE" <<std::endl;
	} else {
		std::cout << "THIS WILL NEVER HAPPEND\n";
	}

}