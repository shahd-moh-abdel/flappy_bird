#ifndef BIRD_H
#define BIRD_H

#include <raylib.h>

class Bird {
 public:
  Vector2 pos;
  int width;
  int height;
  Color color;
  int gravity = 1;
  int velocity = 0;

  void up();
  void draw();
  void update();
};

#endif
