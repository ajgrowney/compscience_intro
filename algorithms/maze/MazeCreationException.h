#ifndef MAZECREATIONEXCEPTION_H
#define MAZECREATIONEXCEPTION_H
#include <stdexcept>
#include <iostream>

class MazeCreationException: public std::runtime_error{

public:
  MazeCreationException(char const* message);
};

#endif
