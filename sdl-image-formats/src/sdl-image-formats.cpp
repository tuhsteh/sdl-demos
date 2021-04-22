#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <cstdio>
#include <iostream>

SDL_Texture *LoadTexture(std::string fileName, SDL_Renderer *target) {
  SDL_Texture *texture = nullptr;
  SDL_Surface *surface = IMG_Load(fileName.c_str());
  if (NULL == surface) {
    std::cerr << "Image Load Error:  " << IMG_GetError() << std::endl;
  } else {
    texture = SDL_CreateTextureFromSurface(target, surface);
    if (NULL == texture) {
      std::cerr << "Texture Create Error:  " << IMG_GetError() << std::endl;
    }
  }

  SDL_FreeSurface(surface);

  return texture;
}

int main(int argv, char **args) {
  using namespace std;
  freopen("output.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
  std::cout << "Starting up..." << std::endl;

  SDL_Window *window = nullptr;
  SDL_Texture *currentImage = nullptr;
  SDL_Renderer *renderTarget = nullptr;

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "Video Init Error:  " << SDL_GetError() << std::endl;
  } else {
    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;

    if (!(IMG_Init(imgFlags) & imgFlags)) {
      std::cerr << "Image Init Error:  " << IMG_GetError() << std::endl;
    } else {
      window =
          SDL_CreateWindow("SDL CodingMadeEasy Series", SDL_WINDOWPOS_CENTERED,
                           SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
      if (NULL == window) {
        std::cerr << "Window Error:  " << SDL_GetError() << std::endl;
      } else {
        renderTarget = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        currentImage = LoadTexture("src\\image2.jpg", renderTarget);

        bool isRunning = true;
        SDL_Event ev;

        while (isRunning) {
          while (SDL_PollEvent(&ev) != 0) {
            if (SDL_QUIT == ev.type) {
              isRunning = false;
            }
          }

          SDL_RenderClear(renderTarget);
          SDL_RenderCopy(renderTarget, currentImage, NULL, NULL);
          SDL_RenderPresent(renderTarget);
        }
      }
    }
  }

  SDL_DestroyWindow(window);
  SDL_DestroyTexture(currentImage);
  SDL_DestroyRenderer(renderTarget);
  window = nullptr;
  currentImage = nullptr;
  renderTarget = nullptr;

  SDL_Quit();

  return 0;
}
