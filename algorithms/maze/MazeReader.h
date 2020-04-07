#ifndef MAZEREADER_H
#define MAZEREADER_H
#include <fstream>
#include <iostream>
#include <string>
#include "RecWalk.h"
#include "MazeCreationException.h"
class MazeReader{

public:
  MazeReader(std::string filename) throw(MazeCreationException);
  ~MazeReader();
  const char* const* getMaze() const;
  int getCols() const;
  int getRows() const;
  int getStartCol() const;
  int getStartRow() const;
private:
  int rows, columns, startRow, startCol;
  char** myMaze;
  const char* const* Maze;


};

#endif
