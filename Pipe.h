#ifndef PIPE_H
#define PIPE_H

#include "raylib.h"
#include "Bird.h"

class Pipe {
 public:
  int top;
  int bottom;
  int x;
  int width;
  int speed;
  bool passed;

  Pipe();

  void draw();
  void update();
  bool hits(Bird bird);
};

#endif
