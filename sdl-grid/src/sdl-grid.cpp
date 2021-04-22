#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <time.h>

#include <cstdio>
#include <iostream>
#include <random>

const int cells_wide = 4;
const int cells_high = 4;

const int margin = 10;
const int w_width = 640;
const int w_height = 480;
const int g_width = w_width / cells_wide;
const int g_height = w_height / cells_high;

struct rect {
  int r;
  int b;
  int g;
  int a;  // alpha
};

int main(int argv, char **args) {
  srand(time(NULL));

  using namespace std;
  freopen("output.txt", "w", stdout);
  freopen("error.txt", "w", stderr);

  struct rect rects[3] = {{rand() % 255, rand() % 255, rand() % 255, 0xFF},
                          {rand() % 255, rand() % 255, rand() % 255, 0xFF},
                          {rand() % 255, rand() % 255, rand() % 255, 0xFF}};

  SDL_Window *window = nullptr;
  SDL_Renderer *renderer = nullptr;

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "Video Init Error:  " << SDL_GetError() << std::endl;
  } else {
    window = SDL_CreateWindow("SDL CodingMadeEasy Series",
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              w_width, w_height, SDL_WINDOW_SHOWN);
    if (NULL == window) {
      std::cerr << "Video Init Error:  " << SDL_GetError() << std::endl;
    } else {
      renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

      int selected = rand() % 2;
      bool isRunning = true;
      SDL_Event ev;

      while (isRunning) {
        while (SDL_PollEvent(&ev) != 0) {
          if (ev.type == SDL_QUIT) {
            isRunning = false;
          }

          SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
          SDL_RenderClear(renderer);

          for (int i = 0; i < (sizeof rects / sizeof rects[0]); i++) {
            SDL_Rect fillRect = {
              g_width * i + (margin*((selected == i) ? 0 : 1)),
              (margin*((selected == i) ? 0 : 1)),
              g_width - 2 * (margin*((selected == i) ? 0 : 1)),
              g_height - 2 * (margin*((selected == i) ? 0 : 1))
            };
            SDL_SetRenderDrawColor(renderer, rects[i].r, rects[i].b, rects[i].g,
                                   rects[i].a);
            SDL_RenderFillRect(renderer, &fillRect);
          }

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
