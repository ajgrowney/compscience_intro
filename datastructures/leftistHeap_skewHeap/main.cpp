#include <iostream>
#include <string>
#include "skewheap.h"
#include "leftistheap.h"
#include "concatqueue.h"

int main(int argc, char** argv){
  ConcatenatedQueue<int>* myHeap;
  if(argc!=2){
    std::cout << "Expected input: ./Lab10 leftist or ./Lab10 skew\n";
    exit(1);
  }

  if((std::string)argv[1]=="leftist"){
    myHeap = new LeftistHeap<int>();
  }else if((std::string)argv[1]=="skew"){
    myHeap = new SkewHeap<int>();
  }
  myHeap->build();

  int menuChoice = 0;

  while(menuChoice!=6){
    std::cout<<"\n";
    std::cout << "Please choose one of the following commands:\n1)Insert\n2)deleteMin\n3)Preorder\n4)Inorder\n5)LevelOrder\n6)End\n";
    std::cin >> menuChoice;
    if(menuChoice==1){
      std::cout << "Enter number to be inserted:\n";
      int insertVal;
      std::cin >> insertVal;
      myHeap->insert(insertVal);
    }else if(menuChoice==2){
      myHeap->deleteMin();
    }else if(menuChoice==3){
      myHeap->preorder();
    }else if(menuChoice==4){
      myHeap->inorder();
    }else if(menuChoice==5){
      myHeap->levelorder();
    }else if(menuChoice==6){
      std::cout <<"Goodbye\n";
    }else{
      std::cout<<"Invalid menu choice\n";
    }
  }

  delete myHeap;
  return 0;
}
