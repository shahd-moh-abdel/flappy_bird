#include "Pipe.h"
#include <iostream>
#include <ostream>
#include "colors.h"
#include "raylib.h"

static int lastGapY = 300;
int gapSize = 200;

Texture2D Pipe::pipeTexture = {0};

void Pipe::loadTexture()
{
  pipeTexture = LoadTexture("./assets/pipe/pipe.png");
}

void Pipe::unloadTexture()
{
  UnloadTexture(pipeTexture);
}

Pipe::Pipe() {
  int delta = GetRandomValue(-100, 100);
  lastGapY += delta;

  if (lastGapY < 100) lastGapY = 100;
  if (lastGapY > 700 - gapSize) lastGapY = 700 - gapSize;
  
  top = lastGapY - gapSize/2;
  bottom = 800 - (lastGapY + gapSize/2) ;
  
  x = 450;
  width = 60;
  speed = 5;
  passed = false;
}

void Pipe::draw()
{
  if (pipeTexture.id > 0)
    {
      Rectangle sourceRec = {0, (float)(pipeTexture.height - top), (float)pipeTexture.width, (float)top};
      Rectangle destRec = {(float)x, 0, (float)width, (float)top};
      Vector2 origin = {0, 0};
      DrawTexturePro(pipeTexture, sourceRec, destRec, origin, 0.0f, WHITE);

      Rectangle bottomSourceRec = {0, 0, (float)pipeTexture.width, (float)bottom};
      Rectangle bottomDestRec = {(float)x, (float)(800 - bottom), (float)width, (float)bottom};
      bottomSourceRec.height = (float)bottom;
      DrawTexturePro(pipeTexture, bottomSourceRec, bottomDestRec, origin, 0.0f, WHITE);
    }
  else
    {
      DrawRectangle(x, 0, width, top, MY_SOFT_VIOLET);
      DrawRectangle(x, 800 - bottom, width, bottom, MY_SOFT_VIOLET);
    }
}

void Pipe::update()
{
  x -= speed;
}

bool Pipe::hits(Bird bird)
{
  Rectangle birdRec =
    {bird.pos.x + 10, bird.pos.y + 10, (float)bird.width - 15, (float)bird.height -17};
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
