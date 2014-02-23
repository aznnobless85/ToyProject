#include "HashMap.hpp"
#include <iostream>

HashMap::HashMap() {
	hasher = MyHash();
	numberOfAccount = 0;
}

HashMap::HashMap(HashFunction hasher) {
	this->hasher = hasher;
	numberOfAccount = 0;
}

HashMap::HashMap(const HashMap& hm) {
	std::cout << "";
}

HashMap::~HashMap() {
	std::cout << "";
}

HashMap& HashMap::operator=(const HashMap& hm) {
	return *this;
}

void HashMap::add(const std::string& key, const std::string& value) {

	std::cout << "LoadFactor: " << loadFactor() << std::endl;
	if(loadFactor() >= 0.8) {
		arrList.increaseCapacity();
		std::cout << "Expanded\n";
		std::cout << "LoadFactor: " << loadFactor() << std::endl;
	}

	unsigned int index = hasher(key) % bucketCount() ;
	
	Node* pNode = new Node;
	pNode->key = key;
	pNode->value = value;
	pNode->next = NULL;

	Node* pTempNode = new Node;
	//std::cout << *pTempNode << std::endl;
	pTempNode = arrList.at(index);
	
	if(pTempNode == NULL) {
		std::cout << "No Item at this index " << index << std::endl;
		arrList.add(pNode, index);
		increaseNumberOfAccount();
		std::cout << index << " added \n" ;
	}else { // If Node Exists, then...
		bool keyExist = false;

		while(pTempNode->next != NULL) {
			if(pTempNode->key == key) {
				//keyExist = true; // MUST
			}
			pTempNode = pTempNode->next;

		}
		if(keyExist) {
			std::cout << "EXISTS\n";
		}else {
			//arrList.increaseSize();
			increaseNumberOfAccount();
			pTempNode->next = pNode;	
			pTempNode = pTempNode->next;
			std::cout << pTempNode->key <<" "<< index << " l added \n" ;
		}
		
	}
	//std::cout << pTempNode->key << std::endl;
	
}
void HashMap::remove(const std::string& key) {
	unsigned int index = hasher(key) % bucketCount() ;
	bool isExist = false;

	Node* pTempNode = arrList.at(index);

	Node* previousNode = new Node;
	previousNode = NULL;
	Node* nextNode;


	if(arrList.at(index) == NULL) { // if absolute empty
		std::cout << "NONEXISTENT\n";
	}else{
		do {
			if(key == pTempNode->key){
				if(previousNode == NULL) {
					nextNode = pTempNode->next;
					//delete pTempNode;
					arrList.updateBucket(nextNode, index);
				} else{
					previousNode->next = pTempNode->next;
					//delete pTempNode;
				}
				isExist = true;
				std::cout << pTempNode->key << " " << pTempNode->value << " is deleted\n";
				arrList.decreaseSize();
				decreaseNumberOfAccount();
				delete pTempNode;
				break;
			}
			previousNode = pTempNode;
			pTempNode = pTempNode->next;
		}while(pTempNode->next != NULL);
		if(!isExist)
			std::cout << "NONEXISTENT\n";
	}
}

bool HashMap::contains(const std::string& key) const {

	unsigned int index = hasher(key) % bucketCount() ;

	Node* pTempNode = arrList.at(index); 

	bool flag = false;

	if(arrList.at(index) != NULL) {
		do{
			std::cout << "Checlk " << pTempNode->key << key << std::endl;
			if(key == pTempNode->key)
			{
				std::cout << "EXIST " << pTempNode->key << key << std::endl;		
				flag = true;
				break;
			}
		}while(pTempNode->next != NULL);
		
	} else {
		std::cout << "Something NOT exists" << std::endl;
	}

	return flag;
}

std::string HashMap::value(const std::string& key) const {
	return "";
}

unsigned int HashMap::size() const {
	return numberOfAccount;
}
unsigned int HashMap::bucketCount() const {
	return arrList.capacity();
}
double HashMap::loadFactor() const {

	return (double)size()/(double)bucketCount();
}
unsigned int HashMap::maxBucketSize() const{
	return 0;
}
