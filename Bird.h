#ifndef BIRD_H
#define BIRD_H

#include <raylib.h>

class Bird {
 public:
  Vector2 pos;
  int width;
  int height;
  Color color;
  float gravity = 0.3;
  float velocity = 0;

  void up();
  void draw();
  void update();
};

#endif
