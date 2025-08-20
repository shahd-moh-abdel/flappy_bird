#include <iostream>
#include <ostream>
#include <raylib.h>
#include <raymath.h>
#include "colors.h"
#define SCREEN_WIDTH 450
#define SCREEN_HEIGHT 800

class Bird {
public:
  Vector2 pos;
  int width;
  int height;
  Color color;

  void draw()
  {
    DrawRectangle(pos.x, pos.y, width, height, color);
  }
  void update()
  {
    if (pos.y < SCREEN_HEIGHT - height)
      {
	  pos.y += 5.0f;
      }
  }
};

int main()
{
  Bird bird = {(Vector2){200, 375}, 50, 50, MY_DARK_BLUE};

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "flappy bird");

  SetTargetFPS(60);

  while (!WindowShouldClose())
    {
      BeginDrawing();
      ClearBackground(MY_PINK);
      bird.update();
      bird.draw();
      EndDrawing();
    }
  CloseWindow();
  return 0;
}
