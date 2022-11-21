#pragma once

template <class T>
class HashTable {

    public:
        HashTable();
        ~HashTable();

        int hash(int);

        bool addItem(T&);
        T getItem(T&);
        bool contains(T&);

    private:

        int m_size;


};

#include "HashTable.cpp"