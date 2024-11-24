#pragma once
#include <SDL.h>

class Board {
public:
    void initialize(SDL_Renderer* renderer);
    void render(SDL_Renderer* renderer, int x, int y, int size);

private:
    // Add board state and other necessary members here
};
