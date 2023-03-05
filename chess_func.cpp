#include <iostream>
#include "chess.h"

using namespace std;

bool bishop_threat(char king_pos[3], char bishop_pos[3], char rook_pos[3]) { //returns true if the check comes from the bishop
    bool check = false;
    if (abs(int(king_pos[0]) - int(bishop_pos[0])) == abs(int(king_pos[1]) - int(bishop_pos[1])))
    {
        if (abs(int(rook_pos[0]) - int(bishop_pos[0])) != abs(int(rook_pos[1]) - int(bishop_pos[1])) || int(bishop_pos[1]) < int(rook_pos[1]) && int(bishop_pos[1]) < int(king_pos[1]) || int(bishop_pos[1]) > int(rook_pos[1]) && int(bishop_pos[1]) > int(king_pos[1]))
            check = true;
    }
        
    return check;
}

bool rook_threat(char king_pos[3], char rook_pos[3], char bishop_pos[3]) { //returns true if the check comes from the rook
    bool check = false;
    if (king_pos[0] == rook_pos[0])
    {
        if (rook_pos[0] != bishop_pos[0] || int(bishop_pos[1]) < int(rook_pos[1]) && int(bishop_pos[1]) < int(king_pos[1]) || int(bishop_pos[1]) > int(rook_pos[1]) && int(bishop_pos[1]) > int(king_pos[1]))
            check = true;
    }
        
    else if (king_pos[1] == rook_pos[1])
    {
        if (rook_pos[1] != bishop_pos[1] || int(bishop_pos[0]) < int(rook_pos[0]) && int(bishop_pos[0]) < int(king_pos[0]) || int(bishop_pos[0]) > int(rook_pos[0]) && int(bishop_pos[0]) > int(king_pos[0]))
            check = true;
    }
        
    return check;
}