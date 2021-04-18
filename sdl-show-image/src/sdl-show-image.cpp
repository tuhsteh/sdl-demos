#include <SDL2/SDL.h>

#include <iostream>
#include <cstdio>

int main(int argv, char **args) {
  using namespace std;

  freopen("output.txt","w", stdout);
  freopen("error.txt","w",stderr);

  std::cout << "Starting up..." << std::endl;

  SDL_Window *window = nullptr;
  SDL_Surface *windowSurface = nullptr;
  SDL_Surface *imageSurface = nullptr;

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cout << "Video Init Error:  " << SDL_GetError() << std::endl;
  } else {
    window =
        SDL_CreateWindow("SDL CodingMadeEasy Series", SDL_WINDOWPOS_CENTERED,
                         SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    if (NULL == window) {
      std::cout << "Window Error:  " << SDL_GetError() << std::endl;
      SDL_Delay(2000);
    } else {
      windowSurface = SDL_GetWindowSurface(window);
      imageSurface = SDL_LoadBMP("src\\test.bmp");

      if (NULL == imageSurface) {
        std::cout << "Image Surface Error:  " << SDL_GetError() << std::endl;
        SDL_Delay(3000);
      } else {
        SDL_BlitSurface(imageSurface, NULL, windowSurface, NULL);
        SDL_UpdateWindowSurface(window);
        SDL_Delay(5000);
      }
    }
  }

  SDL_FreeSurface(imageSurface);
  imageSurface = nullptr;
  SDL_DestroyWindow(window);
  window = nullptr;
  windowSurface = nullptr;
  SDL_Quit();

  return 0;
}
