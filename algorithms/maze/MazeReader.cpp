#include "MazeReader.h"

MazeReader::MazeReader(std::string userFilename) throw(MazeCreationException){
  char tmp=' ';
  std::ifstream iFile(userFilename);
  if(iFile.is_open()){
    iFile >> rows;
    iFile >> columns;
    iFile >> startRow;
    iFile >>startCol;
  }else{
      //throw MazeCreationException("Cannot open the file");
  }

  std::cout<< "Maze size: "<<getRows()<<" by "<<getCols()<<std::endl;
  std::cout<<"Starting position: "<<getStartRow()<<" by "<<getStartCol()<<std::endl;

  //myMaze creating two dimensions
  myMaze = new char* [rows];
  for(int i=0;i<rows;i++){
    myMaze[i]=new char [columns];
  }

  for(int i=0;i<rows;i++){
    for(int j=0;j<columns;j++){
      iFile >> tmp;
      myMaze[i][j]=tmp;
      std::cout<<myMaze[i][j];
    }
    std::cout<<"\n";
  }
  std::cout<<"\n";

  Maze=myMaze;
  RecWalk(Maze, getStartRow(), getStartCol(), getRows(), getCols());

}
const char* const* MazeReader::getMaze() const{
  return(myMaze);
}
int MazeReader::getRows() const{
  return(rows);
}
int MazeReader::getCols() const{
  return(columns);
}
int MazeReader::getStartRow() const{
  return(startRow);
}
int MazeReader::getStartCol() const{
  return(startCol);
}
MazeReader::~MazeReader(){

}
