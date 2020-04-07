//Pre: Uninitialized heap class
//Post: Initializes the private member variables of the class
//Return: Constructor returns no value
template <typename T>
MinMaxHeap<T>::MinMaxHeap(int size){
	k = size;
	num_elements = 0;
	for(int i=0; i< 500; i++){
		m_array[i]=-1;
	}
}
//Pre: Exisiting heap for the val of type T to be inserted into
//Post: Place the val in the next available spot in the array
//Return: Returns void, but buildheap will be run directly after to place the value correctly
template <typename T>
void MinMaxHeap<T>::insert_bottomup(T val){
	num_elements++;
	m_array[num_elements] = val;
}
// Pre: Takes in the index from which to upheap
// Post: Checks the parent values and grandparent values to make recursive calls for upheaping
// Return: Returns void
template<typename T>
void MinMaxHeap<T>::upheap(int index){
	if(num_elements > 1 && index > 1){
		int check_value = index;
		bool min_node;


			if((int)floor(log2(check_value))%2!=1){

				min_node = true;

			}else{
				min_node = false;
			}

			// Check Parents

			int parent_value = check_value/k;


			if(((min_node == true && m_array[check_value] > m_array[parent_value]) || (min_node==false && m_array[check_value] < m_array[parent_value])) && parent_value > 0){
				T tmp = m_array[check_value];
				m_array[check_value] = m_array[parent_value];
				m_array[parent_value] = tmp;
				upheap(parent_value);


			}


			// Check Grandparents
			int grandparent_value = (int)floor(check_value/(4));

			if(((min_node == false && m_array[check_value] > m_array[grandparent_value]) || (min_node==true && m_array[check_value] < m_array[grandparent_value])) && grandparent_value > 0){
				T tmp = m_array[check_value];
				m_array[check_value] = m_array[grandparent_value];
				m_array[grandparent_value] = tmp;
				upheap(grandparent_value);


			}
		}
}
//Pre: A heap is already existing and in correct min heap form
//Post: A new value has been inserted and correctly placed
//Return: Returns void
template <typename T>
void MinMaxHeap<T>::insert_upheap(T val){
	num_elements++;

	m_array[num_elements] = val;

	upheap(num_elements);
}
//
//
//
template <typename T>
void MinMaxHeap<T>::buildheap_recursive(int index){
	// Check children

	int check_value = index;

	bool min_node = false;


		if((int)floor(log2(check_value))%2!=1){
			min_node=true;
		}else{
			min_node=false;
		}

		int swap_index=-1;
		int swap_value=-1;
		int compare_value = -1;

		for(int j=0; j<k;j++){
			if(num_elements >= (k*check_value+j)){
				if(min_node==true){
					swap_value = m_array[check_value] - m_array[k*check_value+j];

				}else{
					swap_value = m_array[k*check_value+j] - m_array[check_value];

				}

				if(swap_value > compare_value){
					compare_value = swap_value;
					swap_index = k*check_value+j;
				}
			}

		}

		if(swap_index!=-1){

			T tmp = m_array[check_value];
			m_array[check_value] = m_array[swap_index];
			m_array[swap_index] = tmp;
			buildheap_recursive(swap_index);

		}

	// Check grandchildren

	int compare_grandchild_index = 4*check_value;
	int compare_grandchild_value = m_array[4*check_value];


	if(min_node==false){
					//Max Node checking
					for(int grand_child = 1; grand_child < 4; grand_child++){
						if(m_array[4*check_value+grand_child] > compare_grandchild_value && (4*check_value+grand_child <=num_elements)){
							compare_grandchild_value = m_array[4*check_value + grand_child];
							compare_grandchild_index = 4*check_value+grand_child;
						}
					}

					//Swap if greatest grandhild is bigger than its grandparent (check_value)

					if(m_array[check_value] < compare_grandchild_value && ((compare_grandchild_index) <=num_elements)){
						T tmp = m_array[check_value];
						m_array[check_value] = m_array[compare_grandchild_index];
						m_array[compare_grandchild_index] = tmp;
						buildheap_recursive(compare_grandchild_index);
					}

	}else{

					//Min Node checking
					for(int grand_child = 1; grand_child < 4; grand_child++){
						if(m_array[4*check_value+grand_child] < compare_grandchild_value && ((4*check_value+grand_child) <=num_elements)){
							compare_grandchild_value = m_array[4*check_value + grand_child];
							compare_grandchild_index = 4*check_value+grand_child;
						}
					}

					//Swap if greatest grandhild is bigger than its grandparent (check_value)

					if(m_array[check_value] > compare_grandchild_value && ((compare_grandchild_index) <=num_elements)){
						T tmp = m_array[check_value];
						m_array[check_value] = m_array[compare_grandchild_index];
						m_array[compare_grandchild_index] = tmp;
						buildheap_recursive(compare_grandchild_index);
					}

	}

}



//Pre: A heap exists to be rebuilt
//Post: Go through each non leaf node and verify/restructure its properties with children
//Return: returns void, but fixes the heap
template<typename T>
void MinMaxHeap<T>::buildheap(){

	if(num_elements > 1){


		for(int i=((num_elements-1)/k); i>=1; i--){
			buildheap_recursive(i);
		}
	}

}
//Pre: There exists a heap to be checked
//Post: Makes no changes to the data structure
//Return: true if empty, false otherwise
template <typename T>
bool MinMaxHeap<T>::isEmpty() const{
	if(num_elements==0){
		return true;
	}else{
		return false;
	}

}
template <typename T>
bool MinMaxHeap<T>::deleteMin_help(int index, T holder){
	if(index < (num_elements+1)/k){
		//Index is not a leaf
		int compare_grandchild_index = 4*index;
		T compare_grandchild_value = m_array[4*index];


		//Max Node checking
		for(int grand_child = 1; grand_child < 4; grand_child++){
			if(m_array[4*index+grand_child] < compare_grandchild_value && (4*index+grand_child <=num_elements)){
				compare_grandchild_value = m_array[4*index + grand_child];
				compare_grandchild_index = 4*index+grand_child;
			}
		}

						//Swap if ;east grandhild is smaller than its grandparent (check_value)

						if(holder > compare_grandchild_value && ((compare_grandchild_index) <=num_elements)){

							m_array[index] = m_array[compare_grandchild_index];
							deleteMin_help(compare_grandchild_index, holder);

						}else{

							int swap_index = k*index;
							int compare_value = holder - m_array[k*index];
							// Check children of holder value
							for(int child = 1;child < k;child++){
								if((holder - m_array[k*index+child]) > compare_value){
									compare_value = holder - m_array[k*index+child];
									swap_index = k*index + child;
								}
							}
							//IMPLEMENT CHECK AND SWAP
							if(m_array[swap_index] < holder){
								m_array[index] = m_array[swap_index];
								m_array[swap_index] = holder;
							}else{
								m_array[index] = holder;
							}



						}


	}else{
		m_array[index] = holder;
	}
}
//Pre: There exists a heap to find the minimum
//Post: Finds the minimum value and deletes it from the heap
//Return: true if deleted, false otherwise
template <typename T>
bool MinMaxHeap<T>::deleteMin(){
	if(isEmpty()){
		return false;
	}else if(num_elements==1){
		m_array[num_elements] = -1;
		num_elements--;
	}else if(num_elements==2){
		m_array[1] = m_array[2];
		m_array[2] = -1;
		num_elements--;
	}else{
			//Find min location then shift array because min value will be a leaf
			T holder = m_array[num_elements];
			num_elements--;
			deleteMin_help(1,holder);
			return true;


	}

}
//Pre: There exists a heap to find the minimum
//Post: Finds the minimum value in the heap
//Return: location in the array, -1 if not found
template <typename T>
int MinMaxHeap<T>::findMin(){
	if(!isEmpty()){
		std::cout << "Min Value: "<<m_array[1]<<"\n";
		return 0;
	}else{
		return -1;
	}

}
//Pre: There exists a heap to find the maximum
//Post: Finds the maximum value in the heap
//Return: location in the array, -1 if not found
template <typename T>
int MinMaxHeap<T>::findMax(){
	if(!isEmpty()){
		if(num_elements > 2){
			int greatest_val;
			int greatest_index;
			if(m_array[2] > m_array[3]){
				greatest_val = m_array[2];
				greatest_index=2;
			}else{
				greatest_index=3;
				greatest_val = m_array[3];
			}
			std::cout << "Max Value: "<<greatest_val<<"\n";
			return greatest_index;

		}else{
			std::cout << "Max Value: "<<m_array[2]<<"\n";
			return 2;
		}

	}else{
		std::cout << "Heap is empty\n";
		return -1;
	}
}
template <typename T>
bool MinMaxHeap<T>::deleteMax_help(int index, T holder){
	if(index < (num_elements+1)/k){
		//Index is not a leaf
		int compare_grandchild_index = 4*index;
		T compare_grandchild_value = m_array[4*index];


		//Max Node checking
		for(int grand_child = 1; grand_child < 4; grand_child++){
			if(m_array[4*index+grand_child] > compare_grandchild_value && (4*index+grand_child <=num_elements)){
				compare_grandchild_value = m_array[4*index + grand_child];
				compare_grandchild_index = 4*index+grand_child;
			}
		}

						//Swap if greatest grandhild is bigger than its grandparent (check_value)

						if(holder < compare_grandchild_value && ((compare_grandchild_index) <=num_elements)){

							m_array[index] = m_array[compare_grandchild_index];
							deleteMax_help(compare_grandchild_index, holder);

						}else{

							int swap_index = k*index;
							int compare_value = m_array[k*index]-holder;
							// Check children of holder value
							for(int child = 1;child < k;child++){
								if((m_array[k*index+child] - holder) > compare_value){
									compare_value = m_array[k*index+child] - holder;
									swap_index = k*index + child;
								}
							}
							//IMPLEMENT CHECK AND SWAP
							if(m_array[swap_index] > holder){
								m_array[index] = m_array[swap_index];
								m_array[swap_index] = holder;
							}else{
								m_array[index] = holder;
							}



						}


	}else{
		m_array[index] = holder;
	}
}
//Pre: There exists a heap to find the maximum
//Post: Finds the maximum value and deletes it from the heap
//Return: true if deleted, false otherwise
template <typename T>
bool MinMaxHeap<T>::deleteMax(){
	if(isEmpty()){
		//Empty Heap
		return false;
	}else	if(num_elements==1){
			m_array[num_elements]=-1;
			num_elements--;
			return true;
	}else{
				//Find min location then shift array because max value will be a leaf
				//IMPLEMENT MY HELPER
				T holder = m_array[num_elements];
				num_elements--;
				if(m_array[2] > m_array[3]){
					deleteMax_help(2,holder);

				}else{
					deleteMax_help(3,holder);

				}
				return true;


	}
}
//Pre: There is a heap to print
//Post: Std::out the heap through level order notation
//Return: no return value
template <typename T>
void MinMaxHeap<T>::levelOrder(){
	int level=0;
	int level_cap = 1;
	for(int i=1; i<=num_elements;i++){
		std::cout<<m_array[i]<<" ";

		if(i==level_cap){
			level++;
			std::cout<<"\n";
			level_cap = level_cap + pow(k,level);
		}else if((i-1)%k==0){
			std::cout<<"- ";
		}

	}
	std::cout<< "\n";
}
template<typename T>
MinMaxHeap<T>::~MinMaxHeap(){
}
