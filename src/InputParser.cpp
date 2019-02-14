//
//  inputParser.cpp
//  tictactoe
//
//  Created by Jack Thorp on 14/11/2017.
//  Copyright © 2017 Jack Thorp. All rights reserved.
//

#include "InputParser.hpp"

bool InputParser::validInput(std::string text) {
    
    if (text.length() != 2) {return false;}
    
    // Converts from char to int
    int x = text[0] - '0';
    int y = text[1] - '0';
    
    if (x < 1 || x > dimension) { return false;}
    if (y < 17 || y >= 17 + dimension) { return false;}
    
    return true;
}
