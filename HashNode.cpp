#include "HashTable.h"
#include "HashNode.h"

#include <memory>

using namespace std;

template <class K, class V>
HashNode<K,V>::HashNode(K key, V value) : m_key(key), m_value(value){

}

template <class K, class V>
K HashNode<K,V>::getKey() {
    return m_key;
}

template <class K, class V>
V HashNode<K,V>::getValue() {
    return m_value;
}

