#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <cstdio>
#include <iostream>

int main(int argv, char **args) {
  using namespace std;
  freopen("output.txt", "w", stdout);
  freopen("error.txt", "w", stderr);

  SDL_Window *window = nullptr;
  SDL_Renderer *renderer = nullptr;

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "Video Init Error:  " << SDL_GetError() << std::endl;
  } else {
    window =
        SDL_CreateWindow("SDL CodingMadeEasy Series", SDL_WINDOWPOS_CENTERED,
                         SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    if (NULL == window) {
      std::cerr << "Video Init Error:  " << SDL_GetError() << std::endl;
    } else {
      renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

      bool isRunning = true;
      SDL_Event ev;

      while (isRunning) {
        while (SDL_PollEvent(&ev) != 0) {
          if (ev.type == SDL_QUIT) {
            isRunning = false;
          }

          SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
          SDL_RenderClear(renderer);

          SDL_Rect fillRect1 = {160, 120, 320, 240};
          SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);
          SDL_RenderFillRect(renderer, &fillRect1);

          SDL_Rect fillRect2 = {0,0, 320, 240};
          SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0xFF, 0xFF);
          SDL_RenderFillRect(renderer, &fillRect2);

          SDL_RenderPresent(renderer);
        }
      }
    }
  }

  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  window = nullptr;
  renderer = nullptr;
  SDL_Quit();

  return 0;
}
