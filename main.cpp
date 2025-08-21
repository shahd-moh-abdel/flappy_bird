#include <iostream>
#include <ostream>
#include <raylib.h>
#include <raymath.h>
#include "colors.h"
#include "Bird.h"
#include "Pipe.h"

#define SCREEN_WIDTH 450
#define SCREEN_HEIGHT 800
#define PIPE_COUNT 3

typedef struct {
  int score = 0;
  bool gameover = false;
} GameState;

int main()
{
  Bird bird = {(Vector2){200, 375}, 50, 50, MY_DARK_BLUE};
  Pipe pipes[PIPE_COUNT];
  GameState gameState;

  for (int i = 0; i < PIPE_COUNT; i++)
    {
      pipes[i] = Pipe();
      pipes[i].x = SCREEN_WIDTH + i * 200;
    }


  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "flappy bird");

  SetTargetFPS(60);

  while (!WindowShouldClose())
    {
      if (IsKeyPressed(KEY_SPACE))
	{
	  bird.up();
	}
      if (IsKeyPressed(KEY_R))
	{
	  //restart game 
	  bird = {(Vector2){200, 375}, 50, 50, MY_DARK_BLUE};
	  for (int i = 0; i < PIPE_COUNT; i++)
	    {
	      pipes[i] = Pipe();
	      pipes[i].x = SCREEN_WIDTH + i * 200;
	    }
	  gameState.score = 0;
	  gameState.gameover = false;
	}
      BeginDrawing();
      ClearBackground(MY_PINK);
      
      if (!gameState.gameover) bird.update();//only update pos !gameover
      bird.draw();
      for (int i = 0; i < PIPE_COUNT; i++)
	{  
	  pipes[i].draw();
	  if (!gameState.gameover ) pipes[i].update();
	  if(pipes[i].hits(bird) && !gameState.gameover)
	    {
	      gameState.gameover = true;
	    } 

	  //check if pipe offscreen
	  if(pipes[i].x + pipes[i].width < 0)
	    {
	      pipes[i] = Pipe();
	      pipes[i].x = SCREEN_WIDTH + 200;
	    }

	  //update score
	  if(!pipes[i].passed && pipes[i].x + pipes[i].width < bird.pos.x)
	    {
	      gameState.score++;
	      std::cout << gameState.score << std::endl;
	      pipes[i].passed = true;
	    }
	}

      //draw game stats
      DrawText(TextFormat("SCORE: %i", gameState.score), 10, 10, 30, MY_DARK_BROWN);
      if(gameState.gameover)
	{
	  DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, (Color){0, 0, 0, 180});
	  DrawText("GAME OVER", SCREEN_WIDTH/2 - 150, SCREEN_HEIGHT/2, 50, MAROON);
	  DrawText("Press R to restart", SCREEN_WIDTH/2 - 100, SCREEN_HEIGHT/2 + 50, 20, WHITE);
	}
      EndDrawing();
    }
  CloseWindow();
  return 0;
}

