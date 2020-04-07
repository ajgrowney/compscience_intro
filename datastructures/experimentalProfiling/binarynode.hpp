template<typename T>
BinaryNode<T>::BinaryNode(){
	m_lst = nullptr;
	m_rst = nullptr;
}
template<typename T>
BinaryNode<T>::BinaryNode(T val){
	m_value = val;
	m_lst = nullptr;
	m_rst = nullptr;

}
template<typename T>
void BinaryNode<T>::setLSTPointer(BinaryNode<T>* new_node){
	m_lst = new_node;
}
template<typename T>
void BinaryNode<T>::setRSTPointer(BinaryNode<T>* new_node){
	m_rst = new_node;
}
template<typename T>
BinaryNode<T>* BinaryNode<T>::getLSTPointer(){
	return m_lst;
}
template<typename T>
BinaryNode<T>* BinaryNode<T>::getRSTPointer(){
	return m_rst;
}
template<typename T>
void BinaryNode<T>::setValue(T newValue){
	m_value=newValue;
}

template<typename T>
T BinaryNode<T>::getValue(){
	return m_value;
}


