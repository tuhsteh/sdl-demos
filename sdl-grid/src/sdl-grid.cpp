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

struct coords {
  int x;
  int y;
};

int main(int argv, char **args) {
  srand(time(NULL));

  using namespace std;
  freopen("output.txt", "w", stdout);
  freopen("error.txt", "w", stderr);

  rect categories[3][4] = {{{rand() % 255, rand() % 255, rand() % 255, 0xFF},
                            {rand() % 255, rand() % 255, rand() % 255, 0xFF},
                            {rand() % 255, rand() % 255, rand() % 255, 0xFF},
                            {rand() % 255, rand() % 255, rand() % 255, 0xFF}},
                           {{rand() % 255, rand() % 255, rand() % 255, 0xFF},
                            {rand() % 255, rand() % 255, rand() % 255, 0xFF},
                            {rand() % 255, rand() % 255, rand() % 255, 0xFF},
                            {rand() % 255, rand() % 255, rand() % 255, 0xFF}},
                           {{rand() % 255, rand() % 255, rand() % 255, 0xFF},
                            {rand() % 255, rand() % 255, rand() % 255, 0xFF},
                            {rand() % 255, rand() % 255, rand() % 255, 0xFF},
                            {rand() % 255, rand() % 255, rand() % 255, 0xFF}}};

  const int W_LIMIT = sizeof categories[0] / sizeof categories[0][0];
  const int H_LIMIT = sizeof categories / sizeof categories[0];

  std::cout << "W_LIMIT:  " << W_LIMIT << std::endl;
  std::cout << "H_LIMIT:  " << H_LIMIT << std::endl;

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

      coords selected = {0, 0};
      std::cout << "Selected tile:  {" << selected.x << ", " << selected.y
                << "};" << std::endl;
      bool isRunning = true;
      SDL_Event ev;

      while (isRunning) {
        while (SDL_PollEvent(&ev) != 0) {
          if (ev.type == SDL_QUIT) {
            isRunning = false;
          } else if (ev.type == SDL_KEYDOWN) {
            if (ev.key.keysym.sym == SDLK_RIGHT) {
              selected.x = min(selected.x + 1, W_LIMIT - 1);
              std::cout << "Selected tile:  {" << selected.x << ", "
                        << selected.y << "};" << std::endl;
            } else if (ev.key.keysym.sym == SDLK_LEFT) {
              selected.x = max(selected.x - 1, 0);
              std::cout << "Selected tile:  {" << selected.x << ", "
                        << selected.y << "};" << std::endl;
            } else if (ev.key.keysym.sym == SDLK_DOWN) {
              selected.y = min(selected.y + 1, H_LIMIT - 1);
              std::cout << "Selected tile:  {" << selected.x << ", "
                        << selected.y << "};" << std::endl;
            } else if (ev.key.keysym.sym == SDLK_UP) {
              selected.y = max(selected.y - 1, 0);
              std::cout << "Selected tile:  {" << selected.x << ", "
                        << selected.y << "};" << std::endl;
            }
            std::cout << "Selected tile:  {" << selected.x << ", " << selected.y
                      << "};" << std::endl;
          }

          SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
          SDL_RenderClear(renderer);

          for (int i = 0; i < W_LIMIT; i++) {
            for (int j = 0; j < H_LIMIT; j++) {
              std::cout << "Rect:  {" << i << ", " << j << "}" << std::endl;
              SDL_Rect fillRect = {
                  g_width * i +
                      (margin * ((selected.x == i && selected.y == j) ? 0 : 1)),
                  g_height * j +
                      (margin * ((selected.x == i && selected.y == j) ? 0 : 1)),
                  g_width -
                      2 * (margin *
                           ((selected.x == i && selected.y == j) ? 0 : 1)),
                  g_height -
                      2 * (margin *
                           ((selected.x == i && selected.y == j) ? 0 : 1))};
              SDL_SetRenderDrawColor(renderer, categories[i][j].r,
                                     categories[i][j].b, categories[i][j].g,
                                     categories[i][j].a);
              SDL_RenderFillRect(renderer, &fillRect);
            }
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
