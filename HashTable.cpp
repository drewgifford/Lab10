#include "HashTable.h"
#include "HashNode.h"

#include <memory>
#include <iostream>

using namespace std;


template <class K, class V>
HashTable<K,V>::HashTable(int size) : m_size(size) {

    m_items = new shared_ptr<HashNode<K,V>>[size];

    for(int i = 0; i < m_size; i++){
        m_items[i] = nullptr;
    }

}

template <class K, class V>
HashTable<K,V>::~HashTable(){
    delete [] m_items;
}

template <class K, class V>
int HashTable<K,V>::hash(K& key){

    // bad hash function
    // return 0;

    int keyInt = (int) key;
    return keyInt % m_size;
}

template <class K, class V>
void HashTable<K,V>::addItem(K key, V value){

    // Initializes a new node to store inside the table
    shared_ptr<HashNode<K, V>> node = make_shared<HashNode<K,V>>(key, value);

    int keyInt = hash(key);

    while (m_items[keyInt] != nullptr && m_items[keyInt]->getKey() != key && m_items[keyInt]->getKey() != -1){

        keyInt++;
        keyInt %= m_size;

    }

    if (m_items[keyInt] == nullptr || m_items[keyInt]->getKey() == -1) {
        m_count++;
        m_items[keyInt] = node;
    }
}

template <class K, class V>
shared_ptr<HashNode<K, V>> HashTable<K,V>::getItem(K key){

    int keyInt = hash(key);
    int passes = 0;

    while (m_items[keyInt] != nullptr){
        passes++;

        if (passes > m_size) return nullptr;

        if (m_items[keyInt]->getKey() == key){
            return m_items[keyInt];
        }

        keyInt++;
        keyInt %= m_size;
    }
}

template <class K, class V>
bool HashTable<K,V>::contains(K key){
    return getItem(key) != nullptr;
}

template <class K, class V>
int HashTable<K,V>::getCount(){
    return m_count;
}