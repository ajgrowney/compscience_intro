#include <iostream>
#include <string>
#include <stdlib.h>
#include "bubbleSort.cpp"
#include "insertionSort.cpp"
#include "selectionSort.cpp"
#include "mergeSort.cpp"
#include "quickSort.cpp"
#include <ctime>
//CLOCKS_PER_SEC is constant converter


int main(int argc, char** argv){
  int data_size=0;
  clock_t start_time;
  clock_t end_time;
  clock_t elapsed_time;
  double elapsed_time_secs=0.0;
  std::string initial_order="  ";
  std::string algorithm_choice=" ";
  bool isRunning=false;
  bool isInitialDataRunning=false;

  if(argc==4){
    data_size=atoi(argv[1]);
    initial_order=argv[2];
    algorithm_choice=argv[3];

  }

  std::cout<<data_size<<std::endl;
  std::cout<<initial_order<<std::endl;
  std::cout<<algorithm_choice<<std::endl;
  while(data_size<=49999){
      std::cout<<"Invalid array size, we need to house some values here! Give me a number greater than or equal to 50,000: ";
      std::cin>>data_size;
  }

  srand48(time(NULL));


//creating arrray
  double* myArr= new double[data_size];

  //Checking if initial data string is valid choice
  while(!isInitialDataRunning){
    //initializing array for increasing
    if(initial_order=="ascending"){
      isInitialDataRunning=true;
      for(int i=0;i<data_size;i++){
        myArr[i]= 0.001*static_cast<double>(i);
      }
    //initializing array for decreasing
    }else if(initial_order=="descending"){
      isInitialDataRunning=true;
      for(int i=0;i<data_size;i++){
        myArr[i]= 0.001*static_cast<double>(data_size-1-i);
      }
    //initializing array for random
    }else if(initial_order=="random"){
      isInitialDataRunning=true;
      for(int i=0;i<data_size;i++){

        myArr[i]= 100000*drand48();
      }
    //asking user for new value because invalid choice
    }else{
      std::cout<<"Invalid initial order, your choices were ascending, descending, and random\nTry entering a new initial_order: ";
      std::cin>>initial_order;
    }
  }


//Checking if Sort tupe is a valid choice
  while(!isRunning){

  if(algorithm_choice=="bubble"){
            //Running Bubble Sort
            isRunning=true;

            start_time=clock();
            bubbleSort(myArr, data_size);
            end_time=clock();
            elapsed_time=end_time-start_time;
            elapsed_time_secs=(elapsed_time/static_cast<double>(CLOCKS_PER_SEC));

            std::cout<<"\nFinished Bubble Sort in "<<elapsed_time_secs<<" seconds\n";


  }else if(algorithm_choice=="selection"){
            //Running selection sort
            isRunning=true;

            start_time=clock();
            selectionSort(myArr, data_size);
            end_time=clock();
            elapsed_time=end_time-start_time;
            elapsed_time_secs=(elapsed_time/static_cast<double>(CLOCKS_PER_SEC));




            std::cout<<"\nFinished selection sort in "<<elapsed_time_secs<<" seconds\n";

  }else if(algorithm_choice=="insertion"){
            //Running Insertion Sort
            isRunning=true;

            start_time=clock();
            insertionSort(myArr, data_size);
            end_time=clock();
            elapsed_time=end_time-start_time;
            elapsed_time_secs=(elapsed_time/static_cast<double>(CLOCKS_PER_SEC));



            std::cout<<"\nFinished insertion Sort in "<<elapsed_time_secs<<" seconds";

  }else if(algorithm_choice=="merge"){
            //Running Merge Sort
            isRunning=true;

            start_time=clock();
            mergeSort(myArr, data_size);
            end_time=clock();
            elapsed_time=end_time-start_time;
            elapsed_time_secs=(elapsed_time/static_cast<double>(CLOCKS_PER_SEC));



            std::cout<<"\nFinished merge sort in "<<elapsed_time_secs<<" seconds\n";


  }else if(algorithm_choice=="quick"){
            //Running Quick Sort
            isRunning=true;

            start_time=clock();
            quickSort(myArr, 0, data_size);
            end_time=clock();
            elapsed_time=end_time-start_time;
            elapsed_time_secs=(elapsed_time/static_cast<double>(CLOCKS_PER_SEC));



            std::cout<<"\nFinished quick sort in "<<elapsed_time_secs<<" seconds\n";


  }else{
            //reassigning algorithm choice to a valid one
            std::cout<<"Invalid algorithm choice\nTry entering a new algorithm_choice: ";
            std::cin>>algorithm_choice;

    }
  }

  delete[] myArr;


return(0);
}
