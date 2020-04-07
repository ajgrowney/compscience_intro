template <typename T>
LeftistNode<T>::LeftistNode(T val){
  lst = nullptr;
  rst = nullptr;
  rank = 0;
  m_value = val;
}

template <typename T>
T LeftistNode<T>::getValue(){
  return m_value;
}
template<typename T>
int LeftistNode<T>::getRank(){
  return rank;
}
template<typename T>
void LeftistNode<T>::setRST(LeftistNode<T>* new_rst){
  rst = new_rst;
}
template<typename T>
LeftistNode<T>* LeftistNode<T>::getRST(){
  return rst;
}
template<typename T>
void LeftistNode<T>::setLST(LeftistNode<T>* new_lst){
  lst = new_lst;
}
template<typename T>
LeftistNode<T>* LeftistNode<T>::getLST(){
  return lst;
}

template<typename T>
void LeftistNode<T>::setRank(int current_rank){
  rank = current_rank;
}

template<typename T>
int LeftistNode<T>::findRank(int current_rank){
  if(rst == nullptr || lst == nullptr){
    return current_rank;
  }else{
    int rank_right = rst->findRank(current_rank+1);
    int rank_left = lst->findRank(current_rank+1);
    if(rank_right > rank_left){
      return rank_left;
    }else{
      return rank_right;
    }
  }

}

template <typename T>
LeftistNode<T>::~LeftistNode(){
  lst = nullptr;
  rst = nullptr;
}
