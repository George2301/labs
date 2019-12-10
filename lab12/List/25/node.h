#pragma once
#include <iostream>

template < typename T >
struct node{
    T val;
    node *next;
};

template < class T >
class List{
private:
    node<T> *head;

public:
    List();
    ~List();
    void Push_back(T val);
    void Pop_back();
    void Push_first (const T& v);
    void Push_after (node<T>* i, const T& v);
    void Pop_first ();
    void Pop_after (node<T>* i);
    node<T>* GetHead();
    T GetVal(node<T>* n);
    node<T>* GoForward(node<T>* n);
};

#include "node.hpp"