#include "game.h"

pieceStructRef newPiece(gameStructRef game, int color, int type, int player)
{
    pieceStructRef new = malloc(sizeof(struct pieceStruct));
    new->color = color;
    new->type = type;
    new->playerHolder = player;
    new->size = 30;
    new->circle = (Rectangle) {0, 0, 0, 0};
    return new;
}

void createBoard(gameStructRef game)
{
    game->boardCreated++;
    for(int y = 1; y <= game->boardsize; y++){
        for(int x = 1; x <= game->boardsize; x++){
            if (y<=game->boardsize/2-1){ // Fichas blancas
                if((y%2!=0 && x%2==0) || (y%2==0 && x%2!=0)){         
                    pieceStructRef new = newPiece(game, 1, 1, 1);
                    game->board[x][y] = new;
                }
            } else if (y>=game->boardsize/2+2){ // Fichas Negras
                if((y%2!=0 && x%2==0) || y%2==0 && x%2!=0){
                    pieceStructRef new = newPiece(game, 0, 1, 2);
                    game->board[x][y] = new;
                }
            } else if (y == game->boardsize/2 && (y%2==0 && x%2!=0)){
                fprintf(stderr, "posición vacia [%d][%d]\n", x, y);
                pieceStructRef new = newPiece(game, 0, 0, 0);
                game->board[x][y] = new;
            } else if (y == game->boardsize/2+1 && (y%2!=0 && x%2==0)){
                fprintf(stderr, "posición vacia [%d][%d]\n", x, y);
                pieceStructRef new = newPiece(game, 0, 0, 0);
                game->board[x][y] = new;
            }
        }
    }
}