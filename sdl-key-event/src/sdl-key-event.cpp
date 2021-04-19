#include <SDL2/SDL.h>

#include <cstdio>
#include <iostream>

int main(int argv, char **args) {
  using namespace std;
  freopen("output.txt", "w", stdout);
  freopen("error.txt", "w", stderr);

  SDL_Window *window = nullptr;
  SDL_Surface *windowSurface = nullptr;
  SDL_Surface *image1 = nullptr;
  SDL_Surface *image2 = nullptr;
  SDL_Surface *image3 = nullptr;
  SDL_Surface *current = nullptr;

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cout << "Video Init Error:  " << SDL_GetError() << std::endl;
  } else {
    window =
        SDL_CreateWindow("SDL CodingMadeEasy Series", SDL_WINDOWPOS_CENTERED,
                         SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    if (NULL == window) {
      std::cout << "Video Init Error:  " << SDL_GetError() << std::endl;
    } else {
      windowSurface = SDL_GetWindowSurface(window);

      image1 = SDL_LoadBMP("src\\image1.bmp");
      image2 = SDL_LoadBMP("src\\image2.bmp");
      image3 = SDL_LoadBMP("src\\image3.bmp");
      current = image1;

      bool isRunning = true;
      SDL_Event ev;

      while (isRunning) {
        while (SDL_PollEvent(&ev) != 0) {
          if (ev.type == SDL_QUIT) {
            isRunning = false;
          } else if (ev.type == SDL_KEYDOWN) {
            switch (ev.key.keysym.sym) {
              case SDLK_1:
                current = image1;
                break;
              case SDLK_2:
                current = image2;
                break;
              case SDLK_3:
                current = image3;
                break;
            }
          }

          SDL_BlitSurface(current, NULL, windowSurface, NULL);
          SDL_UpdateWindowSurface(window);
        }
      }
    }
  }

  SDL_FreeSurface(image1);
  SDL_FreeSurface(image2);
  SDL_FreeSurface(image3);
  image1 = image2 = image3 = current = nullptr;
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
