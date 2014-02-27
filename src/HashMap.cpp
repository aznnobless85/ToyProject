#include "HashMap.hpp"
#include <iostream>
#include <cstring>

namespace {
    unsigned int myHash(const std::string& key) {
        unsigned int sum = 0;
        for(unsigned int i = 0; i < key.length();i++) 
        {
            char ch = key.at(i);
            sum += ch;
        }
        return sum;
    }
}

// Default Constructor
HashMap::HashMap() {
	arrList = new ArrayList<Node>(initialBucketCount);
	hasher = myHash;
	HashFunction tt = hasher;
	numberOfAccount = 0;
	isExpanding = false;
	//temp();
}

// Constructor with one argument
HashMap::HashMap(HashFunction hasher) {
	arrList = new ArrayList<Node>(initialBucketCount);
	this->hasher = hasher;
	numberOfAccount = 0;
	isExpanding = false;
}

// Copy Constructor
HashMap::HashMap(const HashMap& hm){ 

	hasher = hm.hasher;
	isExpanding = hm.isExpanding;
	numberOfAccount = hm.numberOfAccount;

	arrList = new ArrayList<Node>(*hm.arrList);
	

	// for(unsigned int i = 0; i < hm.bucketCount(); i++) {
	// 	Node* source = hm.arrList->at(i);
	// 	Node* target = arrList->at(i);

	// 	int count = 0;
	// 	while(source != nullptr) {
			
	// 		if(count == 0) {
	// 			Node* pTempNode = new Node;
	// 			pTempNode->key = source->key;

	// 			pTempNode->value = source->value;
	// 			if(source->next == nullptr)
	// 				pTempNode->next = nullptr;
	// 			else
	// 				pTempNode->next = new Node;
	// 			arrList->add(pTempNode, i);
	// 			count++;
	// 			target = arrList->at(i);
				
	// 			//break;
	// 		} else {

	// 			target = target->next;
	// 			target->key = source->key;
	// 			target->value = source->value;
	// 			if(source->next == nullptr)
	// 				target->next = nullptr;
	// 			else
	// 				target->next = new Node;
	// 		}


	// 		source = source->next;
			
	// 	}
		
	// }

}

// Destructor
HashMap::~HashMap() {

	for(unsigned int i = 0; i < bucketCount(); i++) {
		Node* pTempNode = arrList->at(i);

		if(arrList->at(i) == nullptr) {
			delete pTempNode;
		}
		else {
			while(pTempNode != nullptr) {
				Node* nextNode = pTempNode->next;
				delete pTempNode;
				pTempNode = nextNode;			
			}
		}
	}
	
	delete arrList;

	
}
// Operator Overload
HashMap& HashMap::operator=(const HashMap& hm) {
	if(this != &hm) {
		this->clearHashMap();
		hasher = hm.hasher;
		isExpanding = hm.isExpanding;
		numberOfAccount = hm.numberOfAccount;
		
		// Deep copy is needed. So I created new Array.
		ArrayList<Node>* newArrList = new ArrayList<Node>(hm.bucketCount());
		
		// for(unsigned int i = 0; i < hm.bucketCount(); i++) {
		// Node* source = hm.arrList->at(i);
		// Node* target;

		// int count = 0;
		// while(source != nullptr) 
		// {

			
		// 	if(count == 0) 
		// 	{
		// 		Node* pTempNode = new Node;

		// 		pTempNode->key = source->key;
		// 		pTempNode->value = source->value;

		// 		if(source->next == nullptr)
		// 			pTempNode->next = nullptr;
		// 		else
		// 			pTempNode->next = new Node;
		// 		newArrList->add(pTempNode, i);
		// 		count++;
		// 		target = newArrList->at(i);
				
		// 	} else 
		// 	{

		// 		target = target->next;
		// 		target->key = source->key;
		// 		target->value = source->value;
		// 		//arrList->increaseSize();
		// 		if(source->next == nullptr)
		// 			target->next = nullptr;
		// 		else
		// 			target->next = new Node;
		// 	}

		// 	source = source->next;
			
		// }

		delete arrList;
		arrList = newArrList; 
		
	//	}


		
	}

	return *this;
}

// this function add a node with key/password pair data into hashmap.
void HashMap::add(const std::string& key, const std::string& value) {

	if(loadFactor() >= 0.8) {
		isExpanding = true;
		expandBucket();
		isExpanding = false;
	}

	unsigned int index = hasher(key) % bucketCount() ;
	
	Node* pNode = new Node;
	pNode->key = key;
	pNode->value = value;
	pNode->next = nullptr;

	Node* pTempNode;
	pTempNode = arrList->at(index);
	
	if(pTempNode == nullptr) {
		arrList->add(pNode, index);
		increaseNumberOfAccount();
		if(!isExpanding)
			std::cout << "CREATED" << std::endl;
	}else { // If Node Exists, then...

		bool keyExist = false;
		Node* currentNode;

		do{
			currentNode = pTempNode;
			if(pTempNode->key == pNode->key) {
				keyExist = true; // MUST
				break;
			}if(pTempNode->next != nullptr) {
				pTempNode = pTempNode->next;
			}
		}while(currentNode->next != nullptr);

		if(keyExist) {
			std::cout << "EXISTS" << std::endl;
		}else {
			increaseNumberOfAccount();
			pTempNode->next = pNode;	
			pTempNode = pTempNode->next;
			if(!isExpanding)
				std::cout << "CREATED" << std::endl;
		}
	}
}
void HashMap::remove(const std::string& key) {
	unsigned int index = hasher(key) % bucketCount() ;
	bool isExist = false;

	Node* pTempNode = arrList->at(index);

	Node* previousNode;
	previousNode = nullptr;
	Node* nextNode;


	if(arrList->at(index) == nullptr) { // if absolute empty
		std::cout << "NONEXISTENT\n";
	}else{
		do {
			if(key == pTempNode->key){
				if(previousNode == nullptr) {
					nextNode = pTempNode->next;
					//delete pTempNode;
					arrList->updateBucket(nextNode, index);
				} else{
					previousNode->next = pTempNode->next;
					//delete pTempNode;
				}
				isExist = true;
				//std::cout << pTempNode->key << " " << pTempNode->value << " is deleted\n";
				arrList->decreaseSize();
				decreaseNumberOfAccount();
				delete pTempNode;
				break;
			}
			previousNode = pTempNode;
			pTempNode = pTempNode->next;
		}while(previousNode->next != nullptr);
		if(!isExist)
			std::cout << "NONEXISTENT\n";
	}
}

bool HashMap::contains(const std::string& key) const {

	unsigned int index = hasher(key) % bucketCount() ;

	Node* pTempNode = arrList->at(index); 
	Node* currentNode;
	bool flag = false;

	if(arrList->at(index) != nullptr) {
		do{
			currentNode = pTempNode;
			if(key == pTempNode->key)
			{
				flag = true;
				break;
			}else if(pTempNode->next != nullptr) {
				pTempNode = pTempNode->next;
			}
		}while(currentNode->next != nullptr);
		
	} 

	return flag;
}

std::string HashMap::value(const std::string& key) const {
	
	std::string value = "";

	if(contains(key)) {
		unsigned int index = hasher(key) % bucketCount() ;

		Node* pTempNode = arrList->at(index); 

		Node* currentNode;

		do{
			currentNode = pTempNode;
			
			if(pTempNode->key == key) {
				value = pTempNode->value;
				break;
			}else if(pTempNode->next != nullptr) {
				pTempNode = pTempNode->next;
			}
		}while(currentNode->next != nullptr);
	} 

	return value;
}

unsigned int HashMap::size() const {
	return numberOfAccount;
}
unsigned int HashMap::bucketCount() const {
	return arrList->capacity();
}
double HashMap::loadFactor() const {

	return (double)size()/(double)bucketCount();
}

unsigned int HashMap::maxBucketSize() const{

	Node* pTempNode;
	unsigned int maxNumber = 0;
	unsigned int bucketThatHoldsMaxNumber = 0;
	
	for(unsigned int i = 0; i < bucketCount(); i++) {
		pTempNode = arrList->at(i);
		unsigned int counter = 0;
		while(pTempNode != nullptr) {
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

// THIS FUNCTION is for my personal DEBUG COMMAND.
void HashMap::showAllLinkedList(const std::string& key){
    unsigned int index = hasher(key) % bucketCount() ;
    Node* pTempNode = arrList->at(index);

    while(pTempNode != nullptr) {
        std::cout << pTempNode->key << " " << pTempNode->value << " \n";
        pTempNode = pTempNode->next;
    }   
}
// THIS FUNCTION is for my personal DEBUG COMMAND.
void HashMap::showAllHashmap() {

	Node* pTempNode;
	for(unsigned int i = 0; i < bucketCount(); i++) {
		pTempNode = arrList->at(i);
		while(pTempNode != nullptr) {
	        std::cout << "index:\t" << i << "\t" << pTempNode->key << "\t" << pTempNode->value << " \n";
	        pTempNode = pTempNode->next;
    	}   
	}

}

void HashMap::expandBucket() {
	unsigned int oldCapacity = bucketCount();
	numberOfAccount = 0;
	unsigned int newCapacity = bucketCount() * 2 + 1;
	Node** newItems = new Node*[newCapacity];
	Node** tempItems = arrList->getItems();

	arrList->setItems(newItems, newCapacity);
	Node* tempNode;
	for(unsigned int i =0; i < oldCapacity; i++) {
		
		tempNode = tempItems[i];
		Node* previousNode;
		
		if(tempNode != nullptr) {
			do {
				previousNode= tempNode;
				add(tempNode->key, tempNode->value);
				tempNode = tempNode->next;
				
				delete previousNode;

			}while(tempNode != nullptr);
		}
	}

	delete [] tempItems;
}

unsigned int HashMap::getIndex(const std::string& key) const  {
       return hasher(key) % bucketCount() ;
}

void HashMap::clearHashMap() {

	for(unsigned int i = 0; i < bucketCount(); i++) {
		Node* pTempNode = arrList->at(i);
		
		// COMMENTED PART INSIDE OF THIS WHILE LOOP IS ALTERNATIVE ALGORITHM! 
		while(pTempNode != nullptr) {
			// Node* nextNode = pTempNode->next;
			// delete pTempNode;
			// pTempNode = nextNode;
			// decreaseNumberOfAccount();
			Node* nextNode = pTempNode->next;
			remove(pTempNode->key);
			pTempNode = nextNode;
		}
			//pTempNode = arrList->at(i);
			//pTempNode = new Node;
			//pTempNode = nullptr;
	}

	std::cout << "CLEARED" <<std::endl;

}

// increaseNumberOfAccount() increases numberOfAccount
void HashMap::increaseNumberOfAccount() {
    numberOfAccount++;
}

// decreaseNumberOfAccount() decreases numberOfAccount
void HashMap::decreaseNumberOfAccount() {
    numberOfAccount--;
}

// FUNCTION that performs my personal DEBUG COMMAND
void HashMap::temp() {


    	add("Singed","1");
    	add("Timo","1");


    
}
