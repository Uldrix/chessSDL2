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

#include "Board.h"
#include <stdexcept>

void Board::initialize(SDL_Renderer* renderer) {
    // Load the chess pieces texture
    SDL_Surface* surface = IMG_Load("assets/chessPieces.png");
    if (!surface) {
        throw std::runtime_error("Failed to load chess pieces image: " + std::string(IMG_GetError()));
    }
    piecesTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (!piecesTexture) {
        throw std::runtime_error("Failed to create texture: " + std::string(SDL_GetError()));
    }

    initializePieceDimensions();
}

void Board::render(SDL_Renderer* renderer, int x, int y, int size) {
    int squareSize = size / 8;

    // Render the board first
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

    // Now render the pieces on top of the board
    int padding = squareSize / 10;  // 10% padding
    int maxPieceSize = squareSize - (2 * padding);

    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            ChessPiece piece;
            std::string color;

            if (row == 0 || row == 7) {
                color = (row == 0) ? "black" : "white";
                switch (col) {
                    case 0: case 7: piece = ChessPiece::ROOK; break;
                    case 1: case 6: piece = ChessPiece::KNIGHT; break;
                    case 2: case 5: piece = ChessPiece::BISHOP; break;
                    case 3: piece = ChessPiece::QUEEN; break;
                    case 4: piece = ChessPiece::KING; break;
                    default: continue;  // Skip rendering for invalid columns
                }
            } else if (row == 1 || row == 6) {
                piece = ChessPiece::PAWN;
                color = (row == 1) ? "black" : "white";
            } else {
                continue;  // Skip empty squares
            }

            SDL_Rect pieceSprite = getChessPieceSprite(piece, color);
            
            // Calculate aspect ratio
            float aspectRatio = static_cast<float>(pieceSprite.w) / pieceSprite.h;
            int pieceWidth, pieceHeight;
            
            if (aspectRatio > 1) {
                pieceWidth = maxPieceSize;
                pieceHeight = static_cast<int>(maxPieceSize / aspectRatio);
            } else {
                pieceHeight = maxPieceSize;
                pieceWidth = static_cast<int>(maxPieceSize * aspectRatio);
            }

            SDL_Rect destRect = {
                x + col * squareSize + (squareSize - pieceWidth) / 2,
                y + row * squareSize + (squareSize - pieceHeight) / 2,
                pieceWidth,
                pieceHeight
            };
            SDL_RenderCopy(renderer, piecesTexture, &pieceSprite, &destRect);
        }
    }
}



void Board::cleanup() {
    if (piecesTexture) {
        SDL_DestroyTexture(piecesTexture);
    }
}

SDL_Rect Board::getChessPieceSprite(ChessPiece piece, const std::string& color) {
    if (pieceDimensions.find(color) == pieceDimensions.end() ||
        pieceDimensions.at(color).find(piece) == pieceDimensions.at(color).end()) {
        throw std::invalid_argument("Invalid piece or color specified.");
    }
    return pieceDimensions.at(color).at(piece);
}

void Board::initializePieceDimensions() {
    pieceDimensions = {
        {"black", {
            {ChessPiece::KING, {0, 0, 124, 290}},
            {ChessPiece::QUEEN, {124, 0, 120, 290}},
            {ChessPiece::BISHOP, {244, 0, 120, 290}},
            {ChessPiece::ROOK, {360, 0, 120, 290}},
            {ChessPiece::KNIGHT, {480, 0, 146, 290}},
            {ChessPiece::PAWN, {624, 0, 86, 290}},
        }},
        {"white", {
            {ChessPiece::KING, {0, 290, 124, 290}},
            {ChessPiece::QUEEN, {124, 290, 120, 290}},
            {ChessPiece::BISHOP, {244, 290, 118, 290}},
            {ChessPiece::ROOK, {356, 290, 120, 290}},
            {ChessPiece::KNIGHT, {480, 290, 146, 290}},
            {ChessPiece::PAWN, {624, 290, 86, 290}},
        }},
    };
}
