#include <iostream>
#include <sstream>
#include <string>
#include "board.hpp"
#include "InputParser.hpp"

/*
 Objects in program:
 
 Validator
    -   Determines whether game is over i.e. line has been made on a board.
 
 Board
    -   Data structure that represents the game grid.
    -   Handles drawing to terminal / conversion to string
    -
 
 Game Engine
    -   Handles turns
    -   Handles reading user input
    -   Handles writing info and output to terminal.
 */

using namespace std;

int main(int argc, const char * argv[]) {
    
    // Get grid size from user.
    string dimStr;
    int dimension;
    do {
        cout << "What grid size would you like to play (3 to 10): ";
        getline(cin, dimStr);
        stringstream(dimStr) >> dimension;
        cout << endl;
    } while (dimension < 3 || dimension > 10);
    
    
    // Set up board, player and limiting number of turns.
    Board board(dimension);
    int player = 2;
    int turns = dimension * dimension;
    string moveText;
    InputParser ip(dimension);
    bool validMove;
    
    // MAIN GAME LOOP
    while(!board.hasWon(player) && turns > 0)
    {
        board.draw();
        player = (player % 2) + 1;
        validMove = false;
        
        do {
            cout << "Player " << player << " make a move:";
            cin >> moveText;
            cout << endl;
            
            if (!ip.validInput(moveText))
            {
                validMove = false;
            } else {
                int x = moveText[0] - '0' - 1;
                int y = moveText[1] - 'A';
                validMove = board.makeMove(x, y, player);
            }
        } while (!validMove);
        
        --turns;
        
    }
    
    // Print out final credits
    cout << endl;
    board.draw();
    cout << "Player " << player << " has won!" << endl;
    return 0;
}
