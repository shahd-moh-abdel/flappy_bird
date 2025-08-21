#include "Bird.h"
#include "raylib.h"
#include "colors.h"
#include <iostream>

void Bird::initSprites()
{
  frames[0] = LoadTexture("./assets/bird/frame-1.png");
  frames[1] = LoadTexture("./assets/bird/frame-2.png");
  frames[2] = LoadTexture("./assets/bird/frame-3.png");
  frames[3] = LoadTexture("./assets/bird/frame-4.png");
}

void Bird::draw()
{
  DrawRectangleLines(pos.x, pos.y, width, height, color);
  DrawTexturePro(frames[currentFrame],
		 {0, 0, (float)frames[currentFrame].width, (float)frames[currentFrame].height},
		 {pos.x, pos.y, (float)width, (float)height},
		 {0, 0},
		 0.0f,
		 WHITE); 
}

void Bird::update()
{
  if (velocity < 0)
    velocity += gravity;
  else 
    velocity += gravity * 1.5;
  
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

  //bird animation
  frameTimer += GetFrameTime();
  if (frameTimer >= 0.1f)
    {
      frameTimer = 0;
      currentFrame++;
      if (currentFrame > 3) currentFrame = 0;
    }
  
}

void Bird::up()
{
  velocity = -5;
}
