#ifndef ARRAYLIST_CPP
#define ARRAYLIST_CPP

#include "ArrayList.hpp"
#include <iostream>

namespace
{
    const unsigned int initialCapacity = 10;
    template<class T>
    void arrayCopy(T* target, T* source, unsigned int capacity)
    {
        for (unsigned int i = 0; i < capacity; i++)
        {
            target[i] = source[i];
        }
    }
}
template<class T>
ArrayList<T>::ArrayList()
{
    items = new T*[initialCapacity];
    for(int i=0;i<initialCapacity;i++) {
        items[i]=nullptr;
    }
    sz = 0;
    numberOfAccount = 0;
    cap = initialCapacity;
}

template<class T>
ArrayList<T>::ArrayList(unsigned int initCapacity)
{
    items = new T*[initCapacity];
    for(int i=0;i<initCapacity;i++) {
        items[i]=nullptr;
    }
    sz = 0;
    numberOfAccount = 0;
    cap = initCapacity;
}

template<class T>
ArrayList<T>::ArrayList(const ArrayList<T>& a)
{
    items = new T*[a.cap];
    sz = a.sz;
    numberOfAccount = a.numberOfAccount;;
    cap = a.cap;
    
    arrayCopy(items, a.items, a.cap);
}

template<class T>
ArrayList<T>::~ArrayList()
{
    delete[] items;
}

template<class T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& a)
{

    if (this != &a)
    {
        T** newItems = new T*[a.cap];
        arrayCopy(newItems, a.items, a.cap);

        sz = a.sz;
        cap = a.cap;

        delete[] items;
        items = newItems;
    }

    return *this;
}


template<class T>
T* ArrayList<T>::at(unsigned int index) const
{
    return items[index];
}

// template<class T>
// void ArrayList<T>::setCapacity(unsigned int capacity);
// {
//     cap = capacity;

// }


template <class T>
void ArrayList<T>::add(T* t,unsigned int index )
{
    items[index] = t;
    increaseSize();
    //std::cout << items[index]->key;
}

template <class T>
void ArrayList<T>::updateBucket(T* t, unsigned int index){
    items[index] = t;
}

template <class T>
unsigned int ArrayList<T>::size() const
{
    return sz;
}

template <class T>
unsigned int ArrayList<T>::capacity() const
{
    return cap;
}

template <class T>
unsigned int ArrayList<T>::getNumberOfAccount() const
{
    return numberOfAccount;
}

template <class T>
void ArrayList<T>::increaseSize() {
    sz++;
    numberOfAccount++;
}

template <class T>
void ArrayList<T>::decreaseSize() {
    sz--;
}

template <class T>
void ArrayList<T>::setItems(T** newItems, unsigned int newCap) {
    
    for(unsigned int i = 0; i < newCap; i++) {
        newItems[i] = nullptr;
    }    

    this->items = newItems;
    cap = newCap;
    sz = 0;
    numberOfAccount = 0;
}

template <class T>
T** ArrayList<T>::getItems() {
    return items;
}

#endif