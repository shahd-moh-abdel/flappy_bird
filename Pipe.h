#ifndef PIPE_H
#define PIPE_H

#include "raylib.h"

class Pipe {
 public:
  int top;
  int bottom;
  int x;
  int width;
  int speed;

  Pipe();

  void draw();
  void update();
};

#endif
