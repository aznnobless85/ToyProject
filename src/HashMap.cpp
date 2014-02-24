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
	
}

HashMap& HashMap::operator=(const HashMap& hm) {
	return *this;
}

void HashMap::add(const std::string& key, const std::string& value) {

	//std::cout << "LoadFactor: " << loadFactor() << std::endl; // DEBUG 
	if(loadFactor() >= 0.8) {
		std::cout << "LoadFactor: " << loadFactor() << std::endl; //DEBUG
		std::cout << "Rehash Started\n";

		unsigned int oldCapacity = bucketCount();
		numberOfAccount = 0;
		unsigned int newCapacity = bucketCount() * 2 + 1;
		Node** newItems = new Node*[newCapacity];
		Node** tempItems = arrList.getItems();

		arrList.setItems(newItems, newCapacity);
		Node* tempNode;
		for(unsigned int i =0; i < oldCapacity; i++) {
		
			tempNode = tempItems[i];
			Node* currentNode;
			if(tempNode != NULL) {
				do {
					currentNode = tempNode;
					add(tempNode->key, tempNode->value);
					if(tempNode->next != NULL) {
						tempNode = tempNode->next;
					}
				}while(currentNode->next != NULL);
			}
		
		}
		//arrList.increaseCapacity(hasher);
		std::cout << "Rehashed\n";
		std::cout << "LoadFactor: " << loadFactor() << std::endl; //DEBUG
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
		arrList.add(pNode, index);
		increaseNumberOfAccount();
		std::cout << "CREATED" << std::endl;
		//std::cout << pNode->key << " || " << index << " is added to empty spot. \n" ;
	}else { // If Node Exists, then...

		//std::cout << "HEAD IS NOT EMPTY\n";
		bool keyExist = false;
		Node* currentNode;

		do{
			currentNode = pTempNode;
			//std::cout << pTempNode->key<< " || " <<pNode->key<<" CURRENTLY CHEKS\n";
			if(pTempNode->key == pNode->key) {
				keyExist = true; // MUST
				break;
			}if(pTempNode->next != NULL) {
				//std::cout << "NEXT NODE IS NULL\n";

				pTempNode = pTempNode->next;
			}
		}while(currentNode->next != NULL);



		if(keyExist) {
			std::cout << "EXISTS" << std::endl;
		}else {
			//arrList.increaseSize();

			increaseNumberOfAccount();
			pTempNode->next = pNode;	
			//std::cout << pTempNode->key <<" || "<< index << "previous node \n" ;

			pTempNode = pTempNode->next;
			//std::cout << pTempNode->key <<" || "<< index << " is added to chain \n" ;
			std::cout << "CREATED" << std::endl;
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
				//std::cout << pTempNode->key << " " << pTempNode->value << " is deleted\n";
				arrList.decreaseSize();
				decreaseNumberOfAccount();
				delete pTempNode;
				break;
			}
			previousNode = pTempNode;
			pTempNode = pTempNode->next;
		}while(previousNode->next != NULL);
		if(!isExist)
			std::cout << "NONEXISTENT\n";
	}
}

bool HashMap::contains(const std::string& key) const {

	unsigned int index = hasher(key) % bucketCount() ;

	Node* pTempNode = arrList.at(index); 
	Node* currentNode;
	bool flag = false;

	if(arrList.at(index) != NULL) {
		do{
			currentNode = pTempNode;
			//std::cout << "Checlk " << pTempNode->key << key << std::endl;
			if(key == pTempNode->key)
			{
				//std::cout << "EXIST " << pTempNode->key << key << std::endl;		
				flag = true;
				break;
			}else if(pTempNode->next != NULL) {
				pTempNode = pTempNode->next;
			}
		}while(currentNode->next != NULL);
		
	} else {
		std::cout << "Something NOT exists" << std::endl;
	}

	return flag;
}

std::string HashMap::value(const std::string& key) const {
	
	std::string value = "";

	if(contains(key)) {
		unsigned int index = hasher(key) % bucketCount() ;

		Node* pTempNode = arrList.at(index); 

		Node* currentNode;

		do{
			currentNode = pTempNode;
			
			if(pTempNode->key == key) {
				value = pTempNode->value;
				break;
			}else if(pTempNode->next != NULL) {
				pTempNode = pTempNode->next;
			}
		}while(currentNode->next != NULL);
	} 

	return value;
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

	Node* pTempNode;
	unsigned int maxNumber = 0;
	unsigned int bucketThatHoldsMaxNumber = 0;
	
	for(unsigned int i = 0; i < bucketCount(); i++) {
		pTempNode = arrList.at(i);
		unsigned int counter = 0;
		while(pTempNode != NULL) {
			counter++;
			pTempNode = pTempNode->next;
		}

		if(maxNumber < counter) {
			maxNumber = counter;
			bucketThatHoldsMaxNumber = i;
		}
	}

	return maxNumber;
}

void HashMap::showAllLinkedList(const std::string& key){
    unsigned int index = hasher(key) % bucketCount() ;
    Node* pTempNode = arrList.at(index);

    while(pTempNode != NULL) {
        std::cout << pTempNode->key << " " << pTempNode->value << " \n";
        pTempNode = pTempNode->next;
    }
    
}
