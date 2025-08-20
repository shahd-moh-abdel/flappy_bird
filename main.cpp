#include <iostream>
#include <ostream>
#include <raylib.h>
#include <raymath.h>
#include "colors.h"
#include "Bird.h"

#define SCREEN_WIDTH 450
#define SCREEN_HEIGHT 800

int main()
{
  Bird bird = {(Vector2){200, 375}, 50, 50, MY_DARK_BLUE};

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "flappy bird");

  SetTargetFPS(60);

  while (!WindowShouldClose())
    {
      if(IsKeyPressed(KEY_SPACE))
	{
	  bird.up();
	}
      BeginDrawing();
      ClearBackground(MY_PINK);
      bird.update();
      bird.draw();
      EndDrawing();
    }
  CloseWindow();
  return 0;
}
