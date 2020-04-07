#include <iostream>
#include <fstream>
#include "minmaxheap.h"
#include "maxminheap.h"

// Command Line args: ./Lab7 Max or ./Lab7 Min

int main(int argc, char* argv[]){
	HeapInterface<int>* MyHeap;
	int input;
	std::ifstream reader("data.txt");
	//Determine which type of Heap
	if( (std::string)argv[1] == "Min"){
		MyHeap = new MinMaxHeap<int>(2);
		while(reader >> input){
			MyHeap->insert_bottomup(input);
		}
		MyHeap->buildheap();

	}else{
		MyHeap = new MaxMinHeap<int>(2);
		while(reader >> input){
			MyHeap->insert_upheap(input);
		}
	}

	//Initialize the array


	//Heapify the m_array
	MyHeap->levelOrder();

	int menuChoice = 0;
	while(menuChoice !=7){
		std::cout<<"\n---------------------------------------\nPlease choose one of the following commands:\n";
		std::cout<<"1- insert\n2-deleteMin\n3-findMin\n4-findMax\n5-deleteMax\n6-levelOrder\n7-exit\n";
		std::cin>>menuChoice;
		if(menuChoice==1){
			int insert_val;
			std::cout << "Enter a value to be inserted:\n";
			std::cin >> insert_val;
			MyHeap->insert_upheap(insert_val);
			MyHeap->levelOrder();
		}else if(menuChoice==2){
			MyHeap->deleteMin();
		}else if(menuChoice==3){
			MyHeap->findMin();
		}else if(menuChoice==4){
			MyHeap->findMax();
		}else if(menuChoice==5){
			MyHeap->deleteMax();
		}else if(menuChoice==6){
				MyHeap->levelOrder();
		}else if(menuChoice==7){
			delete MyHeap;
			std::cout <<"Bye bye\n";
		}
	}





	return 0;
}
