//Pre: Takes in no parameters
//Post: Initializes a new leftist heap object
//Return: No return
template <typename T>
LeftistHeap<T>::LeftistHeap(){
  m_root = nullptr;
  m_display = new DisplayQueue<T>();
}

//Pre: Takes in no parameters
//Post: No changes to the data structure
//Return: true if empty, false otherwise
template <typename T>
bool LeftistHeap<T>::isEmpty(){
  if(m_root == nullptr){
    return true;
  }else{
    return false;
  }
}

//Pre: Takes in two leftist node pointers h1,h2
//Post: Concatenates the two structures
//Return: returns a pointer to the root of the two concatenated
template <typename T>
LeftistNode<T>* LeftistHeap<T>::concat(LeftistNode<T>* h1, LeftistNode<T>* h2){
  if(h1 == nullptr){
    return h2;
  }else if(h2 == nullptr){
    return h1;
  }else{
    //DONE
    if(h1->getValue() > h2->getValue()){
      //Swap if the h1 root is larger to keep min heap properties
      LeftistNode<T>* tmp = h1;
      h1 = h2;
      h2 = tmp;
      tmp = nullptr;
      //delete tmp;
    }
    h1->setRST(concat(h1->getRST(),h2));
    h1->setRank(h1->findRank(0));

    if(h1->getRST()==nullptr){
      //No need to switch
    }else if(h1->getLST()==nullptr){
      //Move the right to the left side
      h1->setLST(h1->getRST());
      h1->setRST(nullptr);
    }else if(h1->getRST()->getRank() > h1->getLST()->getRank()){
      LeftistNode<T>* tmp = h1->getLST();
      h1->setLST(h1->getRST());
      h1->setRST(tmp);
    }
    return h1;


  }
}

//Pre: Takes in no parameters
//Post: Reads in integers from the data.txt file
//Return: No return value needed.
template <typename T>
void LeftistHeap<T>::build(){
  std::ifstream reader("data.txt");
  T input;
  while(reader >> input){
    insert(input);
  }
}

//Pre: Takes in a value of type T
//Post: Places the value in the data structure
//Return: no return value
template <typename T>
void LeftistHeap<T>::insert(T val){
  LeftistNode<T>* newNode = new LeftistNode<T>(val);

  if(isEmpty()){
    m_root = newNode;

  }else{
    m_root = concat(m_root,newNode);
  }
}

//Pre: Takes in no values
//Post: Deletes the minimum node in the structure
//Return: Returns void
template <typename T>
void LeftistHeap<T>::deleteMin(){
  if(m_root!=nullptr){
    LeftistNode<T>* tmp = m_root;


    if(m_root->getRST()==nullptr){
      m_root = m_root->getLST();
    }else if(m_root->getLST()==nullptr){
      m_root = m_root->getRST();
    }else{
      LeftistNode<T>* h1 = m_root->getLST();
      LeftistNode<T>* h2 = m_root->getRST();
      m_root = concat(h1,h2);
    }

    delete tmp;
  }else{
    std::cout << "Tree is empty\n";
  }
}

//Pre: Takes in a subtreePtr for traversal sake
//Post: Places the node in the queue and makes recursive calls
//Return: no return needed
template <typename T>
void LeftistHeap<T>::preorder_helper(LeftistNode<T>* subtreePtr){
  if(subtreePtr!=nullptr){
    m_display->enqueue(subtreePtr,0);
    preorder_helper(subtreePtr->getLST());
    preorder_helper(subtreePtr->getRST());
  }
}

//Pre: Base call for pre order traversal
//Post: calls its recursive helper function
//Return: no return needed
template <typename T>
void LeftistHeap<T>::preorder(){
  if(m_root!=nullptr){
    preorder_helper(m_root);
    while(!m_display->isEmpty()){
      LeftistNode<T>* tmp = (LeftistNode<T>*)m_display->peek();
      std::cout << tmp->getValue()<<" ";
      m_display->dequeue();
    }
    std::cout <<"\n";
  }else{
    std::cout << "Empty tree\n";
  }
}

//Pre: Takes in a subtreePtr for traversal sake
//Post: Places the node in the queue and makes recursive calls
//Return: no return needed
template <typename T>
void LeftistHeap<T>::inorder_helper(LeftistNode<T>* subtreePtr){
  if(subtreePtr!=nullptr){
    inorder_helper(subtreePtr->getLST());
    m_display->enqueue(subtreePtr,0);
    inorder_helper(subtreePtr->getRST());
  }
}

//Pre: Base call for in order traversal
//Post: calls its recursive helper function
//Return: no return needed
template <typename T>
void LeftistHeap<T>::inorder(){
  if(m_root!=nullptr){
    inorder_helper(m_root);
    while(!m_display->isEmpty()){
      LeftistNode<T>* tmp = (LeftistNode<T>*)m_display->peek();
      std::cout << tmp->getValue()<<" ";
      m_display->dequeue();
    }
    std::cout <<"\n";
  }else{
    std::cout << "Empty tree\n";
  }
}

//Pre: Takes in a subtreePtr for traversal sake and its respective depth
//Post: Places the node in the queue and makes recursive calls
//Return: no return needed
template <typename T>
void LeftistHeap<T>::levelorder_helper(LeftistNode<T>* subtreePtr, int depth){
  //Safeguard from seg faults
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
    //Retrieve the Current node in the front of the queue and do level order
    LeftistNode<T>* tmp = (LeftistNode<T>*)m_display->peek();
    //Get the Rank of the node at the front of the queue
    int depth_help = m_display->getFrontDepth();
    //Remove the front node from the queue
    m_display->dequeue();
    //Call Level order on that information
    levelorder_helper(tmp,depth_help);

  }else{
    //No more level order traversal, reset the queue's current depth variable
    m_display->resetDepth();
  }
}

//Pre: Base call for level order traversal
//Post: calls its recursive helper function
//Return: no return needed
template <typename T>
void LeftistHeap<T>::levelorder(){
  if(m_root!=nullptr){
    levelorder_helper(m_root,0);
  }
}

//Pre: Takes in a subtreePtr for traversing pointers to delete
//post: Deletes the whole tree
//return: no return value
template <typename T>
void LeftistHeap<T>::destroy_tree(LeftistNode<T>* subtreePtr){
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
LeftistHeap<T>::~LeftistHeap(){
  destroy_tree(m_root);
  delete m_display;

}
