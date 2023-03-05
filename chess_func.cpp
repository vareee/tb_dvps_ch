#include <iostream>
#include "chess.h"

using namespace std;

bool bishop_threat(char king_pos[3], char bishop_pos[3]) {
    bool check = false;
    if (abs(int(king_pos[0]) - int(bishop_pos[0])) == abs(int(king_pos[1]) - int(bishop_pos[1])) )
        check = true;
    return check;
}

bool rook_threat(char king_pos[3], char rook_pos[3]) {
    bool check = false;
    if (king_pos[0] == rook_pos[0] || king_pos[1] == rook_pos[1])
        check = true;
    return check;
}