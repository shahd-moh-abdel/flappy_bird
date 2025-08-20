#include <iostream>
#include <raylib.h>
#include <raymath.h>
#define SCREEN_WIDTH 400
#define SCREEN_HEIGHT 800
#define MY_PINK (Color) {255, 197, 232, 255}

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
