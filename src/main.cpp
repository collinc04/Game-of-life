#include <SDL2/SDL.h>
#include <thread>
#include <chrono>
#include "game.cpp"
#include "game.h"

using namespace std;

int main () {
  // Initialize
  constexpr int cell_size = 20;
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

  while(true) {
    if(SDL_PollEvent(&event) && event.type == SDL_QUIT) {
      break;
    }

    step();
    this_thread::sleep_for(chrono::seconds(1));
  }

  // Cleanup
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}