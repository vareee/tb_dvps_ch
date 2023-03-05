#include <iostream>
#include <string>
#include "chess.h"

using namespace std;

int main() {
    char king_pos[3];
    char bishop_pos[3];
    char rook_pos[3];
    string alf = "abcdefgh";
    cout << "Enter the positions of the chess pieces in the following format: 'B2' (the first symbol is the column name (letter from A to H), the second is the row number (number from 1 to 8))\n";
    cout << "Enter the position of the king: ";
    cin.getline(king_pos, 3);
    king_pos[0] = tolower(king_pos[0]);
    if (alf.find(king_pos[0]) == string::npos || int(king_pos[1]) - 48 > 8 || int(king_pos[1]) - 48 < 1)
    {
        cout << "error\n";
        exit(1);
    }
    cout << "Enter the position of the bishop: ";
    cin.getline(bishop_pos, 3);
    bishop_pos[0] = tolower(bishop_pos[0]);
    if (alf.find(bishop_pos[0]) == string::npos || int(bishop_pos[1]) - 48 > 8 || int(bishop_pos[1]) - 48 < 1)
    {
        cout << "error\n";
        exit(1);
    }
    cout << "Enter the position of the rook: ";
    cin.getline(rook_pos, 3);
    rook_pos[0] = tolower(rook_pos[0]);
    if (alf.find(rook_pos[0]) == string::npos || int(rook_pos[1]) - 48 > 8 || int(rook_pos[1]) - 48 < 1)
    {
        cout << "error\n";
        exit(1);
    }
    // cout << king_pos << endl;
    // cout << king_pos[0] << rook_pos[0] << king_pos[1] << rook_pos[1] << endl;
    bool rook = rook_threat(king_pos, rook_pos);
    bool bishop = bishop_threat(king_pos, bishop_pos);
    if (rook) {
        if (bishop)
            cout << "Error!";
        else
            cout << "Check from the rook!";
    }
        
    else if (bishop)
        cout << "Check from the bishop!";
    else
        cout << "No check!";
    // cout << int('b');

}