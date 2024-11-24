#include "Board.h"

void Board::initialize(SDL_Renderer* renderer) {
    // Initialize board state here
}

void Board::render(SDL_Renderer* renderer, int x, int y, int size) {
    int squareSize = size / 8;
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            SDL_Rect square = {x + col * squareSize, y + row * squareSize, squareSize, squareSize};
            if ((row + col) % 2 == 0) {
                SDL_SetRenderDrawColor(renderer, 240, 217, 181, 255);  // Warm beige
            } else {
                SDL_SetRenderDrawColor(renderer, 181, 136, 99, 255);   // Rich brown
            }
            SDL_RenderFillRect(renderer, &square);
        }
    }
}

