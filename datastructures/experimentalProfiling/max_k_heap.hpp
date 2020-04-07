//Pre: Uninitialized heap class
//Post: Initializes the private member variables of the class
//Return: Constructor returns no value
template <typename T>
MaxKHeap<T>::MaxKHeap(int size){
	k = size;
	num_elements = 0;
	for(int i=0; i< 10000000; i++){
		m_array[i]=-1;
	}
}
//Pre: Exisiting heap for the val of type T to be inserted into
//Post: Place the val in the next available spot in the array
//Return: Returns void, but buildheap will be run directly after to place the value correctly
template <typename T>
void MaxKHeap<T>::insert_bottomup(T val){
	m_array[num_elements] = val;
	num_elements++;
}
//Pre: A heap is already existing and in correct min heap form
//Post: A new value has been inserted and correctly placed
//Return: Returns void
template <typename T>
void MaxKHeap<T>::insert_upheap(T val){
	m_array[num_elements] = val;
	num_elements++;
	bool check_continue = false;
	int check_value = num_elements-1;
	do{
		std::cout << "Checking "<<m_array[check_value]<< " against parent "<< m_array[(int)floor((double)(check_value-1)/(double)5)]<<"\n";
		if( check_value!= 0 && m_array[check_value] > m_array[(int)floor((double)(check_value-1)/(double)5)]){
			std::cout << "Should swap\n";
			int parent_value = (int)floor((double)(check_value-1)/(double)5);
			T tmp = m_array[check_value];
			m_array[check_value] = m_array[parent_value];
			m_array[parent_value] = tmp;
			check_value = parent_value;
			check_continue = true;


		}else{
			if(check_value == 0){
				std::cout << "Reached the root\n";
			}
			check_continue = false;
		}
	}while(check_continue);
}
//Pre: A heap exists to be rebuilt
//Post: Go through each non leaf node and verify/restructure its properties with children
//Return: returns void, but fixes the heap
template <typename T>
void MaxKHeap<T>::buildheap(){
	if(num_elements > 1){
		for(int i=((num_elements-2)/k); i>=0; i--){

			bool check_continue = false;
			int check_value = i;

			do{
				int swap_index=-1;
				int swap_value=-1;
				int compare_value = -1;

				for(int j=1; j<=5;j++){
					if(num_elements > (5*check_value + j)){
						swap_value = m_array[5*check_value+j] - m_array[check_value];

						if(swap_value > compare_value){
							compare_value = swap_value;
							swap_index = 5*check_value+j;
						}
					}

				}

				if(swap_index!=-1){
					check_continue = true;
					T tmp = m_array[check_value];
					m_array[check_value] = m_array[swap_index];
					m_array[swap_index] = tmp;
				}else{
					check_continue = false;
				}
				check_value = swap_index;

			}while(check_value < num_elements/k && check_continue);


		}
	}

}
//Pre: There exists a heap to be checked
//Post: Makes no changes to the data structure
//Return: true if empty, false otherwise
template <typename T>
bool MaxKHeap<T>::isEmpty() const{
	if(num_elements==0){
		return true;
	}else{
		return false;
	}
}
//Pre: There exists a heap to find the minimum
//Post: Finds the minimum value and deletes it from the heap
//Return: true if deleted, false otherwise
template <typename T>
bool MaxKHeap<T>::deleteMin(){
	if(!isEmpty()){
		if(num_elements > 1){
			int min_location = findMin();
			m_array[min_location] = m_array[num_elements-1];
			bool continue_check = true;
			int check_index = min_location;
			while(continue_check){
				int parent_index = (int)floor((double)(check_index-1)/(double)k);
				if(m_array[check_index] > m_array[parent_index]){
					T tmp = m_array[parent_index];
					m_array[parent_index] = m_array[check_index];
					m_array[check_index] = tmp;
					check_index = parent_index;
					continue_check = true;
				}else{
					continue_check = false;
				}
			}
			num_elements--;
			return true;
		}else{
			//Deleting only element in heap
			m_array[num_elements-1]=-1;
			num_elements--;
			return true;
		}
	}else{
		return false;
	}
}
//Pre: There exists a heap to find the minimum
//Post: Finds the minimum value in the heap
//Return: location in the array, -1 if not found
template <typename T>
int MaxKHeap<T>::findMin(){
	if(!isEmpty()){
		if(num_elements > 1){
			int least_val = -1;
			int least_index = -1;
			for(int i=((num_elements-2)/k); i < num_elements; i++){
				if(m_array[i] < least_val || least_val==-1){
					least_val = m_array[i];
					least_index = i;
				}
			}
			return least_index;
		}else{
			return 0;
		}

	}else{
		std::cout << "Heap is empty\n";
		return -1;
	}

}
//Pre: There exists a heap to find the maximum
//Post: Finds the maximum value in the heap
//Return: location in the array, -1 if not found
template <typename T>
int MaxKHeap<T>::findMax(){
	if(!isEmpty()){
		//std::cout << "Max Value: "<<m_array[0]<<"\n";
		return 0;
	}else{
		return -1;
	}

}
//Pre: There exists a heap to find the maximum
//Post: Finds the maximum value and deletes it from the heap
//Return: true if deleted, false otherwise
template <typename T>
bool MaxKHeap<T>::deleteMax(){
	if(!isEmpty()){
		if(num_elements > 1){
			m_array[0] = m_array[num_elements-1];
			m_array[num_elements-1]=-1;
			num_elements--;

			bool check_continue = false;
			int check_value = 0;

			do{
				int swap_index=-1;
				int swap_value=-1;
				int compare_value = -1;

				for(int j=1; j<=5;j++){
					if(num_elements > (5*check_value + j)){
						swap_value = m_array[5*check_value+j] - m_array[check_value];

						if(swap_value > compare_value){
							compare_value = swap_value;
							swap_index = 5*check_value+j;
						}
					}

				}

				if(swap_index!=-1){
					check_continue = true;
					T tmp = m_array[check_value];
					m_array[check_value] = m_array[swap_index];
					m_array[swap_index] = tmp;
				}else{
					check_continue = false;
				}
				check_value = swap_index;

			}while(check_value <= num_elements/k && check_continue);

		}else{
			m_array[num_elements-1]=-1;
			num_elements--;
		}

	}else{
		return false;
	}

}
//Pre: There is a heap to print
//Post: Std::out the heap through level order notation
//Return: no return value
template <typename T>
void MaxKHeap<T>::levelOrder(){
	int level=0;
	int level_cap = 1;
	for(int i=0; i< num_elements;i++){
		std::cout<< m_array[i]<<" ";

		if(i+1==level_cap){
			level++;
			std::cout<<"\n";
			level_cap = level_cap + pow(k,level);
		}else if(i%k==0){
			std::cout<<"- ";
		}

	}
	std::cout<< "\n";
}
