#include <SDL.h>
#include <iostream>

const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;

// Colors
const SDL_Color WHITE = {255, 255, 255, 255};
const SDL_Color GREY = {192, 192, 192, 255};

// Chessboard dimensions
const int BOARD_COLUMNS = 8;
const int BOARD_ROWS = 8;

// Prototypes
void renderSplashScreen(SDL_Renderer* renderer);
void renderChessboard(SDL_Renderer* renderer, int windowWidth, int windowHeight);
void renderInfoBar(SDL_Renderer* renderer, int windowWidth, int windowHeight);

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow(
        "Chess Game",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_RESIZABLE
    );

    if (!window) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Show splash screen for 5 seconds
    renderSplashScreen(renderer);
    SDL_Delay(5000);

    // Main loop
    bool isRunning = true;
    SDL_Event event;
    while (isRunning) {
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                isRunning = false;
            }
        }

        // Get window size for responsive layout
        int windowWidth, windowHeight;
        SDL_GetWindowSize(window, &windowWidth, &windowHeight);

        // Clear screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Render chessboard and info bar
        renderChessboard(renderer, windowWidth, windowHeight);
        renderInfoBar(renderer, windowWidth, windowHeight);

        // Present the screen
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

void renderSplashScreen(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 128, 255); // Blue background
    SDL_RenderClear(renderer);

    // Example splash screen: Draw a white rectangle
    SDL_Rect splashRect = { 100, 100, 400, 200 };
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &splashRect);

    // Present the screen
    SDL_RenderPresent(renderer);
}

void renderChessboard(SDL_Renderer* renderer, int windowWidth, int windowHeight) {
    int boardWidth = windowWidth * 0.8;
    int boardHeight = windowHeight;
    int squareSize = boardWidth / BOARD_COLUMNS;

    for (int row = 0; row < BOARD_ROWS; ++row) {
        for (int col = 0; col < BOARD_COLUMNS; ++col) {
            SDL_Rect square = { col * squareSize, row * squareSize, squareSize, squareSize };
            if ((row + col) % 2 == 0) {
                SDL_SetRenderDrawColor(renderer, WHITE.r, WHITE.g, WHITE.b, WHITE.a);
            } else {
                SDL_SetRenderDrawColor(renderer, GREY.r, GREY.g, GREY.b, GREY.a);
            }
            SDL_RenderFillRect(renderer, &square);
        }
    }
}

void renderInfoBar(SDL_Renderer* renderer, int windowWidth, int windowHeight) {
    int infoBarWidth = windowWidth * 0.2;
    SDL_Rect infoBar = { windowWidth - infoBarWidth, 0, infoBarWidth, windowHeight };

    SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255); // Dark grey background
    SDL_RenderFillRect(renderer, &infoBar);
}
