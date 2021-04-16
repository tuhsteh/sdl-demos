#include<SDL2/SDL.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<iostream>

int main(int argv, char **args) {
  time_t t;

  srand((unsigned)time(&t));
  SDL_Init(SDL_INIT_EVERYTHING);

  SDL_Window *window = SDL_CreateWindow("Hello SDL", SDL_WINDOWPOS_CENTERED,
                                        SDL_WINDOWPOS_CENTERED, 800, 600, 0);
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

  bool isRunning = true;
  SDL_Event event;

  while (isRunning) {
    int R = rand() % 255;
    int B = rand() % 255;
    int G = rand() % 255;

    while (SDL_PollEvent(&event)) {
      switch (event.type) {
        case SDL_QUIT:
          isRunning = false;
          break;

        case SDL_KEYDOWN:
          if (event.key.keysym.sym == SDLK_ESCAPE) {
            isRunning = false;
          }
      }
    }

    usleep(1000000 + 1000000 * (rand() % 5));

    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, R, B, G, 255);

    SDL_RenderPresent(renderer);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
