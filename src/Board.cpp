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

    // Seed the random number generator
    srand(static_cast<unsigned int>(time(nullptr)));
    
    initializePieceDimensions();

    // Initialize the board with starting positions
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            board[i][j] = {ChessPiece::EMPTY, PieceColor::NONE};
        }
    }

    // Set up initial piece positions
    PieceColor colors[2] = {PieceColor::WHITE, PieceColor::BLACK};

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
                        PieceColor color,
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

void Board::movePiece(ChessPiece piece, PieceColor color, int fromX, int fromY, int toX, int toY, float speed) {
    board[toY][toX] = board[fromY][fromX];
    board[fromY][fromX] = {ChessPiece::EMPTY, PieceColor::NONE};

    // Add animation
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

                // Ensure ratio does not exceed 1 to prevent overshooting
                if (ratio > 1.0f) ratio = 1.0f;

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

                //std::cout << "Animation completed for " << animatedPiece.color << " " << static_cast<int>(animatedPiece.piece) << std::endl;
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

SDL_Rect Board::getChessPieceSprite(ChessPiece piece, PieceColor color) {
    std::string colorStr = (color == PieceColor::WHITE) ? "white" : "black";
    if (pieceDimensions.find(colorStr) == pieceDimensions.end() ||
        pieceDimensions.at(colorStr).find(piece) == pieceDimensions.at(colorStr).end()) {
        throw std::invalid_argument("Invalid piece or color specified.");
    }
    return pieceDimensions.at(colorStr).at(piece);
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

void Board::computeComputerMove(PieceColor color, int difficulty) {
    // Generate all legal moves
    std::vector<Move> legalMoves = generateAllLegalMoves(color);

    if (legalMoves.empty()) {
        //std::cerr << "No legal moves available for " << color << ". Game over." << std::endl;
        return;
    }

    Move bestMove = (difficulty == 0)
                    ? legalMoves[rand() % legalMoves.size()]
                    : findBestMove(color, difficulty + 1); // Depth increases with difficulty

    std::cout << "Computer selected move from (" << bestMove.fromX << ", " << bestMove.fromY 
              << ") to (" << bestMove.toX << ", " << bestMove.toY << ")" << std::endl;

    // Apply the move
    movePiece(bestMove.piece, bestMove.color, bestMove.fromX, bestMove.fromY, bestMove.toX, bestMove.toY, 2.0f);
}



std::vector<Move> Board::generateAllLegalMoves(PieceColor color) {
    std::vector<Move> moves;
    bool debug = false; // Turn on/off debug logging

    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            PiecePosition& pos = board[y][x];
            if (pos.color == color) {
                std::vector<Move> pieceMoves = generatePieceMoves(x, y, pos.piece, pos.color);
                moves.insert(moves.end(), pieceMoves.begin(), pieceMoves.end());
                if (debug) {
                    std::cout << "Generated " << pieceMoves.size() << " moves for " 
                              << static_cast<int>(pos.color) << " " 
                              << static_cast<int>(pos.piece) << " at (" << x << ", " << y << ")" 
                              << std::endl;
                }
            }
        }
    }
    return moves;
}




std::vector<Move> Board::generatePieceMoves(int x, int y, ChessPiece piece, PieceColor color) {
    std::vector<Move> moves;

    switch (piece) {
        case ChessPiece::PAWN:
            generatePawnMoves(x, y, color, moves);
            break;
        case ChessPiece::KNIGHT:
            generateKnightMoves(x, y, color, moves);
            break;
        case ChessPiece::BISHOP:
            generateBishopMoves(x, y, color, moves);
            break;
        case ChessPiece::ROOK:
            generateRookMoves(x, y, color, moves);
            break;
        case ChessPiece::QUEEN:
            generateQueenMoves(x, y, color, moves);
            break;
        case ChessPiece::KING:
            generateKingMoves(x, y, color, moves);
            break;
        default:
            break;
    }

    return moves;
}

void Board::generatePawnMoves(int x, int y, PieceColor color, std::vector<Move>& moves) {
    int direction = (color == PieceColor::WHITE) ? -1 : 1;
    int newY = y + direction;

    // Forward move
    if (newY >= 0 && newY < 8 && board[newY][x].piece == ChessPiece::EMPTY) {
        moves.push_back({x, y, x, newY, ChessPiece::PAWN, color});

        // Double move from starting position
        if ((color == PieceColor::WHITE && y == 6) || (color == PieceColor::BLACK && y == 1)) {
            int doubleStepY = y + 2 * direction;
            if (board[doubleStepY][x].piece == ChessPiece::EMPTY) {
                moves.push_back({x, y, x, doubleStepY, ChessPiece::PAWN, color});
            }
        }
    }

    // Captures
    for (int dx = -1; dx <= 1; dx += 2) {
        int newX = x + dx;
        if (newX >= 0 && newX < 8 && newY >= 0 && newY < 8) {
            if (board[newY][newX].piece != ChessPiece::EMPTY && board[newY][newX].color != color) {
                moves.push_back({x, y, newX, newY, ChessPiece::PAWN, color});
            }
        }
    }
}


void Board::generateKnightMoves(int x, int y, PieceColor color, std::vector<Move>& moves) {
    const int knightMoves[8][2] = {
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1},
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1}
    };

    for (const auto& move : knightMoves) {
        int newX = x + move[0];
        int newY = y + move[1];

        if (newX >= 0 && newX < 8 && newY >= 0 && newY < 8) {
            if (board[newY][newX].piece == ChessPiece::EMPTY || board[newY][newX].color != color) {
                moves.push_back({x, y, newX, newY, ChessPiece::KNIGHT, color});
            }
        }
    }
}

void Board::generateBishopMoves(int x, int y, PieceColor color, std::vector<Move>& moves) {
    const int directions[4][2] = {
        {-1, -1}, {1, -1}, {1, 1}, {-1, 1}
    };

    for (const auto& dir : directions) {
        int newX = x + dir[0];
        int newY = y + dir[1];
        while (newX >= 0 && newX < 8 && newY >= 0 && newY < 8) {
            if (board[newY][newX].piece == ChessPiece::EMPTY) {
                moves.push_back({x, y, newX, newY, ChessPiece::BISHOP, color});
            } else {
                if (board[newY][newX].color != color) {
                    moves.push_back({x, y, newX, newY, ChessPiece::BISHOP, color});
                }
                break;
            }
            newX += dir[0];
            newY += dir[1];
        }
    }
}

void Board::generateRookMoves(int x, int y, PieceColor color, std::vector<Move>& moves) {
    const int directions[4][2] = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };

    for (const auto& dir : directions) {
        int newX = x + dir[0];
        int newY = y + dir[1];
        while (newX >= 0 && newX < 8 && newY >= 0 && newY < 8) {
            if (board[newY][newX].piece == ChessPiece::EMPTY) {
                moves.push_back({x, y, newX, newY, ChessPiece::ROOK, color});
            } else {
                if (board[newY][newX].color != color) {
                    moves.push_back({x, y, newX, newY, ChessPiece::ROOK, color});
                }
                break;
            }
            newX += dir[0];
            newY += dir[1];
        }
    }
}

void Board::generateQueenMoves(int x, int y, PieceColor color, std::vector<Move>& moves) {
    generateBishopMoves(x, y, color, moves);
    generateRookMoves(x, y, color, moves);
}

void Board::generateKingMoves(int x, int y, PieceColor color, std::vector<Move>& moves) {
    const int directions[8][2] = {
        {-1, -1}, {0, -1}, {1, -1},
        {-1,  0},          {1,  0},
        {-1,  1}, {0,  1}, {1,  1}
    };

    for (const auto& dir : directions) {
        int newX = x + dir[0];
        int newY = y + dir[1];

        if (newX >= 0 && newX < 8 && newY >= 0 && newY < 8) {
            if (board[newY][newX].piece == ChessPiece::EMPTY || board[newY][newX].color != color) {
                moves.push_back({x, y, newX, newY, ChessPiece::KING, color});
            }
        }
    }
}

Move Board::findBestMove(PieceColor color, int depth) {
    int bestScore = -1000000;
    Move bestMove;
    std::vector<Move> legalMoves = generateAllLegalMoves(color);

    for (const Move& move : legalMoves) {
        makeMove(move);
        int score = minimax(depth - 1, false, color);
        undoMove(move);

        if (score > bestScore) {
            bestScore = score;
            bestMove = move;
        }
    }
    return bestMove;
}

int Board::minimax(int depth, bool isMaximizingPlayer, PieceColor color) {
    if (depth == 0) {
        return evaluateBoard(color);
    }

    PieceColor currentColor = isMaximizingPlayer ? color : getOpponentColor(color);
    std::vector<Move> legalMoves = generateAllLegalMoves(currentColor);

    if (legalMoves.empty()) {
        return isMaximizingPlayer ? -1000000 : 1000000;
    }

    int bestScore = isMaximizingPlayer ? -1000000 : 1000000;

    for (const Move& move : legalMoves) {
        makeMove(move);
        int score = minimax(depth - 1, !isMaximizingPlayer, color);
        undoMove(move);

        if (isMaximizingPlayer) {
            if (score > bestScore) {
                bestScore = score;
            }
        } else {
            if (score < bestScore) {
                bestScore = score;
            }
        }
    }
    return bestScore;
}

int Board::evaluateBoard(PieceColor color) {
    int score = 0;
    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            PiecePosition& pos = board[y][x];
            if (pos.piece != ChessPiece::EMPTY) {
                int pieceValue = getPieceValue(pos.piece);
                if (pos.color == color) {
                    score += pieceValue;
                } else {
                    score -= pieceValue;
                }
            }
        }
    }
    return score;
}

int Board::getPieceValue(ChessPiece piece) {
    switch (piece) {
        case ChessPiece::PAWN:   return 10;
        case ChessPiece::KNIGHT: return 30;
        case ChessPiece::BISHOP: return 30;
        case ChessPiece::ROOK:   return 50;
        case ChessPiece::QUEEN:  return 90;
        case ChessPiece::KING:   return 900;
        default: return 0;
    }
}

PieceColor Board::getOpponentColor(PieceColor color) {
    return (color == PieceColor::WHITE) ? PieceColor::BLACK : PieceColor::WHITE;
}


void Board::makeMove(const Move& move) {
    PiecePosition& fromPos = board[move.fromY][move.fromX];
    PiecePosition& toPos = board[move.toY][move.toX];

    moveHistory.push({move, toPos});

    toPos = fromPos;
    fromPos = {ChessPiece::EMPTY, PieceColor::NONE};
}

void Board::undoMove(const Move& move) {
    MoveHistoryEntry entry = moveHistory.top();
    moveHistory.pop();

    board[move.fromY][move.fromX] = board[move.toY][move.toX];
    board[move.toY][move.toX] = entry.capturedPiece;
}

bool Board::isAnimating() const {
    if (!animatedPieces.empty()) {
        std::cout << "Animation in progress. Animated pieces count: " << animatedPieces.size() << std::endl;
        return true;
    }
    return false;
}

