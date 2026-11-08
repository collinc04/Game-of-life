#include <SDL2/SDL.h>
#include <string>
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
        SDL_SetRenderDrawColor(renderer, 40, 61, 26, 0);
      } else {
        SDL_SetRenderDrawColor(renderer, 102, 163, 64, 0);
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
  SDL_SetWindowTitle(
    window, "Conway's game of life"
  );

  Uint32 last_step = SDL_GetTicks();
  bool running = true;
  bool stepping = false;
  while(running) {
    while (SDL_PollEvent(&event)) {
      // handle quitting
      if (event.type == SDL_QUIT) {
        running = false;
      }

      // handle pausing
      if (event.type == SDL_KEYDOWN &&
          event.key.keysym.sym == SDLK_SPACE &&
          event.key.repeat == 0) {
        stepping = !stepping;
        last_step = SDL_GetTicks();
      }

      // handle changing cell states
      if (event.type == SDL_MOUSEBUTTONDOWN &&
          event.button.button == SDL_BUTTON_LEFT &&
          !stepping) {
        int normal_x = event.button.y / cell_size;
        int normal_y = event.button.x / cell_size;

        if (normal_x < width && normal_y < height) {
          toggle(normal_x, normal_y);
        }
      }
    }

    if (!running) {
      break;
    }

    Uint32 now = SDL_GetTicks();
    if(stepping && (now - last_step >= 1000)) {
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