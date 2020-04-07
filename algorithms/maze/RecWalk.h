#ifndef RECWALK_H
#define RECWALK_H

class RecWalk{

public:
  RecWalk(const char* const* mazePtr, int startRow, int startCol, int rows, int cols);
  bool walk(int curRow, int curCol);
  void setStartRow(int tmp);
  void setStartCol(int tmp);
  //~RecWalk();

private:
  const char* const* m_maze;
  int** m_visited;
  int m_rows, m_cols;
  int m_curRow, m_curCol;
  int m_startRow, m_startCol;
  int m_curStep;
  bool isGoalReached() const;
};
#endif
