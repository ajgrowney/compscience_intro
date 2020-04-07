#include <fstream>
#include <iostream>

template <typename T>
LinkedList<T>::LinkedList()
{
m_length=0;
m_front=nullptr;
}
template <typename T>
int LinkedList<T>:: getLength() const{
  return m_length;
}

template <typename T>
void LinkedList<T>::addBack(T val){
    bool isAdded=false;
    //creation of new node with string value
    Node<T>* newBack=new Node<T>();
    newBack->setValue(val);

    //empty Linked List check
    if(m_front==nullptr){
        m_front=newBack;
        newBack->setNext(nullptr);
        isAdded=true;
        m_length++;
    }

    //tmp node traversing the list until nullptr
    while(!isAdded){
    Node<T>* tmp=m_front;
    Node<T>*tmp2=tmp->getNext();
    while(tmp2!=nullptr){
        tmp=tmp->getNext();
        tmp2=tmp->getNext();
    }
    tmp->setNext(newBack);
    newBack->setNext(nullptr);
    m_length++;
    isAdded=true;
    }
}

template <typename T>
void LinkedList<T>::reverseList(std::string filename){
    bool validInput=false;
    std::string tmp0,tmp1,tmp2;
    std::ifstream iFile;

    //original list creation
    while(!validInput){
        std::ifstream iFile(filename);
        if(!iFile.is_open()){
        std::cout<<"I'm sorry, there's been an issue finding the file you entered. Try making sure you have it properly placed and named correctly.\nEnter the filename: ";
        std::cin>>filename;
        }else{
            int pos=1;
            validInput=true;
            iFile >> tmp0;
            while(!iFile.eof()){
                if(tmp0!= "\n"){
                  addBack(tmp0);
                }
                iFile >>tmp0;
                pos++;

            }

            //print orignial list
            int count=1;
            std::cout<<"Here is the original list: ";
            while(count<=m_length){
              tmp1=getEntry(count);
              std::cout<<tmp1<<" ";
              count++;
            }
            std::cout<<" "<<std::endl;
            //recursive reversal of list
            recReverseList(m_front);

            int counter=1;
            std::cout<<"Here is the reversed list: ";
            while(counter<=m_length){
              //std::cout<<"Checkpoint 3\n";
              tmp2=getEntry(counter);
              //std::cout<<"Checkpoint 4\n";
              std::cout<<tmp2<<" ";
              counter++;
            }
            std::cout<<" "<<std::endl;


        }
        iFile.close();
    }


}

template <typename T>
void LinkedList<T>::recReverseList(Node<T>* cur){
  Node<T>* tmp=cur->getNext();
  if(tmp->getNext()==nullptr){
    m_front=tmp;
    tmp->setNext(cur);
    }else{
      recReverseList(tmp);
      tmp->setNext(cur);
    }
    //std::cout<<"Checkpoint 6\n";
}

template <typename T>
T LinkedList<T>::getEntry(int pos){
    int count=1;
    Node<T>* tmp=m_front;
    while(count<(pos)){
        tmp=tmp->getNext();
        count++;
    }
    return(tmp->getValue());
}

template <typename T>
LinkedList<T>::~LinkedList(){

}
