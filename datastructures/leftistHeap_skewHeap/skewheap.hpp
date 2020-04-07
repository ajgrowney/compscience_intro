//Pre: Takes in no parameters
//Post: Initializes a new skew heap object
//Return: No return
template <typename T>
SkewHeap<T>::SkewHeap(){
  m_root = nullptr;
  m_display = new DisplayQueue<T>();
}

//Pre: Takes in no parameters
//Post: No changes to the data structure
//Return: true if empty, false otherwise
template <typename T>
bool SkewHeap<T>::isEmpty(){
  if(m_root == nullptr){
    return true;
  }else{
    return false;
  }
}

//Pre: Takes in two skew node pointers: h1 and h2
//Post: Creates a proper skew tree
//Return: return the SkewNode pointer h1 for setting
template <typename T>
SkewNode<T>* SkewHeap<T>::concat(SkewNode<T>* h1, SkewNode<T>* h2){
  if(h1 == nullptr){
    return h2;
  }else if(h2 == nullptr){
    return h1;
  }else{

    if(h1->getValue() > h2->getValue()){
      //Swap if the h1 root is larger to keep min heap properties
      SkewNode<T>* tmp = h1;
      h1 = h2;
      h2 = tmp;
      tmp = nullptr;
      //delete tmp;
    }

    SkewNode<T>* tmp = h1->getRST();
    h1->setRST(h1->getLST());
    h1->setLST(concat(tmp,h2));
    return h1;


  }
}

//Pre: Takes in the data.txt file
//Post: Places all elements into the data structure
//Return: No return value
template <typename T>
void SkewHeap<T>::build(){
  std::ifstream reader("data.txt");
  T input;
  while(reader >> input){
    insert(input);
  }
}

//Pre: Takes in a value to insert the data structure
//Post: Places a new value by using the cancat function
//Return: No return needed
template <typename T>
void SkewHeap<T>::insert(T val){
  SkewNode<T>* newNode = new SkewNode<T>(val);

  if(isEmpty()){
    m_root = newNode;

  }else{
    m_root = concat(m_root,newNode);
  }
}

//Pre: No input parameters
//Post: Deletes the root of the data structure and concatenates the two subtrees
//Return: No return needed

template <typename T>
void SkewHeap<T>::deleteMin(){
  if(m_root!=nullptr){
    SkewNode<T>* temp = m_root;

    if(m_root->getRST()==nullptr){
      SkewNode<T>* new_root = m_root->getLST();
      m_root = new_root;
      //delete tmp;
    }else if(m_root->getLST()==nullptr){
      SkewNode<T>* new_root = m_root->getRST();
      m_root = new_root;
      //delete tmp;
    }else{
      SkewNode<T>* h1 = m_root->getLST();
      SkewNode<T>* h2 = m_root->getRST();
      //delete tmp;
      SkewNode<T>* new_root = concat(h1,h2);
      m_root = new_root;
    }
    delete temp;
  }else{
    std::cout << "Tree is empty\n";
  }

}

//Pre: Takes in a subtree pointer
//Post: enqueues all the values in the data structure
//Return: No return value, recrusive calls though
template <typename T>
void SkewHeap<T>::preorder_helper(SkewNode<T>* subtreePtr){
  if(subtreePtr!=nullptr){
    m_display->enqueue(subtreePtr,0);
    preorder_helper(subtreePtr->getLST());
    preorder_helper(subtreePtr->getRST());
  }
}

//Pre: Non recursive function that initializes the preorder
//Post: Places the whole data structure in the queue
//Return: No return value
template <typename T>
void SkewHeap<T>::preorder(){
  if(m_root!=nullptr){
    preorder_helper(m_root);
    while(!m_display->isEmpty()){
      SkewNode<T>* tmp = (SkewNode<T>*)m_display->peek();
      std::cout << tmp->getValue()<<" ";
      m_display->dequeue();
    }
    std::cout <<"\n";
  }else{
    std::cout << "Empty tree\n";
  }
}

//Pre: Recursive helper function
//Post: Adds all values recrusively to the queue
//Return: No return value
template <typename T>
void SkewHeap<T>::inorder_helper(SkewNode<T>* subtreePtr){
  if(subtreePtr!=nullptr){
    inorder_helper(subtreePtr->getLST());
    m_display->enqueue(subtreePtr,0);
    inorder_helper(subtreePtr->getRST());
  }
}

//Pre: Takes in no input parameters
//Post: Places all the values in a queue upon recursive function call
//Return: No return value
template <typename T>
void SkewHeap<T>::inorder(){
  if(m_root!=nullptr){
    inorder_helper(m_root);
    while(!m_display->isEmpty()){
      SkewNode<T>* tmp = (SkewNode<T>*)m_display->peek();
      std::cout << tmp->getValue()<<" ";
      m_display->dequeue();
    }
    std::cout <<"\n";
  }else{
    std::cout << "Empty tree\n";
  }
}

//Pre: Takes in an integer of depth and its respective subtree
//Post: Adds the pointer to the display queue
//Return: no return value from this function
template <typename T>
void SkewHeap<T>::levelorder_helper(SkewNode<T>* subtreePtr, int depth){
  if(subtreePtr!=nullptr){

    if(depth!= m_display->getDepth()){
      m_display->increaseDepth();
      std::cout<<"\n";
    }

    std::cout<<subtreePtr->getValue()<<" ";
    //Add Subtree's Children to the Queue
    if(subtreePtr->getLST()!=nullptr){
      m_display->enqueue(subtreePtr->getLST(),depth+1);

    }
    if(subtreePtr->getRST()!=nullptr){
      m_display->enqueue(subtreePtr->getRST(),depth+1);

    }

  }

  if(!m_display->isEmpty()){
    SkewNode<T>* tmp = (SkewNode<T>*)m_display->peek();
    int depth_help = m_display->getFrontDepth();
    m_display->dequeue();
    levelorder_helper(tmp,depth_help);
  }else{
    m_display->resetDepth();
  }

}

//Pre: Takes in no value
//Post: Initiates the level order traversal
//Return: No return value
template <typename T>
void SkewHeap<T>::levelorder(){

  if(m_root!=nullptr){
    levelorder_helper(m_root,0);
  }

}
//Pre: Takes in a subtreePtr for traversing pointers to delete
//post: Deletes the whole tree
//return: no return value
template <typename T>
void SkewHeap<T>::destroy_tree(SkewNode<T>* subtreePtr){
  if(subtreePtr!=nullptr){
    destroy_tree(subtreePtr->getLST());
    destroy_tree(subtreePtr->getRST());
    delete subtreePtr;
  }
}

//Pre: Takes in no value
//Post: Initiates the level order traversal
//Return: No return value
template <typename T>
SkewHeap<T>::~SkewHeap(){
  destroy_tree(m_root);
  delete m_display;

}
