#pragma once

using namespace std;

template <class K, class V>
class HashNode {

    public:
        HashNode(K, V);

        K getKey();
        V getValue();
        
    private:
        V m_value;
        K m_key;


};

#include "HashNode.cpp"