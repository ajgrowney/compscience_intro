//Pre: Takes in no parameters because it is a constructor
//Post: We have initialized the BST with null rootptr and 0 nodes
//Return: No return, it is a constructor
template<typename T>
BinarySearchTree<T>::BinarySearchTree(){
	m_node_count = 0;
	m_root = nullptr;
}
//Pre: Takes in no parameters
//Post: Makes no changes to the BST
//Return: returns Binary Node pointer to the root of the tree
template<typename T>
BinaryNode<T>* BinarySearchTree<T>::getRootPtr(){
	return m_root;
}
//Pre: Takes in a binarynode pointer as parameter
//Post: Sets the root equal to the pointer passed in 
//Return: Returns void because no need for return
template<typename T>
void BinarySearchTree<T>::setRootPtr(BinaryNode<T>* newRoot){
	m_root = newRoot;
}
//Pre: Takes in no parameters
//Post: Makes no changes to the tree
//Return: Returns true if there are no nodes in the tree, false otherwise
template<typename T>
bool BinarySearchTree<T>::isEmpty() const{
	if(m_node_count == 0){
		return true;
	}else{
		return false;
	}
}
//Pre: Takes in a new value to be inserted into the tree
//Post: There will be a new node added to the BST
//Return: Returns true immediately if empty and added as root, else calls a
//recursive function to insert it and returns the respective return value
template<typename T>
bool BinarySearchTree<T>::insert(T val){
	if(isEmpty()){
		BinaryNode<T>* newNode = new BinaryNode<T>(val);
		m_root = newNode;
		m_node_count++;
		return true;
	}else{
		return insertRec(val,m_root);
	}

}
//Pre: Takes in a value to be inserted and a binary node pointer for
//comparison 
//Post: Adds the new value to the tree based on value and positioning of
//subtrees
//return: Returns true if inserted, returns the recursive call to its subtree
//if not inserted yet
template<typename T>
bool BinarySearchTree<T>::insertRec(T val, BinaryNode<T>* subtreePtr){
	if(subtreePtr!=nullptr && val >= subtreePtr->getValue()){
		if(subtreePtr->getRSTPointer()!=nullptr){
			return insertRec(val,subtreePtr->getRSTPointer());
		}else{
			BinaryNode<T>* newNode = new BinaryNode<T>(val);
			subtreePtr->setRSTPointer(newNode);
			m_node_count++;
			return true;
		}
	}else{
		if(subtreePtr->getLSTPointer()!=nullptr){
			return insertRec(val,subtreePtr->getLSTPointer());
		}else{
			BinaryNode<T>* newNode = new BinaryNode<T>(val);
			subtreePtr->setLSTPointer(newNode);
			m_node_count++;
			return true;
		}
	}
	return false;
}
//Pre: Takes in a value of type T and a binarynode pointer used to find the value in the
//BST
//Post: Deletes the given val from the BST or returns nullptr if it is not
//found  
//Return: Returns the the same node if the node is not deleted, restructures
//and changes to the mininum of the RST if it is deleted 
template<typename T>
BinaryNode<T>* BinarySearchTree<T>::removeNode(T val, BinaryNode<T>* tmp){
	if(tmp!=nullptr){
		if(val < tmp->getValue()){
			if(tmp->getLSTPointer()!=nullptr){
				tmp->setLSTPointer(removeNode(val,tmp->getLSTPointer()));
			}else{
				std::cout << val << " could not be found in the tree\n";
			}
		}else if(val > tmp->getValue()){
			if(tmp->getRSTPointer()!=nullptr){
				tmp->setRSTPointer(removeNode(val,tmp->getRSTPointer()));
			}else{
				std::cout<< val << " could not be found in the tree\n";
			}
		}else{
			if(tmp->getLSTPointer()==nullptr){
				BinaryNode<T>* helperNode = tmp->getRSTPointer();
				delete tmp;
				std::cout << val << " has been deleted\n";
				m_node_count--;
				return helperNode;
			}else if(tmp->getRSTPointer()==nullptr){
				BinaryNode<T>* helperNode = tmp->getLSTPointer();
				delete tmp;
				std::cout << val << " has been deleted\n";
				m_node_count--;
				return helperNode;
			}
			BinaryNode<T>* traverse = findMin(tmp->getRSTPointer());

			tmp->setValue(traverse->getValue());
			tmp->setRSTPointer(removeNode(traverse->getValue(),tmp->getRSTPointer()));
		}
		return tmp;
		
	}else{
		return tmp;
	}

}
//Pre: Takes in the binary node pointer to find the largest value
//Post: Traverses to the largest value using the RST pointers and then deletes
//and replaces the node
//Return: returns a binary node pointer for the recursion to work properly in
//replacing the correct ones and keeping the others the same
template<typename T>
BinaryNode<T>* BinarySearchTree<T>::removeMax(BinaryNode<T>* traverseNode){
	if(traverseNode!=nullptr){
		if(traverseNode->getRSTPointer()!=nullptr){
			traverseNode->setRSTPointer(removeMax(traverseNode->getRSTPointer()));
		}else{
			BinaryNode<T>* helperNode = traverseNode->getLSTPointer();
			//T deleteValue = traverseNode->getValue();
			delete traverseNode;
			//std::cout << deleteValue << " has been deleted\n";
			m_node_count--;
			return helperNode;
		}
		return traverseNode;
	}else{
		return nullptr;
	}
}
//Pre: Takes in the binary node pointer to find the smallest value
//Post: Traverses to the smallest value using the LST pointers and then deletes
//and replaces the node
//Return: returns a binary node pointer for the recursion to work properly in
//replacing the correct ones and keeping the others the same
template<typename T>
BinaryNode<T>* BinarySearchTree<T>::removeMin(BinaryNode<T>* traverseNode){
	if(traverseNode!=nullptr){
		if(traverseNode->getLSTPointer()!=nullptr){
			traverseNode->setLSTPointer(removeMin(traverseNode->getLSTPointer()));
		}else{
			BinaryNode<T>* helperNode = traverseNode->getRSTPointer();
			//T deleteValue = traverseNode->getValue();
			delete traverseNode;
			//std::cout << deleteValue << " has been deleted\n";
			m_node_count--;
			return helperNode;
		}
		return traverseNode;
	}else{
		return nullptr;
	}

}
//Pre: Takes in a BinaryNode pointer called traverseNode which is used to take
//in subtrees and obtain value of node
//Post: Traveses each Nodes LST pointer to find the smallest value in the tree
//Return: Pointer to the smallest valued node if not empty, else return
//nullptr
template<typename T>
BinaryNode<T>* BinarySearchTree<T>::findMin(BinaryNode<T>* traverseNode){
	if(!isEmpty()){
		while(traverseNode->getLSTPointer()!=nullptr){
			traverseNode = traverseNode->getLSTPointer();
		}
		return traverseNode;
	}else{
		return nullptr;
	}
}
//Pre: Takes in a BinaryNode pointer called traverseNode which is used to take
//in subtrees and obtain value of node
//Post: Traverses each nodes RST pointer to find the largest value in the
//tree
//Return: Returns a pointer to the largest valued node if not empty, else returns
//nullptr
template<typename T>
BinaryNode<T>* BinarySearchTree<T>::findMax(BinaryNode<T>* traverseNode){
	if(!isEmpty()){
		while(traverseNode->getRSTPointer()!=nullptr){
			traverseNode = traverseNode->getRSTPointer();
		}
		return traverseNode;
	}else{
		return nullptr;
	}
}
//Pre: Takes in a BinaryNode pointer called traverseNode which is used to take
//in subtrees and obtain value of node
//Post: Prints out the entire tree preorder by recursively calling itself with
//LST and RST after printing its current value
//Return:  returns nothing but prints to standard output
template <typename T>
void BinarySearchTree<T>::PreOrderTraverse(BinaryNode<T>* traverseNode){
	if(traverseNode!=nullptr){
		std::cout << traverseNode->getValue()<<" ";
		PreOrderTraverse(traverseNode->getLSTPointer());
		PreOrderTraverse(traverseNode->getRSTPointer());	
	}
}
//Pre: Takes in a BinaryNode pointer called traverseNode which is used to take
//in subtrees and obtain value of node
//Post: Prints out the entire tree in order by recursively calling itself with
//LST before printing and RST after printing its current value
//Return:  returns nothing but prints to standard output
template <typename T>
void BinarySearchTree<T>::InOrderTraverse(BinaryNode<T>* traverseNode){
	if(traverseNode!=nullptr){
		InOrderTraverse(traverseNode->getLSTPointer());
		std::cout<<traverseNode->getValue()<<" ";
		InOrderTraverse(traverseNode->getRSTPointer());
	}
}
//Pre: Takes in a BinaryNode pointer called traverseNode which is used to get
//the subtrees and value of the current node
//Post: Prints out the entire tree in post order by recursively calling itself with
//the LST and RST before printing the current value
//Return: returns nothing because it is used to be doing standard output
template <typename T>
void BinarySearchTree<T>::PostOrderTraverse(BinaryNode<T>* traverseNode){
	if(traverseNode!=nullptr){
		PostOrderTraverse(traverseNode->getLSTPointer());
		PostOrderTraverse(traverseNode->getRSTPointer());
		std::cout << traverseNode->getValue()<<" ";
	}
}
//Pre: Takes in a BinaryNode pointer called traverseNode used to make
//recursive calls
//Post: Makes a recursive call to the left subtree and right subtree of the
//Binary Node and then deletes the Node upon return of previous calls
//Return: returns void because it is merely deleting the Binary Nodes
template<typename T>
void BinarySearchTree<T>::PostOrderDeletion(BinaryNode<T>* traverseNode){
	if(traverseNode!=nullptr){
		PostOrderDeletion(traverseNode->getLSTPointer());
		PostOrderDeletion(traverseNode->getRSTPointer());
		delete traverseNode;
	}
}
//Pre: The destructor takes in no parameters
//Post: Passes the root node to destroy tree which deletes the tree nodes
//Return: Returns nothing given that it is a destructor
template<typename T>
BinarySearchTree<T>::~BinarySearchTree(){
	PostOrderDeletion(m_root);

}
