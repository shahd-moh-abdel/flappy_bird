#ifndef BIRD_H
#define BIRD_H

#include <raylib.h>

class Bird {
 public:
  Vector2 pos;
  int width;
  int height;
  Color color;

  void draw();
  void update();
};

#endif
