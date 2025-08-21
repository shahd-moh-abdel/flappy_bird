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

  Texture2D frames[4];
  int currentFrame;
  float frameTimer;

  Bird(Vector2 p, int w, int h, Color c)
  {
    pos = p;
    width = w;
    height = h;
    color = c;
    currentFrame = 0;
    frameTimer = 0.0f;
  };
  

  void up();
  void draw();
  void update();
  void initSprites();
};

#endif
