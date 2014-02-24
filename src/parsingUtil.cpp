#include "parsingUtil.h"

std::string getFirstWord(std::string rawInputStr) {

    return rawInputStr.substr(0,  positionOfFirstEmptyChar(rawInputStr));
}

int positionOfFirstEmptyChar(std::string rawInputStr) {
    return rawInputStr.find(" ",0);
}

// Checks str contains empty char or not.
bool hasEmptyCharOffset(std::string rawInputStr) {

    int emptyCharOffset = rawInputStr.find(" ", 0);

    if(emptyCharOffset > 0) 
        return true;
    else
        return false;

}

// WARNING: last empty char is not considered. 
int countEmptyChars(std::string rawInputStr) {

    int counter = 0;
    int start = 0;
    int emptyCharOffset = 0;
    
    do {
        emptyCharOffset = rawInputStr.find(" ",start);
        if(emptyCharOffset != -1)
            counter++;
            start = emptyCharOffset + 1;
    }while(emptyCharOffset != -1);

    return counter;
}

bool isDebugCommand(std::string command) {
    bool flag = false;
    
    if(command == "LOGIN COUNT" || 
        command == "BUCKET COUNT" ||
        command == "LOAD FACTOR" || 
        command == "MAX BUCKET SIZE" ||
        command == "SHOW ALL") 
            flag = true;

    return flag;

}

bool checkValidNumberOfArguments(std::string rawStr, std::string firstWord){
    if(firstWord == "CREATE" || firstWord == "LOGIN")
         return countEmptyChars(rawStr) == 2;
    else if(firstWord == "REMOVE")
        return countEmptyChars(rawStr) == 1;
    else if(firstWord == "CLEAR" || firstWord == "QUIT")
        return countEmptyChars(rawStr) == 0;
    else
        return true; // THIS WILL NEVER HAPPEN

}

std::string* twoParamParser(std::string str) {

    int firstOffsetOfEmptyChar = positionOfFirstEmptyChar(str);
        
    std::string parameters = str.substr(firstOffsetOfEmptyChar+1);


    std::string* pParameters = new std::string[2];
    firstOffsetOfEmptyChar = positionOfFirstEmptyChar(parameters);
    pParameters[0] = parameters.substr(0, firstOffsetOfEmptyChar);
    pParameters[1] = parameters.substr(firstOffsetOfEmptyChar+1);
   
    return pParameters;
}

std::string oneParamParser(std::string str) {

    int firstOffsetOfEmptyChar = positionOfFirstEmptyChar(str);
        
    std::string parameter = str.substr(firstOffsetOfEmptyChar+1);

    return parameter;
}