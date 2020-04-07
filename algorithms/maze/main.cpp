#include <iostream>
#include <string>
#include "MazeReader.h"

int main(){
    std::string userFilename=" ";
    char runIt= ' ';
    std::cout<<"Welcome to the Maze Runner Program!\n";
    do{
    std::cout<<"\nEnter the filename that contains your maze: ";
    std::cin>>userFilename;
    MazeReader myMazeReader(userFilename);
    std::cout<<"Would you like to run it back?: (Y/N): ";
    std::cin>>runIt;
    }while(runIt!='N');

    std::cout<<"\n\nThanks!";

return(0);
}
