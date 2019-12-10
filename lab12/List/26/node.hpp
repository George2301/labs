template < typename T >
List<T>::List(){   
    head = NULL;
    return;
}

template < typename T >
List<T>::~List(){
    while (head->next->next != NULL)
        Pop_back();
    delete head;
    return;
}

template < typename T >
void List<T>::Push_back(T val){
    node<T> *temp = new node<T>;
    temp->val = val;
    temp->next = NULL;
    node<T> *thead = new node<T>;
    thead = head;
    if (thead != NULL){
        while (thead->next != NULL){
            thead = thead->next;
        }
        thead->next = temp;
    } else {
        head = temp;
    }
    return;
}


template < typename T > 
void List<T>::Pop_back(){
    node<T> *thead = new node<T>;
    thead = head;
    if (thead != NULL){
        if (thead->next != NULL){
            while (thead->next->next != NULL){
            thead = thead->next;
            }
            delete thead->next;
            thead->next = NULL;
        } else {
            delete thead;
            thead = NULL;
        }
    }
    return;
} 

template <typename T> 
void List<T>::Push_first (const T& v){
  node<T> *temp = new node<T>;
  node<T> *thead = new node<T>;
  thead = head;
  if (thead == NULL){
    thead->next = NULL;
    thead->val = v;
  } else {
    temp->next = head;
    temp->val = v;
    thead = temp;
  }
  return;
}

template <typename T> 
void List<T>::Push_after (node<T>* k, const T& v){
  node<T> *temp = new node<T>;
  node<T> *thead = new node<T>;
  thead = head;
  bool f = true;
  while (thead->next && f){
    thead = thead->next;
    if(thead = k)
      f = false;
  }
  if (thead){
    temp->next = thead->next;
    temp->val = v;
    thead->next = temp;
  }
  return;
}

template <typename T> 
void List<T>::Pop_first (){
  node<T> *temp = new node<T>;
  temp = head->next;
  head = NULL;
  head = temp;
  return;
}

template <typename T> 
void List<T>::Pop_after (node<T>* k){
  node<T> *temp = new node<T>;
  node<T> *thead = new node<T>;
  thead = head;
  bool f = true;
  while (thead->next && f){
    if(thead == k)
      f = false;
    if (f) 
      thead = thead->next;  
  }
  if (thead && thead->next){
    temp = thead->next->next;
    thead->next = NULL;
    thead->next = temp;
  }
  return;
}

template <typename T>
node<T>* List<T>::GetHead(){
    return head;
}

template <typename T>
T List<T>::GetVal(node<T>* n){
  return n->val;
}

template <typename T>
node<T>* List<T>::GoForward(node<T>* n){
  return n->next;
}