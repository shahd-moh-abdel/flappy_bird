#include "Bird.h"
#include "raylib.h"
#include "colors.h"
#include <iostream>

void Bird::draw()
{
  DrawRectangle(pos.x, pos.y, width, height, color);
}

void Bird::update()
{  
  velocity += gravity;
  pos.y += velocity;
  
  if (pos.y > 800 - height)
    {
      velocity = 0;
      pos.y = 800 - height;
    }
  if (pos.y < 0)
    {
      velocity = 0;
      pos.y = 0;
    }
}

void Bird::up()
{
  velocity += -5;
}

