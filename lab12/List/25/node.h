#pragma once
#include <iostream>



template < class T >
class List{
private:
    struct node;

public:
    List();
    ~List();
    bool IsEmpty();
    void Push_back(T val);
    void Pop_back();
    void Push_first (const T& v);
    void Push_after (node* i, const T& v);
    void Pop_first ();
    void Pop_after (node* i);
    node* GetHead() const;
    T GetVal(node* n) const;
    node* GoForward(node* n)const;

private:
    struct node{
        T val;
        node *next;
    };

    friend class List_Exp;

private:
    node *head;
};

#include "node.hpp"