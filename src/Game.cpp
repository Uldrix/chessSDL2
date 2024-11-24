/* //////////////////////////////////////////////////////////////////////////////////
// 
// Project :        Chess SDL2 
// Description :    2D chess game in SDL2
// Programmer :     Uldrix | https://github.com/Uldrix
// Licence :        GNU
// 
// 
// 
//     ⠀⠀ ⠀⠀⠀⠀⠀  ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣴⠞⠋⠁⣀⣠⣴⣶⣾⣿⣷⣦⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠆
//     ⠀ ⠀⠀⠀⠀  ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣴⠟⢻⣧⣤⣴⣿⠿⠋⠁⣴⡿⠿⢿⣿⣿⣿⣷⣶⣶⣶⣶⡶⠶⠚⠁⠀⠀⣠⣾⠏⠀
//⠀⠀⠀   ⠀⠀⠀  ⠀⠀⠀⠀⠀⠀⠀⣀⣠⣴⣾⣿⣥⣤⣤⣭⣍⣁⡀⠀⠀⠘⣿⣇⠀⠀⠀⠈⠉⠉⠉⠉⠀⠀⠀⠀⢀⣠⣴⣿⠟⠁⠀⠀
//⠀⠀⠀⠀⠀ ⠀   ⠀⠀⠀⢀⣤⡶⠟⠋⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠁⠀⠀⠘⢿⣷⣦⣄⣀⣀⣀⣀⣀⣤⣤⣶⣾⣿⡿⠛⠁⠀⠀⢀⡀
//⠀⠀   ⠀⠀ ⠀⠀⠀⣠⡾⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠙⠛⠛⠛⠛⠛⣩⣿⠿⠋⠁⠀⠀⣠⣶⠟⠋⠀
//⠀⠀   ⠀ ⠀⠀⢠⡾⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⢄⠀⠀⠀⠀⣼⣿⠁⠀⠀⠀⢠⣾⡿⠃⠀⠀⠀
//⠀   ⠀⠀⠀⣠⡟⡡⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢧⠀⠀⠀⠸⣿⣄⠀⢀⣴⣿⣿⠁⠀⠀⠀⠀
//⠀  ⠀⠀⢠⡟⡜⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⠀⠀⠀⠀⠀⢀⣤⠶⠒⠛⠛⠒⠲⢤⡀⠀⠘⣷⠀⠀⠀⠙⠻⠿⠿⢿⣿⠇⠀⠀⠀⠀⠀
//⠀  ⣠⡶⠿⢇⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠇⠀⢀⡴⢪⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠙⢄⠀⢹⡄⠀⠀⠀⠀⠀⢀⣿⡟⠀⠀⠀⠀⠀⠀
//⠀  ⠙⢷⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⠿⣦⣤⡞⣰⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⡄⠀⡇⠀⠀⠀⢀⣠⣾⠟⢠⠀⠀⠀⠀⠀⠀
//⠀  ⠀⠀⡟⣿⣆⢀⠀⠀⠀⠀⠀⣠⠾⠕⠉⢉⣉⠀⣿⡁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠑⠀⠃⠀⣠⣶⣿⠟⠋⢀⣾⠀⠀⠀⠀⠀⠀
//⠀⠀  ⠀⢰⣿⣿⣯⣧⠠⠮⠴⠞⣁⣠⣴⣾⣿⣿⣷⡌⣿⠋⠉⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣾⡟⠉⠀⠀⣠⣾⡏⠀⠀⠀⠀⠀⠀
//  ⠀⣠⠴⢾⣿⣿⣿⣿⠀⠳⣾⣿⣿⣿⣿⣿⣿⣿⣿⡇⠸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣿⣷⣤⣴⣾⣿⠟⠀⠀⠀⠀⠀⠀⠀
//  ⢰⠁⠀⠀⠙⣿⣿⣧⠈⡆⢻⢿⣿⣿⣿⣿⣿⠿⠟⣃⣀⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠂⣼⠀⢈⣩⣽⠿⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀
//  ⣞⠀⠀⠀⣠⣿⣿⡿⠀⢺⡀⢑⡈⠉⠉⠉⠀⠀⠀⠀⠀⠀⠈⠻⣦⡞⠀⠀⠀⠀⠀⢠⣮⣾⣿⠿⠛⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
//  ⢻⣦⣄⣴⡿⡿⠷⣿⠠⣀⡨⠥⣞⣳⡄⠀⢀⡀⠀⠀⠀⠀⠀⣀⣿⣇⠀⠀⠀⣀⣴⣿⠟⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
//  ⠀⠉⢻⠇⠀⠀⠀⠈⠣⠀⠀⠀⠀⢀⡽⣷⣄⡈⠉⠉⠀⠀⣊⣽⣿⣿⣿⣿⣿⡿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
//  ⠀⠀⣾⠀⠀⠀⠀⠀⠀⠀⠀⠀⡰⠉⡴⣫⣿⣿⣒⡢⢄⣠⡾⠋⠉⠉⠛⠋⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
//  ⠀⢸⠛⣷⣤⢀⡄⢀⠇⣠⠂⣸⣡⣚⣼⠋⠁⠀⠉⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
//  ⠀⠘⣾⡀⡏⠙⡗⠻⠟⢻⠚⢻⢹⠙⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
//  ⠀⠀⠈⠓⠧⠴⣇⣴⣄⢼⣤⠟⠚⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
// 
// In Tenebris we code :: Forged by Uldrix :: Be aware of the Matrix :: ~~~~~~~~~~~~
// 
// ////////////////////////////////////////////////////////////////////////////////// */

#include "Game.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

Game::Game() : window(nullptr), renderer(nullptr), isRunning(true), playerSide(0), difficulty(0), splashTexture(nullptr) {}

Game::~Game() {
    cleanup();
    if (font) {
        TTF_CloseFont(font);
    }
    TTF_Quit();

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

    window = SDL_CreateWindow("Chess Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
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

    if (TTF_Init() == -1) {
        std::cerr << "TTF could not initialize! TTF_Error: " << TTF_GetError() << std::endl;
        isRunning = false;
        return;
    }

    font = TTF_OpenFont("assets/sansserif.ttf", 24); // Adjust path and size as needed
    if (!font) {
        std::cerr << "Failed to load font! TTF_Error: " << TTF_GetError() << std::endl;
        isRunning = false;
        return;
    }


    int splashWidth = splashSurface->w;
    int splashHeight = splashSurface->h;
    SDL_FreeSurface(splashSurface);

    // Show splash screen for 5 seconds
    SDL_Rect splashRect;
    splashRect.x = (SCREEN_WIDTH - splashWidth) / 2;
    splashRect.y = (SCREEN_HEIGHT - splashHeight) / 2;
    splashRect.w = splashWidth;
    splashRect.h = splashHeight;

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, splashTexture, NULL, &splashRect);
    SDL_RenderPresent(renderer);


    // Initialize splash screen
    splashStartTime = SDL_GetTicks();
    showingSplash = true;

    playerSideTxt = "undefined"; // Initial state
    showQuestion = true; // Show question by default
    difficulty = 3; //insane

    if (playerSide == 0) {
        userColor = PieceColor::WHITE;
        computerColor = PieceColor::BLACK;
    } else {
        userColor = PieceColor::BLACK;
        computerColor = PieceColor::WHITE;
    }
    currentPlayer = PieceColor::WHITE; // White moves first in chess

    // Initialize the board
    board.initialize(renderer);
}

void Game::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            isRunning = false;
        }

        // Handle key presses for player side selection
        if (event.type == SDL_KEYDOWN && showQuestion) {
            switch (event.key.keysym.sym) {
                case SDLK_w:
                    playerSideTxt = "White"; // For display purposes
                    playerSide = 0;
                    userColor = PieceColor::WHITE;
                    computerColor = PieceColor::BLACK;
                    currentPlayer = PieceColor::WHITE; // White moves first
                    showQuestion = false;
                    break;
                case SDLK_b:
                    playerSideTxt = "Black"; // For display purposes
                    playerSide = 1;
                    userColor = PieceColor::BLACK;
                    computerColor = PieceColor::WHITE;
                    currentPlayer = PieceColor::WHITE; // White moves first
                    showQuestion = false;
                    break;
            }
        }

        // Handle drag-and-drop for the user's turn
        if (!showQuestion && currentPlayer == userColor) {
            if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
                // Start dragging if a piece of the user's color is clicked
                int squareSize = SCREEN_HEIGHT / 8;
                int clickedX = event.button.x / squareSize;
                int clickedY = event.button.y / squareSize;

                PiecePosition& pos = board.getPieceAt(clickedX, clickedY);
                if (pos.color == userColor) {
                    draggingPiece = true;
                    draggedPiece = pos.piece;
                    draggedPieceColor = pos.color;
                    dragStartX = clickedX;
                    dragStartY = clickedY;
                    mouseX = event.button.x;
                    mouseY = event.button.y;
                }
            }

            if (event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT) {
                // Finalize the drag-and-drop move
                if (draggingPiece) {
                    handlePlayerMove();
                    draggingPiece = false;
                }
            }

            if (event.type == SDL_MOUSEMOTION && draggingPiece) {
                // Update the mouse position for dragging
                mouseX = event.motion.x;
                mouseY = event.motion.y;
            }
        }
    }
}

void Game::handlePlayerMove() {
    int squareSize = SCREEN_HEIGHT / 8;
    int dropX = mouseX / squareSize;
    int dropY = mouseY / squareSize;

    if (board.isLegalMove(dragStartX, dragStartY, dropX, dropY, draggedPiece, userColor)) {
        // Apply the move if legal
        board.movePiece(draggedPiece, userColor, dragStartX, dragStartY, dropX, dropY, 2.0f);

        // Store the move in the history
        board.recordMove({dragStartX, dragStartY, dropX, dropY, draggedPiece, userColor});

        // Switch to computer's turn
        currentPlayer = computerColor;
    } else {
        // Reset piece to its initial position
        //std::cout << "Illegal move. Try again!" << std::endl;
    }
}





// Game.cpp

void Game::update() {
    Uint32 currentTime = SDL_GetTicks();
    float deltaTime = (currentTime - lastUpdateTime) / 1000.0f;
    lastUpdateTime = currentTime;

    // Update the board animations and game state
    board.update(deltaTime);

    // Only proceed if not showing the splash screen and the player's side has been chosen
    if (!showingSplash && !showQuestion) {
        // Check if any animations are still in progress
        if (!board.isAnimating()) {
            if (currentPlayer == computerColor) {
                //td::cout << "It's the computer's turn (" 
                //          << ((computerColor == PieceColor::WHITE) ? "White" : "Black") 
                //          << ")." << std::endl;

                // Computer's turn
                board.computeComputerMove(computerColor, difficulty);
                currentPlayer = userColor; // Switch to the user's turn
                //std::cout << "Switching to user's turn (" 
                //          << ((userColor == PieceColor::WHITE) ? "White" : "Black") 
                //          << ")." << std::endl;

            } else if (currentPlayer == userColor) {
                //std::cout << "It's the user's turn (" 
                //          << ((userColor == PieceColor::WHITE) ? "White" : "Black") 
                //          << ")." << std::endl;

                // User's turn - Placeholder for handling user input
                // We will work on this later
            }
        } else {
            //std::cout << "Waiting for animations to finish." << std::endl;
        }
    }
}





void Game::render() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    int windowWidth, windowHeight;
    SDL_GetWindowSize(window, &windowWidth, &windowHeight);

    // Calculate the board size based on the window height
    int boardSize = windowHeight;

    // Render the board on the left side
    board.render(renderer, 0, 0, windowHeight, 
             draggingPiece, draggedPiece, draggedPieceColor, 
             dragStartX, dragStartY, mouseX, mouseY);

    
    // Render info bar (dark gray area)
    SDL_Rect infoBar = {boardSize, 0, windowWidth - boardSize, windowHeight};
    SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);  // Dark gray for info bar
    SDL_RenderFillRect(renderer, &infoBar);

    // Draw dark blue rectangle for title background
    SDL_Rect titleBackground = {boardSize, 0, windowWidth - boardSize, 50}; // Adjust height as needed
    SDL_SetRenderDrawColor(renderer, 0, 0, 139, 255); // Dark blue color
    SDL_RenderFillRect(renderer, &titleBackground);

    // Render the title text
    renderText("Chess 2D SDL2", boardSize + 10, 10); // Adjust position as needed

    // Draw dark blue rectangle for title background
    SDL_Rect titleBackground2 = {boardSize, 0, windowWidth - boardSize, 50}; // Adjust height as needed
    SDL_SetRenderDrawColor(renderer, 0, 0, 139, 255); // Dark blue color
    SDL_RenderFillRect(renderer, &titleBackground2);

    // Render the title text
    renderText("Chess 2D SDL2", boardSize + 10, 10); // Adjust position as needed

    // Draw green rectangle for player info
    SDL_Rect playerInfoBackground = {boardSize, 50, windowWidth - boardSize, 50}; // Adjust height as needed
    SDL_SetRenderDrawColor(renderer, 0, 128, 0, 255); // Green color
    SDL_RenderFillRect(renderer, &playerInfoBackground);

    // Render player info text
    renderText("You play: " + playerSideTxt, boardSize + 10, 60, windowWidth - boardSize - 20); // Position below title

    // If showing question
    if (showQuestion) {
        SDL_Rect questionBackground = {boardSize, 100, windowWidth - boardSize, 150}; // Adjust height as needed
        SDL_SetRenderDrawColor(renderer, 0, 100, 0, 255); // Darker green color for question box
        SDL_RenderFillRect(renderer, &questionBackground);

        renderText("What side do you want to play? Press W for white or B for black.", boardSize + 10, 110, windowWidth - boardSize - 20);
    }


    SDL_RenderPresent(renderer);
}

void Game::renderText(const std::string& message, int x, int y) {
    SDL_Color textColor = {255, 255, 255}; // White color
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, message.c_str(), textColor);
    if (!textSurface) {
        std::cerr << "Unable to render text surface! TTF_Error: " << TTF_GetError() << std::endl;
        return;
    }

    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    if (!textTexture) {
        std::cerr << "Unable to create texture from rendered text! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_FreeSurface(textSurface);
        return;
    }

    // Get width and height of the texture
    int width = textSurface->w;
    int height = textSurface->h;

    // Set up destination rectangle for rendering
    SDL_Rect renderQuad = {x, y, width, height};

    // Draw the texture
    SDL_RenderCopy(renderer, textTexture, NULL, &renderQuad);

    // Clean up
    SDL_DestroyTexture(textTexture);
    SDL_FreeSurface(textSurface);
}

void Game::renderText(const std::string& message, int x, int y, int boxWidth) {
    SDL_Color textColor = {255, 255, 255}; // White color
    std::string word;
    std::istringstream stream(message);
    std::vector<std::string> lines;
    std::string currentLine;

    // Break the message into words and wrap them
    while (stream >> word) {
        // Create a test surface for the current line plus the new word
        std::string testLine = currentLine.empty() ? word : currentLine + " " + word;
        SDL_Surface* testSurface = TTF_RenderText_Solid(font, testLine.c_str(), textColor);
        
        if (testSurface) {
            // Check if the width exceeds boxWidth
            if (testSurface->w > boxWidth) {
                // If it does, push the current line to lines and start a new line
                lines.push_back(currentLine);
                currentLine = word; // Start new line with the new word
            } else {
                currentLine = testLine; // Add word to the current line
            }
            SDL_FreeSurface(testSurface);
        }
    }
    
    // Add any remaining text in the current line
    if (!currentLine.empty()) {
        lines.push_back(currentLine);
    }

    // Render each line
    for (size_t i = 0; i < lines.size(); ++i) {
        SDL_Surface* textSurface = TTF_RenderText_Solid(font, lines[i].c_str(), textColor);
        if (!textSurface) {
            std::cerr << "Unable to render text surface! TTF_Error: " << TTF_GetError() << std::endl;
            continue;
        }

        SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        if (!textTexture) {
            std::cerr << "Unable to create texture from rendered text! SDL_Error: " << SDL_GetError() << std::endl;
            SDL_FreeSurface(textSurface);
            continue;
        }

        // Get width and height of the texture
        int width = textSurface->w;
        int height = textSurface->h;

        // Set up destination rectangle for rendering
        SDL_Rect renderQuad = {x, y + static_cast<int>(i * height), width, height};

        // Draw the texture
        SDL_RenderCopy(renderer, textTexture, NULL, &renderQuad);

        // Clean up
        SDL_DestroyTexture(textTexture);
        SDL_FreeSurface(textSurface);
    }
}



void Game::cleanup() {
    board.cleanup();
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
     lastUpdateTime = SDL_GetTicks();

    //board.movePiece(ChessPiece::PAWN, "white", 4, 6, 4, 4, 2.0f); // Move white pawn from e2 to e4 with speed 2


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
