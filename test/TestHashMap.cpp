// TestHashMap.cpp
//
// ICS 45C Winter 2014
// Project #3: Maps and Legends
//
// Write unit tests for your HashMap class here.  I've provided one test already,
// though I've commented it out, because it won't compile until you've implemented
// three things: the HashMap constructor, the HashMap destructor, and HashMap's
// size() member function.

#include <gtest/gtest.h>
#include "HashMap.hpp"


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

// Test default constructor
TEST(TestHashMap, sizeOfNewlyCreatedHashMapIsZero)
{
   HashMap empty;
   ASSERT_EQ(0, empty.size());
   ASSERT_EQ(0, empty.loadFactor());
   ASSERT_EQ(0, empty.maxBucketSize());
   ASSERT_EQ(10, empty.bucketCount());
}


//TestCase: test HashMap's constructor with a parameter.
TEST(TestHashMap, hashMapConstructorWithOneParameter) {

	HashMap hashMap(myHash); 
    ASSERT_EQ(0, hashMap.size());
    ASSERT_EQ(0, hashMap.loadFactor());
    ASSERT_EQ(0, hashMap.maxBucketSize());
    ASSERT_EQ(10, hashMap.bucketCount());

}

// Test copy constructor ??
TEST(TestHashMap, testCopyConstructor) {
    HashMap hm1;
    hm1.add("Hi","1234");
    hm1.add("Google", "4321");
    hm1.add("Naver","1234");
    hm1.add("Go", "4321");
    hm1.add("Boo","1234");
    hm1.add("Foo", "4321");
    const HashMap hm2 = hm1;

    EXPECT_EQ(hm1.size(), hm2.size());
    EXPECT_EQ(hm1.bucketCount(), hm2.bucketCount());
}

TEST(TestHashMap, testOperatorOverload) {

	HashMap hm1;
	hm1.add("Hi", "1234");
	hm1.add("aa121", "1234");
	hm1.add("bb441", "1234");
	hm1.add("ccc11", "1234");
	hm1.add("ddd121", "1234");
	hm1.add("qqq441", "1234");
	hm1.add("wew", "1234");
	hm1.add("wewe1121", "1234");
	hm1.add("Hi441", "1234");

	HashMap hm2;
	hm2.add("Hias", "1234");
	hm2.add("Hiqwq", "1234");
	
	hm1 = hm2;

	EXPECT_EQ(hm1.size(), hm2.size());	
	EXPECT_EQ(hm1.bucketCount(), hm2.bucketCount());
}

// TEST(TestHashMap, TestAddFunction) {

// 	HashMap hm1;
// 	hm1.add("HiThere123", "1234");
// 	hm1.add("123Foo", "1234");
// 	hm1.add("Booajfajfdksa;ffajlsdkfjasdlfjsakdfjda;skfjsadf", "abcd1234");

// 	ASSERT_EQ(3, hm1.size());

// }