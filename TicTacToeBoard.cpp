#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Constructor sets an emptO board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
  if (turn == X)
    turn = O;
  else
    turn = X;

  return turn;
//  return Invalid;
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does
 * NOT allow to place a piece in a location where there is alreadO a piece.
 * In that case, placePiece just returns what is alreadO at that location.
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
**/
Piece TicTacToeBoard::placePiece(int row, int column)
{
  Piece currentPiece = getPiece(row, column);
  if(currentPiece == Blank)
  {
    Piece tempturn = turn;
    toggleTurn();
    return turn;
  }
  else if(currentPiece == Invalid)
  {
    return Invalid;
  }
  else
    return currentPiece;


}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
  if(row  > 2|| column > 2)
    return Invalid;
  Piece piece = board[row][column];
  return piece;
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
  if(getPiece(0,0) == X && getPiece(0,1)  == X&& getPiece(0,2) == X)
    return X;
  else if(getPiece(1,0) == X && getPiece(1,1)  == X && getPiece(1,2) == X)
    return X;
  else if(getPiece(2,0) == X && getPiece(2,1)  == X && getPiece(2,2) == X)
    return X;
  else if(getPiece(0,0) == X && getPiece(1,0)  == X && getPiece(2,0) == X)
    return X;
  else if(getPiece(0,1) == X && getPiece(1,1)  == X && getPiece(2,1) == X)
    return X;
  else if(getPiece(0,2) == X && getPiece(1,2)  == X && getPiece(2,2) == X)
    return X;
  else if(getPiece(0,0) == X && getPiece(1,1)  == X && getPiece(2,2) == X)
    return X;
  else if(getPiece(0,2) == X && getPiece(1,1)  == X && getPiece(0,2) == X)
    return X;
  else if(getPiece(0,0) == O && getPiece(0,1)  == O&& getPiece(0,2) == O)
    return O;
  else if(getPiece(1,0) == O && getPiece(1,1)  == O && getPiece(1,2) == O)
    return O;
  else if(getPiece(2,0) == O && getPiece(2,1)  == O && getPiece(2,2) == O)
    return O;
  else if(getPiece(0,0) == O && getPiece(1,0)  == O && getPiece(2,0) == O)
    return O;
  else if(getPiece(0,1) == O && getPiece(1,1)  == O && getPiece(2,1) == O)
    return O;
  else if(getPiece(0,2) == O && getPiece(1,2)  == O && getPiece(2,2) == O)
    return O;
  else if(getPiece(0,0) == O && getPiece(1,1)  == O && getPiece(2,2) == O)
    return O;
  else if(getPiece(0,2) == O  && getPiece(1,1)  == O && getPiece(0,2) == O)
    return O;
  else if((getPiece(0,0) == X  || getPiece(0,0) == O) && (getPiece(1,0) == X  || getPiece(1,0) == O)&& (getPiece(2,0) == X  || getPiece(2,0) == O)&& (getPiece(3,0) == X  || getPiece(3,0) == O)&& (getPiece(3,1) == X  || getPiece(3,1) == O)&& (getPiece(3,2) == X  || getPiece(3,2) == O)&& (getPiece(3,3) == X  || getPiece(3,3) == O))
    return Blank;
  else
    return Invalid;

}
