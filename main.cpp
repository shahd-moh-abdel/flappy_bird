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

typedef enum {
  IDLE,
  PLAYING,
  GAMEOVER
} GameMode;

typedef struct {
  int score = 0;
  GameMode mode = IDLE;
} GameState;

int main()
{
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "flappy bird");
  
  Bird bird = {(Vector2){200, 375}, 50, 50, MY_DARK_BLUE};
  bird.initSprites();
  Pipe pipes[PIPE_COUNT];
  GameState gameState;

  for (int i = 0; i < PIPE_COUNT; i++)
    {
      pipes[i] = Pipe();
      pipes[i].x = SCREEN_WIDTH + i * 200;
      pipes[i].loadTexture();
    }

  SetTargetFPS(60);

  while (!WindowShouldClose())
    {
      if (IsKeyPressed(KEY_SPACE))
	{
	  if (gameState.mode == IDLE)
	    {
	      gameState.mode = PLAYING;
	    }
	  else if (gameState.mode == PLAYING)
	    {
	      bird.up();
	    }
	  
	}
      if (IsKeyPressed(KEY_R))
	{
	  //restart game 
	  bird = {(Vector2){200, 375}, 50, 50, MY_DARK_BLUE};
	  bird.initSprites();
	  for (int i = 0; i < PIPE_COUNT; i++)
	    {
	      pipes[i] = Pipe();
	      pipes[i].x = SCREEN_WIDTH + i * 200;
	    }
	  gameState.score = 0;
	  gameState.mode = IDLE;
	}
      BeginDrawing();
      ClearBackground(MY_PINK);

      //only update when playing
      if (gameState.mode == PLAYING)
	{
	  bird.update();
	  for (int i = 0; i < PIPE_COUNT; i++)
	    {
	      pipes[i].update();
	      if(pipes[i].hits(bird))
		{
		  gameState.mode = GAMEOVER;
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
		  pipes[i].passed = true;
		}
	    }
	}
      //always draw bird and pipes
      bird.draw();
      for (int i = 0; i < PIPE_COUNT; i++)
	pipes[i].draw();
      
      //draw game stats
      if (gameState.mode == IDLE)
	{
	  DrawText("FLAPPY BIRD", SCREEN_WIDTH/2 - 150, SCREEN_HEIGHT/4, 50, MY_DARK_BLUE);
	  DrawText("Press SPACE to start", SCREEN_WIDTH/2 - 100, SCREEN_HEIGHT/4 + 50, 20, WHITE);
	}
      else if (gameState.mode == PLAYING)
	{
	  DrawText(TextFormat("SCORE: %i", gameState.score), 10, 10, 30, MY_DARK_BROWN);
	}
      else if(gameState.mode == GAMEOVER)
	{
	  DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, (Color){0, 0, 0, 180});
	  DrawText("GAME OVER", SCREEN_WIDTH/2 - 150, SCREEN_HEIGHT/2, 50, MAROON);
	  DrawText("Press R to restart", SCREEN_WIDTH/2 - 100, SCREEN_HEIGHT/2 + 50, 20, WHITE);
	  DrawText(TextFormat("SCORE: %i", gameState.score), SCREEN_WIDTH/2 - 50, SCREEN_HEIGHT/2 + 75, 18, (Color) {226, 242, 245, 255});

	}
      EndDrawing();
    }
  CloseWindow();
  return 0;
}

