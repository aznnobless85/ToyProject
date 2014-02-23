
#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP

#include <string>

template <class T> 
class ArrayList
{

public:
    ArrayList();
    ArrayList(const ArrayList<T>& a);
    ~ArrayList();

    ArrayList<T>& operator=(const ArrayList<T>& a);

    T* at(unsigned int index) const;
   

    void add(T* t, unsigned int index);

    void updateBucket(T* t, unsigned int index);

    // size() returns the size of the ArrayList.
    unsigned int size() const;

    void increaseSize() {
    	sz++;
    	numberOfAccount++;
    }

    void decreaseSize() {
    	sz--;
    }

    void increaseCapacity();

    // capacity() returns the capacity of the ArrayList.
    unsigned int capacity() const;

    private:

    // std::string* items;
    T** items;
    unsigned int sz;
    unsigned int numberOfAccount;
    unsigned int cap;
};

#include "ArrayList.cpp"


#endif // ARRAYLIST_HPP