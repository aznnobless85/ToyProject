#ifndef NODE_HPP
#define NODE_HPP

#include <string>

struct Node{
	std::string key;
	std::string value;
	Node* next;
};

#endif