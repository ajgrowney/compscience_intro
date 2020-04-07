#include "Executive.h"
#include <iostream>
#include <limits>
#include <string>

Executive::Executive(){
    menuChoice=0;
}
void Executive::run(){

    //Menu Main Screen
    std::cout<<"\n\nWelcome to the Laboratory 5 Menu\n\n";

    do{
        std::cout<<"\n-------------------------------------------------------------------------------------------\n";
        std::cout<<"Please make your selection by entering the number of corresponding menu choice:\n(1) List Reversal\n(2) Compute\n(3) Quadtree\n(4) Quit\n\n";
        std::cin>>menuChoice;
    while ( std::cin.fail() || menuChoice > 4 || menuChoice < 1)
      {
        if(std::cin.fail()){
          std::cin.clear(); // unset failbit
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // skip bad input
          std::cout << "Sorry, your input did not seem to be an int. Try again: ";
          std::cin >> menuChoice;
          std::cout<<" "<<std::endl;

        }else if(menuChoice > 4){
            std::cout<<"Sorry, the menu does not extend to your selection. Try again: ";
            std::cin>> menuChoice;
            std::cout<<" "<<std::endl;

        }else if(menuChoice < 1){
            std::cout<<"Sorry, the menu begins at 1. Select a number between 1 and 4: ";
            std::cin>>menuChoice;
            std::cout<<" "<<std::endl;
        }
      }

    //user has made their choice and it is saved under the private member variable "menuChoice"

    std::cout<<"----------------------------------------------------------------------\n";
    if(menuChoice==1){
        //--------------------------LIST REVERSAL PROGRAM-----------------------------------
        std::string filename;
        std::cout<<"\nList Reversal\n\n";
        std::cout<<"Please enter the file name containing the strings you would like to reverse: ";
        std::cin>>filename;

        revList.reverseList(filename);


        //-----------------------END OF LIST REVERSAL PROGRAM-------------------------------
    }else if(menuChoice==2){
        //--------------------------C(N) PROGRAM-------------------------------------------
        int n,p=0;
        std::cout<<"\nC(n) Program\n";
        std::cout<<"Please enter the integer that you would like to use: ";
        std::cin>>n;
        while ( std::cin.fail()){
              std::cin.clear(); // unset failbit
              std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // skip bad input
              std::cout << "Sorry, your input did not seem to be an int. Try again: ";
              std::cin >> n;
              std::cout<<" "<<std::endl;
        }
        std::cout<<"Enter 1 if you would like to include permutations or 2 if you'd like to ignore permutations: ";
        std::cin>>p;
        while ( std::cin.fail() || p>2|| p<1){
            if(std::cin.fail()){
              std::cin.clear(); // unset failbit
              std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // skip bad input
              std::cout << "Sorry, your input did not seem to be an int. Try again: ";
              std::cin >> p;
              std::cout<<" "<<std::endl;
            }else{
                std::cout<<"Enter one or two: ";
                std::cin >> p;
                std::cout<<" "<<std::endl;
            }

        }
        int myArr[n];
        for(int i=n;i>0;i--){
            myArr[i]=0;
        }
        if(p==1){
          std::cout<<"\nShowing results with permutations: ";
          for(int i=(n);i>0;i--){
            myArr[0]=i;
            partitionIntegerWith(n,myArr,1);
          }
          std::cout<<CN;
        }else{
          std::cout<<"\nShowing results disregarding permutations: ";
          for(int i=(n);i>0;i--){
              myArr[0]=i;
              partitionInteger(n,myArr,1);
          }
          std::cout<<CN;
        }

        CN=0;






        //-------------------------END OF C(N) PROGRAM-------------------------------------
    }else if(menuChoice==3){

        //----------------------QUADTREE PROGRAM------------------------------------

        std::string filename;
        int Q[64][64];
        std::cout<<"\nQuadtree\n\n";
        std::cout<<"Please enter the file name containing the quadtree you wanted to analyze: ";
        std::cin>>filename;
        std::ifstream iFile;
        //validating document input
            iFile.open(filename);
            if(!iFile.is_open()){
            std::cout<<"I'm sorry, there's been an issue finding the file you entered. Try making sure you have it properly placed and named correctly.\nEnter the filename: ";
            std::cin>>filename;
            }else{
                std::cout<<"Checkpoint\n";
                    for(int i=0;i <64; i++){

                        for(int j=0;j<64;j++){

                            std::string curr;
                            iFile >> curr;
                            if(curr!= "1" && curr !="0"){
                                throw std::runtime_error("Something's wrong");
                            }
                            int num = std::stoi(curr);
                            Q[i][j]=num;
                            std::cout<<Q[i][j];


                        }
                        std::cout<<"\n";
                    }
            }
        iFile.close();
        std::cout<<"Checkpoint 2\n";

        reportSimpleCellsIn(Q, 0, 64, 0, 64);

        //------------END OF QUADTREE PROGRAM-----------------------------------------



    }else{
        std::cout<<"Thanks for running the laboratory 5 program! Have a great day!\n";
    }
    }while(menuChoice!=4);

}

void Executive::reportSimpleCellsIn(int Q[64][64], int frontRow, int lastRow, int firstColumn, int lastColumn){
    int num=1;
    int numOfOnes=0;
    for(int i=frontRow; i< (lastRow);i++){
        for(int j=firstColumn; j< (lastColumn);j++){

            num=Q[i][j];

            if(num==1){
               numOfOnes++;
            }
        }

    }
    //std::cout<<"Currently "<<numOfOnes<<" one(s) in this region"<<std::endl;





    if(numOfOnes==0){
        std::cout<<"Report:\nRow "<<frontRow<<" through "<<lastRow<<"\nColumn "<<firstColumn<<" through "<<lastColumn<< "\nStatus: Empty\n";
    }else if(numOfOnes==1){
        std::cout<<"Report:\nRow "<<frontRow<<" through "<<lastRow<<"\nColumn "<<firstColumn<<" through "<<lastColumn<< "\nStatus: One\n";
    }else{
            int midRow=((frontRow+lastRow)/2);
            int midColumn=((firstColumn+lastColumn)/2);

            std::cout<<"NW\n";
            reportSimpleCellsIn(Q, frontRow, midRow, firstColumn, midColumn);
            std::cout<<std::endl;

            std::cout<<"NE\n";
            reportSimpleCellsIn(Q, frontRow, midRow, midColumn, lastColumn);
            std::cout<<std::endl;

            std::cout<<"SE\n";
            reportSimpleCellsIn(Q, midRow, lastRow, midColumn, lastColumn);
            std::cout<<std::endl;

            std::cout<<"SW\n";
            reportSimpleCellsIn(Q, midRow, lastRow, 0, midColumn);
            std::cout<<std::endl;

    }

}

void Executive::partitionInteger(int n, int arr[], int i){
    if(sum(arr,n)==n){
      CN++;
    }else if(sum(arr,n)<n){
        for(int j=arr[i-1];j>0;j--){
            arr[i]=j;
            partitionInteger(n,arr,i+1);
        }
      }
}
void Executive::partitionIntegerWith(int n, int arr[], int i){
    if(sum(arr,n)==n){
      CN++;
    }else if(sum(arr,n)<n){
        for(int j=arr[i-1];j>0;j--){
            arr[i]=j;
            partitionIntegerWith(n,arr,i+1);
        }
    }
}
int Executive::sum(int arr[], int n){
    int total=0;
    for(int i=0;i<n;i++){
        total=total+arr[i];
    }
    return total;
}

Executive::~Executive(){

}
