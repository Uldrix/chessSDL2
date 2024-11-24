#include "Game.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

Game::Game() : window(nullptr), renderer(nullptr), isRunning(true), playerSide(0), difficulty(0), splashTexture(nullptr) {}

Game::~Game() {
    cleanup();
}

void Game::initialize() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        isRunning = false;
        return;
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        std::cerr << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
        isRunning = false;
        return;
    }

    window = SDL_CreateWindow("Chess Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1080, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == nullptr) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        isRunning = false;
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        isRunning = false;
        return;
    }

    // Load splash image
    SDL_Surface* splashSurface = IMG_Load("assets/chess2d-splash.webp");
    if (splashSurface == nullptr) {
        std::cerr << "Unable to load splash image! SDL_image Error: " << IMG_GetError() << std::endl;
        isRunning = false;
        return;
    }

    splashTexture = SDL_CreateTextureFromSurface(renderer, splashSurface);
    if (splashTexture == nullptr) {
        std::cerr << "Unable to create texture from splash image! SDL Error: " << SDL_GetError() << std::endl;
        isRunning = false;
        return;
    }

    int splashWidth = splashSurface->w;
    int splashHeight = splashSurface->h;
    SDL_FreeSurface(splashSurface);

    // Show splash screen for 5 seconds
    SDL_Rect splashRect;
    splashRect.x = (1920 - splashWidth) / 2;
    splashRect.y = (1080 - splashHeight) / 2;
    splashRect.w = splashWidth;
    splashRect.h = splashHeight;

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, splashTexture, NULL, &splashRect);
    SDL_RenderPresent(renderer);


    // Initialize splash screen
    splashStartTime = SDL_GetTicks();
    showingSplash = true;

    // Initialize the board
    board.initialize(renderer);
}

void Game::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            isRunning = false;
        }
    }
}

void Game::update() {
    // Update game logic here
}

void Game::render() {
    if (showingSplash) return; // Don't render the game if still showing splash
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    int windowWidth, windowHeight;
    SDL_GetWindowSize(window, &windowWidth, &windowHeight);

    // Render chess board (80% of window width)
    int boardSize = static_cast<int>(windowWidth * 0.8);
    int boardX = 0; // Align to left side
    int boardY = (windowHeight - boardSize) / 2;
    board.render(renderer, boardX, boardY, boardSize);

    // Render info bar (20% of window width)
    SDL_Rect infoBar = {boardSize, 0, windowWidth - boardSize, windowHeight};
    SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);  // Dark gray color
    SDL_RenderFillRect(renderer, &infoBar);


    SDL_RenderPresent(renderer);
}

void Game::cleanup() {
    if (splashTexture) {
        SDL_DestroyTexture(splashTexture);
    }
    if (renderer) {
        SDL_DestroyRenderer(renderer);
    }
    if (window) {
        SDL_DestroyWindow(window);
    }
    IMG_Quit();
    SDL_Quit();
}

void Game::run() {
    initialize();

    while (isRunning) {
        handleEvents();
        update();
        
        if (showingSplash) {
            renderSplash();
            if (SDL_GetTicks() - splashStartTime >= SPLASH_DURATION) {
                showingSplash = false;
            }
        } else {
            render();
        }

        SDL_Delay(16); // Cap frame rate
    }

    cleanup();
}

void Game::renderSplash() {
    SDL_RenderClear(renderer);
    
    int windowWidth, windowHeight;
    SDL_GetWindowSize(window, &windowWidth, &windowHeight);

    SDL_Rect splashRect;
    SDL_QueryTexture(splashTexture, NULL, NULL, &splashRect.w, &splashRect.h);
    splashRect.x = (windowWidth - splashRect.w) / 2;
    splashRect.y = (windowHeight - splashRect.h) / 2;

    SDL_RenderCopy(renderer, splashTexture, NULL, &splashRect);
    SDL_RenderPresent(renderer);
}
