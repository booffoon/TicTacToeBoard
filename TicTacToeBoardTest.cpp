/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"

class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){}
		virtual ~TicTacToeBoardTest(){}
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(TicTacToeBoardTest, place_blank)
{
	TicTacToeBoard board;
  Piece piece = board.placePiece(0,0);

  ASSERT_EQ(piece, O);
}

TEST(TicTacToeBoardTest, place_invalid)
{
	TicTacToeBoard board;
  Piece piece = board.placePiece(3,3);

  ASSERT_EQ(piece, Invalid);
}

TEST(TicTacToeBoardTest, place_on_piece)
{
	TicTacToeBoard board;
  board.placePiece(0,0);
	Piece piece = board.placePiece(0,0);

  ASSERT_EQ(piece, piece);
}

TEST(TicTacToeBoardTest, get_no_piece)
{
	TicTacToeBoard board;
	Piece piece = board.getPiece(0,0);

  ASSERT_EQ(piece, Blank);
}

TEST(TicTacToeBoardTest, get_invalid_piece)
{
	TicTacToeBoard board;
	Piece piece = board.getPiece(3,3);

  ASSERT_EQ(piece, Invalid);
}

TEST(TicTacToeBoardTest, check_not_done)
{
	TicTacToeBoard board;
	board.placePiece(0,0);
	board.placePiece(1,0);
	board.placePiece(0,1);
	Piece winner = board.getWinner();


  ASSERT_EQ(winner, Invalid);
}

/*TEST(TicTacToeBoardTest, get_regular_piece)
{
	TicTacToeBoard board;
	Piece placedPiece = board.placePiece(0,0);
	Piece piece = board.getPiece(0,0);

  ASSERT_EQ(piece, placedPiece);
}*/
