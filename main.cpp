#include <iostream>
#include <ostream>
#include <raylib.h>
#include <raymath.h>
#include "colors.h"
#include "Bird.h"
#include "Pipe.h"

#define SCREEN_WIDTH 450
#define SCREEN_HEIGHT 800
#define PIPE_COUNT 30

int main()
{
  Bird bird = {(Vector2){200, 375}, 50, 50, MY_DARK_BLUE};
  Pipe pipes[PIPE_COUNT];

  for (int i = 0; i < PIPE_COUNT; i++)
    {
      pipes[i] = Pipe();
      pipes[i].x = SCREEN_WIDTH + i * 200;
    }

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
      for (int i = 0; i < PIPE_COUNT; i++)
	{  
	  pipes[i].draw();
	  pipes[i].update();
	  pipes[i].hits(bird);
	}

      //draw game stats
      EndDrawing();
    }
  CloseWindow();
  return 0;
}

