//
//  inputParser.hpp
//  tictactoe
//
//  Created by Jack Thorp on 14/11/2017.
//  Copyright © 2017 Jack Thorp. All rights reserved.
//

#ifndef InputParser_hpp
#define InputParser_hpp

#include <stdio.h>
#include <string>

class InputParser
{
    const int dimension;
public:
    InputParser(int dim):dimension(dim){};
    bool validInput(std::string text);
};


#endif /* inputParser_hpp */
