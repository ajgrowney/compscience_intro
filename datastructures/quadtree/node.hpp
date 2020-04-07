template <typename T>
Node<T>::Node()
{
    m_next=nullptr;
}

template <typename T>
T Node<T>:: getValue(){
    return m_value;
}

template <typename T>
Node<T>* Node<T>:: getNext(){
    return m_next;
}


template <typename T>
void Node<T>::setValue(T val){
    m_value=val;
}

template <typename T>
void Node<T>:: setNext(Node<T>* nxt){
    m_next=nxt;
}
