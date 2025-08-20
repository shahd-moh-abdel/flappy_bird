#include "Bird.h"
#include "raylib.h"
#include "colors.h"

void Bird::draw()
{
  DrawRectangle(pos.x, pos.y, width, height, color);
}

void Bird::update()
{
  if (pos.y < 800 - height)
    pos.y += 5.0f;
}
