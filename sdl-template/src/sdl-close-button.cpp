#include <SDL2/SDL.h>

#include <iostream>
#include <cstdio>

int main(int argv, char **args) {
  using namespace std;
  freopen("output.txt","w",stdout);
  freopen("error.txt","w",stderr);

  SDL_Window *window = nullptr;

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cout << "Video Init Error:  " << SDL_GetError() << std::endl;
  } else {
    window =
        SDL_CreateWindow("SDL CodingMadeEasy Series", SDL_WINDOWPOS_CENTERED,
                         SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    if(NULL == window) {
      std::cout << "Video Init Error:  " << SDL_GetError() << std::endl;
    } else {
      SDL_UpdateWindowSurface(window);
      SDL_Delay(5000);
    }
  }

  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
