//
//  testInputParser.cpp
//  tests
//
//  Created by Jack Thorp on 14/11/2017.
//  Copyright © 2017 Jack Thorp. All rights reserved.
//

#include "catch.hpp"
#include "InputParser.hpp"

SCENARIO("Incorrect user input is rejected by input parser") {
    
    GIVEN("A fresh 3x3 input parser") {
    
        InputParser ip(3);
        
        THEN("'A12' is too long") {
            REQUIRE(!ip.validInput("A12"));
        }
        
        THEN("'A' is too short") {
            REQUIRE(!ip.validInput("A"));
        }
        
        THEN("First character must be between 1 and 3") {
            REQUIRE(!ip.validInput("A1"));
            REQUIRE(ip.validInput("1A"));
            REQUIRE(ip.validInput("3B"));
            REQUIRE(!ip.validInput("4A"));
        }
        
        THEN("Second character must be between A and C") {
            REQUIRE(!ip.validInput("11"));
            REQUIRE(ip.validInput("1A"));
            REQUIRE(ip.validInput("2C"));
            REQUIRE(!ip.validInput("3D"));
        }
        
    }
    
    GIVEN("A fresh 4x4 input parser") {
        
        InputParser ip(4);
        
        THEN("First character must be between 1 and 4") {
            REQUIRE(!ip.validInput("A1"));
            REQUIRE(ip.validInput("1A"));
            REQUIRE(ip.validInput("4C"));
            REQUIRE(!ip.validInput("5A"));
        }
        
        THEN("Second character must be between A and D") {
            REQUIRE(!ip.validInput("11"));
            REQUIRE(ip.validInput("1A"));
            REQUIRE(ip.validInput("3D"));
            REQUIRE(!ip.validInput("4E"));
        }
        
    }
}
