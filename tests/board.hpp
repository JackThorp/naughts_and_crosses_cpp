//
//  board.hpp
//  tictactoe
//
//  Created by Jack Thorp on 10/09/2017.
//  Copyright © 2017 Jack Thorp. All rights reserved.
//

#ifndef board_hpp
#define board_hpp

#include "Validator.hpp"
#include <vector>

using namespace std;

class Board {
    
private:
    int dimension;
    vector< vector<int> > grid;
    Validator validator;
    
public:
    Board(int dim);
    static int CLEAR;
    int getDimension();
    vector< vector<int> > getGrid();
    bool makeMove(int x, int y, int marker);
    bool hasWon(int player);
    void draw();
};

#endif /* board_hpp */
