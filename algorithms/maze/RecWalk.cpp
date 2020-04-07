#include "RecWalk.h"
#include <iostream>
RecWalk::RecWalk(const char* const* mazePtr, int startRow, int startCol,int rows, int cols){

  m_visited=new int*[rows];
  for(int i=0;i<rows;i++){
      m_visited[i]=new int [cols];
  }
  for(int i=0;i<rows;i++){
      for(int j=0;j<cols;j++){
          m_visited[i][j]=0;
      }
  }
  int invalidReason=0;
  m_maze=mazePtr;
  m_curStep=0;
  m_rows=rows;
  m_cols=cols;
  m_startRow=startRow;
  m_startCol=startCol;
  m_curRow=startRow;
  m_curCol=startCol;

  bool validStartPoint=true;
  if(m_startRow>=m_rows || m_startCol>=m_cols){
      validStartPoint=false;
      invalidReason=1;
  }
  if(m_maze[m_startRow][startCol]=='W'){
      validStartPoint=false;
      invalidReason=2;
  }

  //Checks for valid start point
  if(validStartPoint==true){
      //Boolean returns true if there is an exit
      if(walk(m_curRow,m_curCol)){

              for(int i=0;i<m_rows;i++){
                for(int j=0;j<m_cols;j++){
                  std::cout<<m_visited[i][j]<<"\t";
                }
                std::cout<<"\n";
              }
      }else{
          //Returns false if no exit
          std::cout<<"No way out!!\n\n";
      }
  }else{
      if(invalidReason==1){
          std::cout<<"Invalid starting position outside of maze bounds!\n\n";
      }else if(invalidReason==2){
          std::cout<<"Attempting to start on a wall, try again!\n\n";
      }else{
          std::cout<<"Invalid starting position.\n\n";
      }
    }



}
bool RecWalk::walk(int curRow, int curCol){
  m_curRow=curRow;
  m_curCol=curCol;

  if(isGoalReached()){
    //Finds an exit
    m_curStep++;
    std::cout<<"Exit is found at ("<<m_curRow<<","<<m_curCol<<") in "<<m_curStep<<" steps\n\n\n";
    m_visited[m_curRow][m_curCol]=m_curStep;
    return true;


  }else if(m_maze[curRow][curCol]=='W'){
      //hits wall
      return false;


  }else if(m_maze[curRow][curCol]=='P'){
        //finds another possible route
        m_curStep++;

            if(m_visited[curRow][curCol]==0){

                    //hasn't been visited
                    m_visited[curRow][curCol]=m_curStep;

                            //check up
                           if(curRow>0){
                              if(walk((curRow-1),curCol)){
                                return true;
                               }
                            }

                              //look right
                            if(curCol<(m_cols-1)){
                              if(walk(curRow,(curCol+1))){
                                return true;

                              }
                            }
                            //look down
                            if(curRow<(m_rows-1)){
                              if (walk((curRow+1),curCol)){
                                return true;
                              }
                            }
                            //look left
                            if(curCol>0){

                              if(walk(curRow,(curCol-1))){
                                return true;
                              }
                            }
                    m_visited[curRow][curCol]=0;

            }
            m_curStep--;
            return false;

      }else{
      return false;

    }
}



bool RecWalk::isGoalReached() const{
  if(m_maze[m_curRow][m_curCol]=='E'){
    return true;
  }else{
    return false;
  }
}

void RecWalk::setStartRow(int tmp){
    m_startRow=tmp;
}
void RecWalk::setStartCol(int tmp){
    m_startCol=tmp;
}
