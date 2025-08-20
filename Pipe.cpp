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
