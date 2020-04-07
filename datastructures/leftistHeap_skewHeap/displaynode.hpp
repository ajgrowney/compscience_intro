template <typename T>
DisplayNode<T>::DisplayNode(ConcatNode<T>* node, int node_depth){
  m_node = node;
  m_next = nullptr;
  m_node_depth = node_depth;
}

template <typename T>
void DisplayNode<T>::setNext(DisplayNode<T>* nextNode){
  m_next = nextNode;
}

template <typename T>
DisplayNode<T>* DisplayNode<T>::getNext(){
  return m_next;
}

template <typename T>
ConcatNode<T>* DisplayNode<T>::getValue(){
  return m_node;
}

template <typename T>
int DisplayNode<T>::getNodeDepth(){
  return m_node_depth;
}
