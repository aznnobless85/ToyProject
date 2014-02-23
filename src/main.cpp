#include <iostream>
#include <string>
#include "commandParser.h"

#include "HashMap.hpp"



int main()
{
	
	HashMap hs;
	hs.add("Hello", "1234");
	std::cout << "Current size: " << hs.size() <<std::endl;
	hs.add("Hello1", "2222");
	std::cout << "Current size: " << hs.size() <<std::endl;
	hs.add("Hello2", "3333");
	std::cout << "Current size: " << hs.size() <<std::endl;
	hs.add("Hello2", "3333");
	std::cout << "Current size: " << hs.size() <<std::endl;
	hs.add("Hello2", "3333");
	std::cout << "Current size: " << hs.size() <<std::endl;
	hs.add("Hello", "1234");
	std::cout << "Current size: " << hs.size() <<std::endl;
	hs.add("Hello3", "4444");
	std::cout << "Current size: " << hs.size() <<std::endl;
	hs.add("Hello4", "4444");
	std::cout << "Current size: " << hs.size() <<std::endl;
	hs.add("Hello5", "5555");
	std::cout << "Current size: " << hs.size() <<std::endl;
	hs.add("Hello6", "6666");
	std::cout << "Current size: " << hs.size() <<std::endl;
	hs.showAllLinkedList("Hello");
	hs.remove("Hello2");
	std::cout << "Current size: " << hs.size() <<std::endl;
	hs.showAllLinkedList("Hello");
	hs.remove("Hello2");
	std::cout << "Current size: " << hs.size() <<std::endl;
	hs.showAllLinkedList("Hello");
	hs.remove("Hello2");
	std::cout << "Current size: " << hs.size() <<std::endl;
	hs.showAllLinkedList("Hello");
	hs.remove("Hello2");
	std::cout << "Current size: " << hs.size() <<std::endl;
	hs.showAllLinkedList("Hello");
	// hs.contains("Hello");
	// hs.contains("Hello1");
	// hs.contains("Hello3");
	// hs.contains("Hello4");



 //    bool isDebugMode = false;
 //    std::string command = "";

	// do {
	// 	getline(std::cin, command); 
	// 	commandChecker(command, isDebugMode);
 //                  std::cout << "isDebugMode:" << isDebugMode << std::endl; 
	// }while(command!="QUIT");
	

    return 0;
}

