#ifndef ARRAYLIST_CPP
#define ARRAYLIST_CPP

#include "ArrayList.hpp"
#include <iostream>

namespace
{
    const unsigned int initialCapacity = 10;
    template<class T>
    void arrayCopy(T* target, T* source, unsigned int size)
    {
        for (unsigned int i = 0; i < size; i++)
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
        items[i]=NULL;
    }
    sz = 0;
    numberOfAccount = 0;
    cap = initialCapacity;
}

template<class T>
ArrayList<T>::ArrayList(const ArrayList<T>& a)
{

    items = new T[a.cap];
    sz = a.sz;
    cap = a.cap;

    
    arrayCopy(items, a.items, sz);
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
        T* newItems = new T[a.cap];
        arrayCopy(newItems, a.items, a.sz);

        sz = a.sz;
        cap = a.cap;

        delete[] items;
        items = newItems;
    }

    return *this;
}


// Notice that the bodies of these two functions appear identical.  What makes
// them different, though, is that they return different types: the first
// returns a reference to items[index] that will allow the value in that
// cell to be modified; the second returns a const reference to items[index],
// so it can be read but not modified.
template<class T>
T* ArrayList<T>::at(unsigned int index) const
{
    return items[index];
}

template<class T>
void ArrayList<T>::increaseCapacity() {
    int newCap = cap * 2 + 1;
    T** newItems = new T*[newCap];
    arrayCopy(newItems, items, cap);
    cap = newCap;
    
    delete[] items;
    items = newItems;
}



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

#endif