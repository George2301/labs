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
bool List<T>::IsEmpty(){
  bool f = false;
  if (head == NULL) f = true;
  return f;
}

template < typename T >
void List<T>::Push_back(T val){
    List<T>::node *temp = new List<T>::node;
    temp->val = val;
    temp->next = NULL;
    List<T>::node *thead = new List<T>::node;
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
    List<T>::node *thead = new List<T>::node;
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
  List<T>::node *temp = new List<T>::node;
  List<T>::node *thead = new List<T>::node;
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
void List<T>::Push_after (node* k, const T& v){
  List<T>::node *temp = new List<T>::node;
  List<T>::node *thead = new List<T>::node;
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
  List<T>::node *temp = new List<T>::node;
  temp = head->next;
  head = NULL;
  head = temp;
  return;
}

template <typename T> 
void List<T>::Pop_after (node* k){
  List<T>::node *temp = new List<T>::node;
  List<T>::node *thead = new List<T>::node;
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
typename List<T>::node* List<T>::GetHead() const{
    return head;
}

template <typename T>
T List<T>::GetVal(node* n) const{
  return n->val;
}

template <typename T>
typename List<T>::node* List<T>::GoForward(node* n) const{
  return n->next;
}