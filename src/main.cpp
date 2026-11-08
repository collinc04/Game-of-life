#include <SDL2/SDL.h>
#include <thread>
#include <chrono>
#include "game.cpp"
#include "game.h"

using namespace std;

void draw_board (SDL_Renderer *renderer) {
  // loop through all pixels
  for (int x = 0; x < width; x++){
    for (int y = 0; y < height; y++){
      if(board[x][y]){
        SDL_SetRenderDrawColor(renderer, 0, 200, 200, 200);
      } else {
        SDL_SetRenderDrawColor(renderer, 0, 100, 100, 100);
      }

      SDL_Rect cell = {
        x * cell_size,
        y * cell_size,
        cell_size,
        cell_size
      };
      SDL_RenderFillRect(renderer, &cell);
      SDL_RenderPresent(renderer);
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

  bool running = true;
  while(running) {
    if(SDL_PollEvent(&event) && event.type == SDL_QUIT) {
      running = false;
    }

    if (!running) {
      break;
    }

    draw_board(renderer);
    step();
    this_thread::sleep_for(chrono::seconds(1));
  }

  // Cleanup
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}