//Pre: Constructor
//In: initialize first ran to false in order to prevent unintialized data from
//being called
//Post: no return value in constructor
Executive::Executive(){
	myMaxKHeap = nullptr;
	myMinKHeap = nullptr;
	myBST = nullptr;
	firstTestRan = false;
	for(int i=0; i<5;i++){
		MinKFinalBuild[i] = 0;
		MinKFinalDeleteMin[i] = 0;
		MinKFinalDeleteMax[i] = 0;
		BSTFinalBuild[i] = 0;
		BSTFinalDeleteMin[i] = 0;
		BSTFinalDeleteMax[i] = 0;
		MaxKFinalBuild[i] = 0;
		MaxKFinalDeleteMin[i] = 0;
		MaxKFinalDeleteMax[i] = 0;
	}
}
//Pre: Takes in an array and the array's size
//In: Calculates the sum to convert to average from the size
//Post: returns the average value of the array
int Executive::calcAverage(int myArr[], int arr_size){
	int sum=0;
	for(int index = 0; index < 5;  index++){
		sum+=myArr[index];
	}
	int average = sum/5;
	return average;
}
//Pre: Takes in no parameters
//In: Displays private member variables containing experimental results
//Post: Returns nothing, meant to cout variables
void Executive::displayResults(){
	std::cout<<"\n----------------------------\n";
	std::cout << "Performance(Min 5 Heap):\n";
	std::cout << "\t\t0.1m\t0.2m\t0.3m\t0.4m\t0.5m\nBuild\t\t";
	for(int final_results = 0; final_results < 5; final_results++){
		std::cout << MinKFinalBuild[final_results]<<"\t";
	}
	std::cout <<"\ndeleteMin\t";
	for(int final_results = 0; final_results < 5; final_results++){
		std::cout << MinKFinalDeleteMin[final_results]<<"\t";
	}
	std::cout <<"\ndeleteMax\t";
	for(int final_results = 0; final_results < 5; final_results++){
		std::cout << MinKFinalDeleteMax[final_results]<<"\t";
	}
	std::cout <<"\n";
	std::cout<<"\n----------------------------\n";

	std::cout << "Performance(Max 5 Heap):\n";
	std::cout << "\t\t0.1m\t0.2m\t0.3m\t0.4m\t0.5m\nBuild\t\t";
	for(int final_results = 0; final_results < 5; final_results++){
		std::cout << MaxKFinalBuild[final_results]<<"\t";
	}
	std::cout <<"\ndeleteMin\t";
	for(int final_results = 0; final_results < 5; final_results++){
		std::cout << MaxKFinalDeleteMin[final_results]<<"\t";
	}
	std::cout <<"\ndeleteMax\t";
	for(int final_results = 0; final_results < 5; final_results++){
		std::cout << MaxKFinalDeleteMax[final_results]<<"\t";
	}
	std::cout <<"\n";
	std::cout<<"\n----------------------------\n";

	std::cout << "Performance(BST):\n";
	std::cout << "\t\t0.1m\t0.2m\t0.3m\t0.4m\t0.5m\nBuild\t\t";
	for(int final_results = 0; final_results < 5; final_results++){
		std::cout << BSTFinalBuild[final_results]<<"\t";
	}
	std::cout <<"\ndeleteMin\t";
	for(int final_results = 0; final_results < 5; final_results++){
		std::cout << BSTFinalDeleteMin[final_results]<<"\t";
	}
	std::cout <<"\ndeleteMax\t";
	for(int final_results = 0; final_results < 5; final_results++){
		std::cout << BSTFinalDeleteMax[final_results]<<"\t";
	}
	std::cout <<"\n";
	std::cout<<"\n----------------------------\n";


}

//Pre: Takes in the table size to create the parameters for random numbers
//In: Tests the timing for inserting in the hash tables
//Post: Returns void but saves the values to private member variables to be
//displayed later
void Executive::testBuild(int m){
	clock_t start_time = 0;
	clock_t end_time = 0;
	int multiplier[5] = {1,2,3,4,5};
	// Trial Size = 1/10, 2/10, 3/10, 4/10,5/10
	for(int trial_size = 0; trial_size < 5; trial_size++){

		for(int trial_number = 0; trial_number < 5; trial_number++){
			myBST = new BinarySearchTree<int>();
			myMinKHeap = new MinKHeap<int>(5);
			myMaxKHeap = new MaxKHeap<int>(5);

			int arraySize = m*multiplier[trial_size];

			std::cout << "Inserting "<<arraySize<<" values\n";
			//Create the Random Seed
			srand(time(NULL));


			//Generate Numbers to Insert
			int* myInsertArr = new int[arraySize];
			for(int i = 0; i < arraySize ; i++){
				//Create Random numbers based off the seed generated
				myInsertArr[i] = (rand() % (5*(m)))+1;
			}




			//Time the Inserting of array into MaxK Probing Hash Table
			start_time = clock();
			for(int k = 0; k < arraySize; k++){
				myMinKHeap->insert_bottomup(myInsertArr[k]);
			}
			myMinKHeap->buildheap();
			end_time = clock();

			MinK_Build_Trial[trial_number] = end_time - start_time;


			//Time the Inserting of array into BST Hash Table
			start_time = clock();
			for(int l = 0; l < arraySize; l++){
				myMaxKHeap->insert_bottomup(myInsertArr[l]);
			}
			myMaxKHeap->buildheap();
			end_time = clock();

			MaxK_Build_Trial[trial_number] = end_time - start_time;


			//Time the Inserting of array into Open Hash Table
			start_time = clock();
			for(int j=0; j < arraySize; j++){
				myBST->insert(myInsertArr[j]);
			}
			end_time = clock();
			BST_Build_Trial[trial_number] = end_time - start_time;

			//
			//Testing delete
			//

			int deleteSize = m*(double(multiplier[trial_size])/double(1000));
			std::cout << "Removing min/max "<<deleteSize<<" times\n";

			//Time the deletMin and deleteMax of heaps

			start_time = clock();
			for(int j=0; j < deleteSize; j++){
				myMinKHeap->deleteMin();
			}
			end_time = clock();
			MinK_DeleteMin_Trial[trial_number] = end_time-start_time;

			start_time = clock();
			for(int j=0; j < deleteSize; j++){
				myMinKHeap->deleteMax();
			}

			end_time = clock();
			MinK_DeleteMax_Trial[trial_number] = end_time-start_time;

			//Time the Find of array in MaxK Probing Hash Table
  		start_time = clock();
			for(int j=0; j < deleteSize; j++){
				myMaxKHeap->deleteMin();
			}
			end_time = clock();
			MaxK_DeleteMin_Trial[trial_number] = end_time-start_time;


			start_time = clock();
			for(int j=0; j < deleteSize; j++){
				myMaxKHeap->deleteMax();
			}

			end_time = clock();
			MaxK_DeleteMax_Trial[trial_number] = end_time-start_time;

			//Time the Find of array in BST Hash Table
			start_time = clock();
			for(int j=0; j < deleteSize; j++){
				myBST->removeMin(myBST->getRootPtr());
			}
			end_time = clock();
			BST_DeleteMin_Trial[trial_number] = end_time-start_time;


			start_time = clock();
			for(int j=0; j < deleteSize; j++){
				myBST->removeMax(myBST->getRootPtr());
			}
			end_time = clock();
			BST_DeleteMax_Trial[trial_number] = end_time - start_time;

			delete myBST;
			myBST = nullptr;
			delete myMinKHeap;
			myMinKHeap = nullptr;
			delete myMaxKHeap;
			myMaxKHeap = nullptr;
			delete myInsertArr;

		}

		//End of One trial

		int MinK_Build_average = calcAverage(MinK_Build_Trial,5);
		int BST_build_average = calcAverage(BST_Build_Trial,5);
		int MaxK_build_average = calcAverage(MaxK_Build_Trial,5);

		MinKFinalBuild[trial_size] = MinK_Build_average;
		BSTFinalBuild[trial_size] = BST_build_average;
		MaxKFinalBuild[trial_size] = MaxK_build_average;

		int MinK_DeleteMin_average = calcAverage(MinK_DeleteMin_Trial,5);
		int BST_DeleteMin_average = calcAverage(BST_DeleteMin_Trial,5);
		int MaxK_DeleteMin_average = calcAverage(MaxK_DeleteMin_Trial,5);
		int MinK_DeleteMax_average = calcAverage(MinK_DeleteMax_Trial,5);
		int BST_DeleteMax_average = calcAverage(BST_DeleteMax_Trial,5);
		int MaxK_DeleteMax_average = calcAverage(MaxK_DeleteMax_Trial,5);

		MinKFinalDeleteMin[trial_size] = MinK_DeleteMin_average;
		BSTFinalDeleteMin[trial_size] = BST_DeleteMin_average;
		MaxKFinalDeleteMin[trial_size] = MaxK_DeleteMin_average;
		MinKFinalDeleteMax[trial_size] = MinK_DeleteMax_average;
		BSTFinalDeleteMax[trial_size] = BST_DeleteMax_average;
		MaxKFinalDeleteMax[trial_size] = MaxK_DeleteMax_average;
	}
	//End of Build
}
//Pre: Takes in the table size to create the parameters for random numbers
//In: Tests the timing for finding in the hash tables
//Post: Returns void but saves the values to private member variables to be
//accessed later

/*
void Executive::testDelete(int table_size_input){
	clock_t start_time;
	clock_t end_time;


	int random_num_size[5] = {1,2,3,4,5};
	// Trial Size = 1/100, 2/100, 3/100, 4/100,5/100
	for(int trial_size = 0; trial_size < 5; trial_size++){
		std::cout <<".";
		for(int trial_number = 0; trial_number < 5; trial_number++){
			int deleteSize = table_size_input*(double(random_num_size[trial_size])/double(1000));
			std::cout << "Removing min/max "<<deleteSize<<" times\n";

			//Time the deletMin and deleteMax of heaps

			start_time = clock();
			sleep(1);
			for(int j=0; j < deleteSize; j++){
				myMinKHeap->deleteMin();
			}
			end_time = clock();
			MinK_DeleteMin_Trial[trial_number] = end_time-start_time;

			start_time = clock();
			for(int j=0; j < deleteSize; j++){
				myMinKHeap->deleteMax();
			}

			end_time = clock();
			MinK_DeleteMax_Trial[trial_number] = end_time-start_time;

			//Time the Find of array in MaxK Probing Hash Table
  			start_time = clock();
			for(int j=0; j < deleteSize; j++){
				myMaxKHeap->deleteMin();
			}
			end_time = clock();
			MaxK_DeleteMin_Trial[trial_number] = end_time-start_time;


			start_time = clock();
			for(int j=0; j < deleteSize; j++){
				myMaxKHeap->deleteMax();
			}

			end_time = clock();
			MaxK_DeleteMax_Trial[trial_number] = end_time-start_time;

			//Time the Find of array in Double Hash Table
			start_time = clock();
			for(int j=0; j < deleteSize; j++){
				myBST->removeMin(myBST->getRootPtr());
			}
			end_time = clock();
			BST_DeleteMin_Trial[trial_number] = end_time-start_time;


			start_time = clock();
			for(int j=0; j < deleteSize; j++){
				myBST->removeMax(myBST->getRootPtr());
			}
			end_time = clock();
			BST_DeleteMax_Trial[trial_number] = end_time - start_time;

		}
		//End of One trial

		int MinK_DeleteMin_average = calcAverage(MinK_DeleteMin_Trial,5);
		int BST_DeleteMin_average = calcAverage(BST_DeleteMin_Trial,5);
		int MaxK_DeleteMin_average = calcAverage(MaxK_DeleteMin_Trial,5);
		int MinK_DeleteMax_average = calcAverage(MinK_DeleteMax_Trial,5);
		int BST_DeleteMax_average = calcAverage(BST_DeleteMax_Trial,5);
		int MaxK_DeleteMax_average = calcAverage(MaxK_DeleteMax_Trial,5);

		MinKFinalDeleteMin[trial_size] = MinK_DeleteMin_average;
		BSTFinalDeleteMin[trial_size] = BST_DeleteMin_average;
		MaxKFinalDeleteMin[trial_size] = MaxK_DeleteMin_average;
		MinKFinalDeleteMax[trial_size] = MinK_DeleteMax_average;
		BSTFinalDeleteMax[trial_size] = BST_DeleteMax_average;
		MaxKFinalDeleteMax[trial_size] = MaxK_DeleteMax_average;
	}
	//End of Find

}

*/
//Pre: Takes in the size of the table
//In: Creates the new Hash Tables for experimenting
//Post: returns void but makes two function calls to create the tests
void Executive::testTreesAndHeaps(int table_size_input){

	testBuild(table_size_input);
	std::cout << "\nFinished testing build\n";
	std::cout << "Testing deleteMin and deleteMax...";
	//testDelete(table_size_input);
	std::cout <<"\n";

}
//Pre: Takes in no parameters
//In: Runs the main menu and options for the user
//Post: Returns void but finishes the program
void Executive::run(){
	int menuChoice = 0;
	while(menuChoice!=3){
		std::cout << "Please choose one of the following commands:\n1-Test Performance\n2- Performance Comparison\n3-Exit\n";
		std::cin >> menuChoice;
		if(menuChoice==1){
			int tableSizeInput;
			std::cout << "What is the size (m-value)?\n";
			std::cin >> tableSizeInput;
			std::cout << "Testing Build...";
			firstTestRan = true;
			if(firstTestRan){
				testTreesAndHeaps(tableSizeInput);
			}
		}else if(menuChoice==2){
			if(firstTestRan){
				displayResults();
			}else{
				std::cout << "Try testing the performance before viewing the results\n";
			}
		}else if(menuChoice==3){
			std::cout << "Byebye!\n";
		}
	}
}
