#include "catch.hpp"
#include "Validator.hpp"
#include "board.hpp"

SCENARIO("Validator detects when game is won") {
    
    GIVEN("An empty board with no moves taken") {
        
        Board board(3);
        Validator v;
        
        THEN("Validator returns no winner i.e. 0"){
            bool winner = v.checkWin(board.getGrid(), 1);
            REQUIRE(!winner);
        }
    }
    
    GIVEN("A board with complete row for player 1") {
        
        Board board(3);
        Validator v;
        board.makeMove(1, 0, 1);
        board.makeMove(1, 1, 1);
        board.makeMove(1, 2, 1);

        THEN("Validator returns true for player one") {
            bool winner = v.checkWin(board.getGrid(), 1);
            REQUIRE(winner);
        }
        
        THEN("Validator returns false for player two") {
            bool winner = v.checkWin(board.getGrid(), 2);
            REQUIRE(!winner);
        }
    }
    
    GIVEN("A full row of ones") {
        
        Validator v;
        vector<int> row = {1, 1, 1};
        
        THEN("Check row should return true for one") {
            bool fullRow = v.checkRow(row, 1);
            REQUIRE(fullRow);
        }
        
        THEN("Check row should return false for two") {
            bool fullRow = v.checkRow(row, 2);
            REQUIRE(!fullRow);
        }
        
    }
    
    GIVEN("A full row of twos") {
        
        Validator v;
        vector<int> row = {2, 2, 2};
        
        THEN("Check row should return true for two") {
            bool fullRow = v.checkRow(row, 2);
            REQUIRE(fullRow);
        }
    }
    
    GIVEN("A non-full rows of ones") {
        
        Validator v;
        vector<int> row = {1, 0, 1};
        vector<int> row1 = {1, 0, 0};
        vector<int> row2 = {1, 2, 0};
        
        THEN("Check row should return false for one") {
            REQUIRE(!v.checkRow(row, 1));
            REQUIRE(!v.checkRow(row1, 1));
            REQUIRE(!v.checkRow(row2, 1));
        }
        
    }
    
    GIVEN("A board with complete column for player 1") {
        
        Board board(3);
        Validator v;
        board.makeMove(0, 2, 1);
        board.makeMove(1, 2, 1);
        board.makeMove(2, 2, 1);
        
        THEN("Validator returns true for player one") {
            bool winner = v.checkWin(board.getGrid(), 1);
            REQUIRE(winner);
        }
        
        THEN("Validator returns false for player two") {
            bool winner = v.checkWin(board.getGrid(), 2);
            REQUIRE(!winner);
        }
    }
    
    GIVEN("A board with complete diagonal for player 1") {
        
        Board board(3);
        Validator v;
        board.makeMove(0, 0, 1);
        board.makeMove(1, 1, 1);
        board.makeMove(2, 2, 1);
        
        THEN("Validator returns true for player one") {
            bool winner = v.checkWin(board.getGrid(), 1);
            REQUIRE(winner);
        }
        
        THEN("Validator returns false for player two") {
            bool winner = v.checkWin(board.getGrid(), 2);
            REQUIRE(!winner);
        }
    }
    
    GIVEN("A 4x4 board") {
        
        Board board(4);
        Validator v;
        
        WHEN("board has complete row for player 1")
        {
            board.makeMove(0, 2, 1);
            board.makeMove(1, 2, 1);
            board.makeMove(2, 2, 1);
            board.makeMove(3, 2, 1);
            
            THEN("Validator returns true for player one") {
                bool winner = v.checkWin(board.getGrid(), 1);
                REQUIRE(winner);
            }
        }
        
        WHEN("board has complete column for player 2")
        {
            board.makeMove(1, 0, 2);
            board.makeMove(1, 1, 2);
            board.makeMove(1, 2, 2);
            board.makeMove(1, 3, 2);

            
            THEN("Validator returns true for player one") {
                bool winner = v.checkWin(board.getGrid(), 2);
                REQUIRE(winner);
            }
        }
        
        WHEN("board has complete diagonal")
        {
            board.makeMove(0, 3, 1);
            board.makeMove(1, 2, 1);
            board.makeMove(2, 1, 1);
            board.makeMove(3, 0, 1);

            
            THEN("Validator returns true for player one") {
                bool winner = v.checkWin(board.getGrid(), 1);
                REQUIRE(winner);
            }
        }
    }
}

