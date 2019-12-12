template < typename T >
Deque<T>::Deque(){   
    d = new T[8];
    before = 4;
    after = 4;
    length = 0;
    return;
}

template < typename T >
Deque<T>::~Deque(){
    delete[] d;
    return;
}

template < typename T >
T* Deque<T>::GetD(){
    return d;
}

template < typename T >
int Deque<T>::GetBefore(){
    return before;
}

template < typename T >
int Deque<T>::GetAfter(){
    return after;
}

template < typename T >
int Deque<T>::GetLength(){
    return length;
}

template < typename T >
void Deque<T>::Resize(){
    T *tmp = new T[length + 8];
    before = 4;
    after = 4;
    for(int i = 0; i < length; i++){
        tmp[before + i] = d[before + i];
    }
    return;
}

template < typename T >
void Deque<T>::Push_back(T val){
    if (before == 0 || after == 0){
        Resize();
        after--;
        d[before + length] = val;
        length++;
    } else {
        after--;
        d[before + length] = val;
        length++;
    }
    return;
}

template < typename T >
void Deque<T>::Push_front(T val){
    if (before == 0 || after == 0){
        Resize();
        length++;
        d[before - 1] = val;
        before--;
    } else {
        before--;
        length++;
        d[before] = val;
    }
    return;
}


template < typename T > 
int Deque<T>::Pop_back(){
    int i = 1;
    if (before > 16 || after > 16){
        Resize();
    }
    if (length > 0){
        length--;
        after++;
    } else i = 0;
    return i;
}

template < typename T > 
int Deque<T>::Pop_front(){
    int i = 1;
    if (before > 16 || after > 16){
        Resize();
    }
    if (length > 0){
        length--;
        before++;
    } else i = 0;
    return i;
} 

template < typename T > 
T Deque<T>::Front(){
    return d[before];
}

template < typename T > 
T Deque<T>::Back(){
    return d[before + length - 1];
}

template < typename T >
void Deque<T>::TopToTop(Deque<T>& d){
    d.Push_front(Front());
    Pop_front();
    return;
}

template < typename T >
void Deque<T>::TopToBottom(Deque<T>& d){
    d.Push_back(Front());
    Pop_front();
    return;
}

template < typename T >
void Deque<T>::BottomToTop(Deque<T>& d){
    d.Push_front(Back());
    Pop_back();
    return;
}

template < typename T >
void Deque<T>::BottomToBottom(Deque<T>& d){
    d.Push_back(Back());
    Pop_back();
    return;
}
