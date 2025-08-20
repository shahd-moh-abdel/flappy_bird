#include <iostream>
#include <raylib.h>
#include <raymath.h>
#include "colors.h"
#define SCREEN_WIDTH 450
#define SCREEN_HEIGHT 800

int main()
{
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "flappy bird");

  SetTargetFPS(60);

  while (!WindowShouldClose())
    {
      BeginDrawing();
      ClearBackground(MY_PINK);
      EndDrawing();
    }
  CloseWindow();
  return 0;
}
