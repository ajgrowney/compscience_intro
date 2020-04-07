#include "TestSuite.h"

//Constructor of Test Suite
TestSuite::TestSuite(LinkedListOfInts importedTestList){
  testList = importedTestList;
  manualListCount = 0;

}

//Running all the tests
void TestSuite::runTests(){
  std::cout << "\n\n---------------Beginning to Run Tests-------------------\n";

  std::cout<<"1) Checking to see if the list created is verified to be empty\n\n";
  if(testList.isEmpty()){
    std::cout << "The new list is empty. Success.\n";
  }else{
    std::cout << "The list is not empty. Make correction\n";
  }

  std::cout <<"\n\n-----------------2) Checking series of addBack calls--------------\n\n";

  testAddBack(3);
  testAddBack(7);
  testAddBack(9);

  std::cout <<"\n\n----------------3) Checking a series of addFront calls-------------\n\n";
  testAddFront(2);
  testAddFront(42);

  std::cout <<"\n\n----------------4) Verify size method of the list------------------\n\n";
  if(testSize()){
    std::cout << "The size method is working correctly."<<std::endl;
  }else{
    std::cout << "The size method contains errant code\n";
    std::cout << "The test count of additions: "<<manualListCount<<std::endl;
    std::cout << "The provided methods count: "<<testList.size()<<std::endl;
  }

  std::cout <<"\n\n----------------5) Checking a Remove Back Method Call----------------\n\n";

  testRemoveBack();

  std::cout <<"\n\n----------------6) Checking a Remove Front Method Call----------------\n\n";

  testRemoveFront();
  std::cout << "\nThe total length of the list is: "<<testList.size() <<std::endl;

  std::cout <<"\n\n----------------7) Checking a isEmpty Method Call----------------\n\n";

  if(testIsEmpty() && manualListCount == 0){
    std::cout << "The list is empty. Code for isEmpty() is correct\n";
  }else{
    std::cout << "The isEmpty() function is working improperly and needs to be fixed\n";
  }
}

bool TestSuite::testIsEmpty(){
  if(testList.isEmpty()){
    return true;
  }else{
    return false;
  }

}

bool TestSuite::testAddBack(int newVar){
  testList.addBack(newVar);
  if(testList.search(newVar)==false){
    std::cout << "It wasn't added to the list\n";
    return false;
  }else{
    std::cout << "addBack added "<<newVar<<" to the list\n";
    std::cout << "New List size is: "<<testList.size()<<std::endl;
    std::vector<int> v = testList.toVector();
    for(int i = 0; i < v.size(); i++){
      std::cout<< v.at(i)<<std::endl;
    }
    manualListCount++;
    return true;
  }
}
bool TestSuite::testAddFront(int newVar){
  testList.addFront(newVar);
  if(testList.search(newVar)==false){
    std::cout << "It wasn't added to the list\n";
    return false;
  }else{
    std::cout << "addFront added "<<newVar<<" to the list\n";
    std::cout << "New List size is: "<<testList.size()<<std::endl;
    std::vector<int> v = testList.toVector();
    for(int i = 0; i < v.size(); i++){
      std::cout<< v.at(i)<<std::endl;
    }
    manualListCount++;
    return true;
  }
}
bool TestSuite::testRemoveBack(){

  std::vector<int> v = testList.toVector();

  std::cout << "The current back of the list is: "<< v.at(testList.size()-1)<<std::endl;

  int sizeBefore = testList.size();
  testList.removeBack();
  int sizeAfter = testList.size();


  if(sizeAfter==sizeBefore){

    std::cout << "The remove back function did not work.\nCurrent List: "<<std::endl;
    for(int i = 0; i < v.size(); i++){
      std::cout<< v.at(i)<<std::endl;
    }
    return false;

  }else{

    std::cout << "The new back of the list is: "<< v.at(testList.size()-1)<<std::endl;
    manualListCount--;
    return true;

  }

}

bool TestSuite::testRemoveFront(){
  std::vector<int> v = testList.toVector();

  std::cout << "The current front of the list is: "<< v.at(0)<<std::endl;

  int sizeBefore = testList.size();
  testList.removeFront();
  int sizeAfter = testList.size();


  if(sizeAfter==sizeBefore){

    std::cout << "The remove front function did not work.\nCurrent List: "<<std::endl;
    for(int i = 0; i < v.size(); i++){
      std::cout<< v.at(i)<<std::endl;
    }
    return false;

  }else{

    std::cout << "The new front of the list is: "<< v.at(0)<<std::endl;
    manualListCount--;
    return true;

  }
}

bool TestSuite::testSize(){
  if(testList.size()!=manualListCount){
    return false;
  }else{
    return true;
  }
}
