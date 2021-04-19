#include <SDL2/SDL.h>

#include <cstdio>
#include <iostream>
#include <string>

int main(int argv, char **args) {
  using namespace std;
  freopen("output.txt", "w", stdout);
  freopen("error.txt", "w", stderr);

  SDL_Window *window = nullptr;

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cout << "Video Init Error:  " << SDL_GetError() << std::endl;
  } else {
    window =
        SDL_CreateWindow("SDL CodingMadeEasy Series", SDL_WINDOWPOS_CENTERED,
                         SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    if (NULL == window) {
      std::cout << "Video Init Error:  " << SDL_GetError() << std::endl;
    } else {
      std::string text = "";
      SDL_StartTextInput();

      bool isRunning = true;
      SDL_Event ev;

      while (isRunning) {
        while (SDL_PollEvent(&ev) != 0) {
          if (ev.type == SDL_QUIT) {
            isRunning = false;
          } else if (ev.type == SDL_TEXTINPUT || ev.type == SDL_KEYDOWN) {
            system("cls");
            if (ev.type == SDL_KEYDOWN && ev.key.keysym.sym == SDLK_BACKSPACE &&
                text.length() > 0) {
              text = text.substr(0, text.length() - 1);
            } else if (ev.type == SDL_TEXTINPUT) {
              text += ev.text.text;
            }

            std::cout << text << std::endl;
          }
        }
        SDL_UpdateWindowSurface(window);
      }
    }
  }

  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
