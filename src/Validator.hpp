#ifndef Validator_hpp
#define Validator_hpp

#include <vector>

using namespace std;

class Validator
{
    public:
        bool checkWin(const vector<vector<int> >& board, int x);
        bool checkRow(const vector<int>& row, int player);
};

#endif
