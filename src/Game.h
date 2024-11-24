#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Board.h"

class Game {
public:
    Game();
    ~Game();
    void run();

private:
    void initialize();
    void handleEvents();
    void update();
    void render();
    void cleanup();

    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* splashTexture;
    Board board;
    bool isRunning;
    int playerSide; // 0 for white, 1 for black
    int difficulty; // 0 for easy, 1 for medium, 2 for hard, 3 for insane

    Uint32 splashStartTime;
    bool showingSplash;
    static const int SPLASH_DURATION = 5000; // 5 seconds in milliseconds
    void renderSplash();
};
