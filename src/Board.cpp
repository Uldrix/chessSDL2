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

    // Initialize the board with starting positions
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            board[i][j] = {ChessPiece::EMPTY, ""};
        }
    }

    // Set up initial piece positions
    std::string colors[2] = {"white", "black"};
    
    for (int c = 0; c < 2; ++c) {
        int row = (c == 0) ? 7 : 0;
        board[row][0] = board[row][7] = {ChessPiece::ROOK, colors[c]};
        board[row][1] = board[row][6] = {ChessPiece::KNIGHT, colors[c]};
        board[row][2] = board[row][5] = {ChessPiece::BISHOP, colors[c]};
        board[row][3] = {ChessPiece::QUEEN, colors[c]};
        board[row][4] = {ChessPiece::KING, colors[c]};
        
        row = (c == 0) ? 6 : 1;
        for (int col = 0; col < 8; ++col) {
            board[row][col] = {ChessPiece::PAWN, colors[c]};
        }
    }
}

void Board::render(SDL_Renderer* renderer, int x, int y, int size) {
    int squareSize = size / 8;

    // Render the board
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            SDL_Rect square = {x + col * squareSize, y + row * squareSize, squareSize, squareSize};
            if ((row + col) % 2 == 0) {
                SDL_SetRenderDrawColor(renderer, 240, 217, 181, 255); // Warm beige
            } else {
                SDL_SetRenderDrawColor(renderer, 181, 136, 99, 255); // Rich brown
            }
            SDL_RenderFillRect(renderer, &square);
        }
    }

    // Render the pieces
    int padding = squareSize / 10;
    int maxPieceSize = squareSize - (2 * padding);

    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            if (board[row][col].piece != ChessPiece::EMPTY) {
                renderPiece(renderer,
                            board[row][col].piece,
                            board[row][col].color,
                            x + col * squareSize,
                            y + row * squareSize,
                            maxPieceSize);
            }
        }
    }

    // Render animated pieces
    for (const auto& animatedPiece : animatedPieces) {
        renderPiece(renderer,
                    animatedPiece.piece,
                    animatedPiece.color,
                    x + animatedPiece.currentX * squareSize,
                    y + animatedPiece.currentY * squareSize,
                    maxPieceSize);
    }
}

void Board::renderPiece(SDL_Renderer* renderer,
                        ChessPiece piece,
                        const std::string& color,
                        int x,
                        int y,
                        int maxPieceSize) {
    
    SDL_Rect pieceSprite = getChessPieceSprite(piece, color);
    
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
        x + (maxPieceSize - pieceWidth) / 2,
        y + (maxPieceSize - pieceHeight) / 2,
        pieceWidth,
        pieceHeight 
    };
    
    SDL_RenderCopy(renderer, piecesTexture, &pieceSprite, &destRect);
}

void Board::movePiece(ChessPiece piece,
                      std::string color,
                      int fromX,
                      int fromY,
                      int toX,
                      int toY,
                      float speed) {

   // Remove the piece from its current position
   board[fromY][fromX] = {ChessPiece::EMPTY, ""};

   // Add the piece to the animated pieces list
   animatedPieces.push_back({
       piece,
       color,
       static_cast<float>(fromX),
       static_cast<float>(fromY),
       static_cast<float>(toX),
       static_cast<float>(toY),
       static_cast<float>(fromX),
       static_cast<float>(fromY),
       speed,
       true
   });
}

void Board::update(float deltaTime) {
   for (auto& animatedPiece : animatedPieces) {
       if (animatedPiece.isAnimating) {
           float dx = animatedPiece.endX - animatedPiece.currentX;
           float dy = animatedPiece.endY - animatedPiece.currentY;
           float distance = std::sqrt(dx * dx + dy * dy);

           if (distance > 0.01f) {
               float moveDistance = animatedPiece.speed * deltaTime;
               float ratio = moveDistance / distance;

               animatedPiece.currentX += dx * ratio;
               animatedPiece.currentY += dy * ratio;
           } else {
               // Animation finished
               animatedPiece.currentX = animatedPiece.endX;
               animatedPiece.currentY = animatedPiece.endY;
               animatedPiece.isAnimating = false;

               // Update the board with the new position
               board[static_cast<int>(animatedPiece.endY)][static_cast<int>(animatedPiece.endX)] =
                   {animatedPiece.piece, animatedPiece.color};
           }
       }
   }

   // Remove finished animations
   animatedPieces.erase(
       std::remove_if(animatedPieces.begin(), animatedPieces.end(),
                      [](const AnimatedPiece& p) { return !p.isAnimating; }),
       animatedPieces.end());
}

void Board::cleanup() {
   if (piecesTexture) {
       SDL_DestroyTexture(piecesTexture);
   }
}

SDL_Rect Board::getChessPieceSprite(ChessPiece piece,const std::string& color) {
   if (pieceDimensions.find(color) == pieceDimensions.end() ||
       pieceDimensions.at(color).find(piece) == pieceDimensions.at(color).end()) {
       throw std::invalid_argument("Invalid piece or color specified.");
   }
   return pieceDimensions.at(color).at(piece);
}

void Board::initializePieceDimensions() {
   pieceDimensions = {
       {"black", {{ChessPiece::KING,{0 ,0 ,124 ,290}},
                  {ChessPiece::QUEEN,{124 ,0 ,120 ,290}},
                  {ChessPiece::BISHOP,{244 ,0 ,120 ,290}},
                  {ChessPiece::ROOK,{360 ,0 ,120 ,290}},
                  {ChessPiece::KNIGHT,{480 ,0 ,146 ,290}},
                  {ChessPiece::PAWN,{624 ,0 ,86 ,290}}}},
       
       {"white", {{ChessPiece::KING,{0 ,290 ,124 ,290}},
                   {ChessPiece::QUEEN,{124 ,290 ,120 ,290}},
                   {ChessPiece::BISHOP,{244 ,290 ,118 ,290}},
                   {ChessPiece::ROOK,{356 ,290 ,120 ,290}},
                   {ChessPiece::KNIGHT,{480 ,290 ,146 ,290}},
                   {ChessPiece::PAWN,{624 ,290 ,86 ,290}}}}
   };
}
