#include <SDL2/SDL.h>
#include <thread>
#include <chrono>
#include "game.cpp"
#include "game.h"

using namespace std;

/**
 * an implementation of John Conway's game of life in C++
 * done as an excersize in programming and as a study of emergent behavior
 * This file defines the interface
 * 
 * written by Collin Cook
 */

void draw_board (SDL_Renderer *renderer) {
  // loop through all pixels
  for (int x = 0; x < width; x++){
    for (int y = 0; y < height; y++){
      if(board[x][y]){
        SDL_SetRenderDrawColor(renderer, 0, 200, 200, 200);
      } else {
        SDL_SetRenderDrawColor(renderer, 0, 100, 100, 100);
      }

      // Coordinates are mapped like that to normalize the system
      SDL_Rect cell = {
        y * cell_size,
        x * cell_size,
        cell_size,
        cell_size
      };
      SDL_RenderFillRect(renderer, &cell);
    }
  }
}

int main () {
  // Initialize
  SDL_Event event;
  SDL_Renderer *renderer;
  SDL_Window *window;
  SDL_Init(SDL_INIT_VIDEO);
  SDL_CreateWindowAndRenderer(width * cell_size, height * cell_size, 0, &window, &renderer);

  //test layout
  board[2][2] = true;
  board[3][2] = true;
  board[2][3] = true;
  board[3][3] = true;
  board[3][4] = true;

  Uint32 last_step = SDL_GetTicks();
  bool running = true;
  while(running) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        running = false;
      }
    }

    if (!running) {
      break;
    }

    Uint32 now = SDL_GetTicks();
    if(now - last_step >= 1000) {
      step();
      last_step = now;
    }

    // Draw
    draw_board(renderer);
    SDL_RenderPresent(renderer);
    SDL_Delay(16);
  }

  // Cleanup
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}