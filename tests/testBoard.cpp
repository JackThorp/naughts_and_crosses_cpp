//
//  testBoard.cpp
//  tictactoe
//
//  Created by Jack Thorp on 10/09/2017.
//  Copyright © 2017 Jack Thorp. All rights reserved.
//

#include "catch.hpp"
#include "board.hpp"

SCENARIO("Board is constructed correctly") {
    
    GIVEN("A new board with explicit dimension") {
        
        Board board(3);
        
        THEN("Retreiving dimension returns value at construction") {
            REQUIRE(board.getDimension() == 3);
        }
        
        THEN("Retreiving the grid returns a zero initialised 2D array") {
            vector< vector<int> > grid = board.getGrid();
            REQUIRE(grid.size() == 3);
            REQUIRE(grid.at(2).size() == 3);
            REQUIRE(grid.at(1).at(1) == Board::CLEAR);
        }
    }
}

SCENARIO("Board accepts moves on unoccupied spaces") {
    
    GIVEN("A new board") {
        
        Board board(3);
        int marker = 2;
        int x, y;
        
        WHEN("In bounds coordinates are passed") {
            
            x = y = 1;
            bool move_made = board.makeMove(x, y, marker);
            
            THEN("A change is made to the grid") {
                vector< vector<int> > grid = board.getGrid();
                
                REQUIRE(move_made);
                REQUIRE(grid.at(x).at(y) == marker);
            }
        }
        
        WHEN("Out of bounds coordinates are passed") {
            
            x = y = 3;
            
            THEN("The attempt to makeMove fails") {
                REQUIRE(!board.makeMove(x, y, marker));
            }
            
            x = y = -1;
            
            THEN("The attempt to makeMove fails") {
                REQUIRE(!board.makeMove(x, y, marker));
            }
        }
    }
}

SCENARIO("Board does not accept move in occupied square") {
    
    GIVEN("A 3x3 board with occupied square at (1,1)") {
        
        Board board(3);
        int marker_1 = 1;
        int marker_2 = 2;
        board.makeMove(1, 1, marker_1);
        
        WHEN("Move is made at coordinares (1,1)") {
            
            bool madeMove = board.makeMove(1, 1, marker_2);
            
            THEN("makeMove returns false and grid is unchanged") {
                REQUIRE(!madeMove);
                REQUIRE(board.getGrid().at(1).at(1) == marker_1);
            }
            
        }
    }
}

SCENARIO("Board is drawn to standard out correctly") {
    
    GIVEN("An 3x3 board") {
        Board board(3);
        
        WHEN("Empty") {
            THEN("board is drawn corretly") {
                board.draw();
                REQUIRE(true);
            }
        }
        
        WHEN("marker at 0,0 and 2,1") {
            board.makeMove(0, 0, 1);
            board.makeMove(2, 1, 2);
            THEN("board is drawn correctly") {
                board.draw();
                REQUIRE(true);
            }
        }
    }
}
