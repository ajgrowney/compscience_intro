template<typename T>
DisplayQueue<T>::DisplayQueue(){
  m_front = nullptr;
  m_size = 0;
  m_depth = 0;
}
template <typename T>
bool DisplayQueue<T>::isEmpty() const{
  if(m_size == 0){
    return true;
  }else{
    return false;
  }
}
template <typename T>
int DisplayQueue<T>::getSize(){
  return m_size;
}
template <typename T>
int DisplayQueue<T>::getDepth(){
  return m_depth;
}
template <typename T>
void DisplayQueue<T>::increaseDepth(){
  m_depth++;
}
template <typename T>
int DisplayQueue<T>::getFrontDepth(){
  return m_front->getNodeDepth();
}
template <typename T>
void DisplayQueue<T>::resetDepth(){
   m_depth = 0;
}
template <typename T>
void DisplayQueue<T>::enqueue(ConcatNode<T>* nextNode, int depth){
  if(isEmpty()){
    DisplayNode<T>* new_front = new DisplayNode<T>(nextNode,depth);
    m_front = new_front;
  }else{
    DisplayNode<T>* traverse = m_front;
    while(traverse->getNext()!=nullptr){
      traverse = traverse->getNext();
    }
    DisplayNode<T>* new_back = new DisplayNode<T>(nextNode,depth);
    traverse->setNext(new_back);
  }
  m_size++;
}

template<typename T>
ConcatNode<T>* DisplayQueue<T>::peek() const{
  return m_front->getValue();
}

template <typename T>
void DisplayQueue<T>::dequeue(){
  DisplayNode<T>* deleteNode = m_front;
  m_front = m_front->getNext();
  delete deleteNode;
  m_size--;
}
