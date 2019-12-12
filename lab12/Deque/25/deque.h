#pragma once

template < class T >
class Deque{
private:
    T *d;
    int before, after, length;

public:
    Deque();
    ~Deque();
    T* GetD();
    int GetBefore();
    int GetAfter();
    int GetLength();
    void Resize();
    void Push_front(T val);
    void Push_back(T val);
    int Pop_front();
    int Pop_back();
    T Front();
    T Back();
    void TopToTop(Deque<T>& d);
    void TopToBottom(Deque<T>& d);
    void BottomToTop(Deque<T>& d);
    void BottomToBottom(Deque<T>& d);
};

#include "deque.hpp"