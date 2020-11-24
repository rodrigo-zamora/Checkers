#include <stdlib.h>
#include <stdio.h>
#include "raylib.h"

struct pieceStruct{
    int color; // 0 = nothing; 1 = black ; 2 = white
    int type; // 0 = nothing ; 1 = normal ; 2 = king
    int playerHolder; // 0 = nothing; 1 = black; 2 = white
    int size;
    Rectangle circle;
};

typedef struct pieceStruct* pieceStructRef;

struct gameStruct{
    int boardsize, screenWidth, screenHeight, currentWindow;
    char* currentPlayer;
    pieceStructRef board[13][13]; // 8x8 10x10 12x12
};

typedef struct gameStruct* gameStructRef;

//
//  Funciones
//

void createBoard(gameStructRef game);

pieceStructRef newPiece(gameStructRef game, int color, int type, int player);