#include <iostream>
#include <string>
#include "Manager.hpp"

#include "HashMap.hpp"
#include "ArrayList.hpp"

struct Node {

	std::string key;
    std::string value;
    Node* next;

};

// My Program starts from here!!
int main()
{
	// Manager manager;
	// manager.runCommand();

	// HashMap hm1;
	// hm1.add("Hello2", "1234");
	// hm1.add("Timo3", "1234");
	// hm1.add("Singe0", "1234");
	// //m1.add("Hi2", "1234");
	// //hm1.add("Hello1","1");
 //    //hm1.add("Singe1","1");
 //    //hm1.add("Timo3","1");
	// HashMap hm2 = hm1;

	//std::cout << "hm1 size: " << hm1.size() <<std::endl;
	//std::cout << "hm2 size: " << hm2.size() <<std::endl;

	// HashMap hm3;

	// hm3 = hm2;

	// std::cout << "hm3 size: " << hm3.size() <<std::endl;


////TEST CASE ARRAY TEST MODE (operator overload)
	// Node str;
	// str.key ="Hi";
	// str.value = "1234";
	// str.next = nullptr;

	// Node* pStr = &str;
	
	// ArrayList<Node> hm1;

	// hm1.add(pStr, 0);
	
	// ArrayList<Node> hm2;
	// hm2 = hm1;

	// Node** ptr = hm1.getItems();
	// for(int i = 0; i <10; i++) {
	// 	if(ptr[i] != nullptr)
	// 		std::cout << ptr[i]->key <<std::endl;
	// 	else
	// 		std::cout << ptr[i] <<std::endl;

	// }

	// std::cout << "hm1 size: " << hm1.size() <<std::endl;
	// std::cout << "hm2 size: " << hm2.size() <<std::endl;

	// // ARRAY TEST MODE (copy constructor)
	// ArrayList<Node> hm3(hm1);

	// std::cout << "hm3 size: " << hm3.size() << std::endl;

    return 0;
}

