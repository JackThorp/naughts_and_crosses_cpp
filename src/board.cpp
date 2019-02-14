//
//  board.cpp
//  tictactoe
//
//  Created by Jack Thorp on 10/09/2017.
//  Copyright © 2017 Jack Thorp. All rights reserved.
//

#include <vector>
#include <iostream>
#include "Validator.hpp"
#include "board.hpp"

int Board::CLEAR = 0;

Board::Board(int dim) {
    
    dimension = dim;
    grid.resize(dim, vector<int>(dim, CLEAR));
    
}

int Board::getDimension() {
    return dimension;
}

vector< vector<int> > Board::getGrid() {
    return grid;
}

// Takes an x and y coordinate for the board and marks the
// grid with the given marker.
bool Board::makeMove(int x, int y, int marker){
    
    // vector.at() throws out of bounds exception if index is >= size.
    // because the function sig takes unsigned int. All negative indicies are implicitly converted to
    // signed ints e.g. -1 becomes 4294967295.
    // This behaviour is not always what might be desired or expected so better to be explicit!
    
    if (x < 0 || y < 0) { return false; }
    if (x >= grid.size() || y >= grid.size()) { return false; }
    if (grid.at(x).at(y) != CLEAR) { return false; }
    
    grid.at(x).at(y) = marker;
    return true;
    
}

void drawRowHelper(string item, string terminator, int dim) {
    std::cout << " ";
    for (int i = 0; i < dim; i++) {
        std::cout << item;
    }
    std::cout << terminator << std::endl;
}

void Board::draw() {
    
    std::cout << "  ";
    for (int j = 1; j <= dimension; j++) {
        std::cout << j << " ";
    }
    std::cout << std::endl;
    
    for (int x = 0; x < dimension; x++) {
        
        drawRowHelper("+-", "+", dimension);
        std::cout << (char) (65 + x);
        
        for (int j = 0; j < dimension; j++) {
            std::cout << "|" << grid.at(j).at(x);
        }
        std::cout << "|" << std::endl;
    }
    drawRowHelper("+-", "+", dimension);
}

bool Board::hasWon(int player) {
    return validator.checkWin(grid, player);
}
