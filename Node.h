#pragma once

using namespace std;

template <class T>
class Node {

    public:
        Node();
        ~Node();

    T m_date;
    int m_key;


};

#include "Node.cpp"