#include "Pipe.h"
#include <iostream>
#include <ostream>
#include "colors.h"
#include "raylib.h"
Pipe::Pipe() {
  top = GetRandomValue(0, 400);
  bottom = GetRandomValue(0, 400);
  x = 450;
  width = 20;
  speed = 5;
  passed = false;
}

void Pipe::draw()
{
  DrawRectangle(x, 0, width, top, MY_SOFT_VIOLET);
  DrawRectangle(x, 800 - bottom, width, bottom, MY_SOFT_VIOLET);
}

void Pipe::update()
{
  x -= speed;
}

bool Pipe::hits(Bird bird)
{
  Rectangle birdRec =
    {bird.pos.x, bird.pos.y, (float)bird.width, (float)bird.height};
  Rectangle topRec =
    {(float)x, 0, (float)width, (float)top};
  Rectangle bottomRect =
    {(float)x, 800 - (float)bottom, (float)width, (float)bottom };

  if(CheckCollisionRecs(topRec, birdRec) || CheckCollisionRecs(bottomRect, birdRec))
    {
      return true;
    }

  return false;
}
