#pragma once
#include "HashNode.h"

#include <memory>
#include <vector>

template <class K, class V>
class HashTable {

    public:
        HashTable(int);
        ~HashTable();

        int hash(K&);
        void addItem(K, V);

        shared_ptr<HashNode<K, V>> getItem(K);
        bool contains(K);
        int getCount();

    private:

        int m_size;
        int m_count;

        shared_ptr<HashNode<K,V>> * m_items;


};

#include "HashTable.cpp"