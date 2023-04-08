#include <SDL.h>
#include <SDL_image.h>
#include <cstdio>
#include <cmath>
#include <iostream>

int main(int argc, char *argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Couldn't initialize SDL : %s\n", SDL_GetError());
        exit(1);
    }

    SDL_Window *window = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 400, 0);
    if (!window) {
        printf("Couldn't open SDL Window : %s\n", SDL_GetError());
        exit(1);
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer) {
        printf("Couldn't initialize SDL Renderer : %s\n", SDL_GetError());
        exit(1);
    }

    SDL_Rect rect;
    rect.x = 10;
    rect.y = 10;
    rect.w = 50;
    rect.h = 50;

    bool running = true;
    SDL_Event e;
    while (running) {
        // Input
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                running = false;
            }
        }

        // Update
        rect.x = (int) (sin((double) SDL_GetTicks() / 500) * 250) + 275;
        rect.y = (int) (sin((double) SDL_GetTicks() / 1000) * 150) + 175;

        // Draw
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderFillRect(renderer, &rect);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}