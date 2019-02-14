#include "Validator.hpp"

bool Validator::checkWin(const vector<vector<int> >& board, int player)
{
    //for (auto rows = board.begin(); rows != board.end(); ++rows)
   // {
    //    if(checkRow(*rows, player)){return true;};
    //}
    
    bool colWin = false;
    bool rowWin = false;
    bool diagRightWin = true;
    bool diagLeftWin = true;
    int j = 0;

    // 0,0 1,1 2,2 && 0,2 1,1 2,0
    for (int i = 0; i < board.size(); ++i)
    {
        diagRightWin &= board.at(i).at(i) == player;
        diagLeftWin &= board.at(i).at(board.size()-i-1) == player;
        
        colWin = true;
        rowWin = true;
        j = 0;
        while((colWin || rowWin) && j < board.size())
        {
            rowWin &= board.at(i).at(j) == player;
            colWin &= board.at(j).at(i) == player;
            j++;
        }
        
        if(colWin || rowWin){return true;}
    }
    
    if (diagLeftWin || diagRightWin) {return true;}
    
    return false;
}

bool Validator::checkRow(const vector<int>& row, int player)
{
    int count = 0;
    auto col = row.begin();
    while(*col == player && col != row.end()) {
        count++;
        ++col;
    }
    return count == row.size();
}

// Needs to check no rows, columns or diagonals.??
