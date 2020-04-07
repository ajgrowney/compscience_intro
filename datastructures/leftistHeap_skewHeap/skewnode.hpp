template <typename T>
SkewNode<T>::SkewNode(T val){
  lst = nullptr;
  rst = nullptr;
  m_value = val;
}
template <typename T>
void SkewNode<T>::setLST(SkewNode<T>* new_lst){
  lst = new_lst;
}
template <typename T>
void SkewNode<T>::setRST(SkewNode<T>* new_rst){
  rst = new_rst;
}
template <typename T>
T SkewNode<T>::getValue(){
  return m_value;
}


template<typename T>
SkewNode<T>* SkewNode<T>::getRST(){
  return rst;
}
template<typename T>
SkewNode<T>* SkewNode<T>::getLST(){
  return lst;
}


template <typename T>
SkewNode<T>::~SkewNode(){
  lst = nullptr;
  rst = nullptr;
}
