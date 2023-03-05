#include <iostream>
#include <string>
#include "chess.h"

using namespace std;

int main() {
    char king_pos[3]; //coordinates of the king
    char bishop_pos[3]; //coordinates of the bishop
    char rook_pos[3]; //coordinates of the rook
    string alf = "abcdefgh"; // posibble values of the desk columns
    cout << "Enter the positions of the chess pieces in the following format: 'B2' (the first symbol is the column name (letter from A to H), the second is the row number (number from 1 to 8))\n";
    cout << "Enter the position of the king: ";
    cin.getline(king_pos, 3);
    king_pos[0] = tolower(king_pos[0]);
    if (alf.find(king_pos[0]) == string::npos || int(king_pos[1]) - 48 > 8 || int(king_pos[1]) - 48 < 1) //if the postion does not exist
    {
        cout << "Error! Incorrect format of the entered data!\n";
        exit(1);
    }
    cout << "Enter the position of the bishop: ";
    cin.getline(bishop_pos, 3);
    bishop_pos[0] = tolower(bishop_pos[0]);
    if (alf.find(bishop_pos[0]) == string::npos || int(bishop_pos[1]) - 48 > 8 || int(bishop_pos[1]) - 48 < 1) //if the postion does not exist
    {
        cout << "Error! Incorrect format of the entered data!\n";
        exit(1);
    }
    cout << "Enter the position of the rook: ";
    cin.getline(rook_pos, 3);
    rook_pos[0] = tolower(rook_pos[0]);
    if (alf.find(rook_pos[0]) == string::npos || int(rook_pos[1]) - 48 > 8 || int(rook_pos[1]) - 48 < 1) //if the postion does not exist
    {
        cout << "Error! Incorrect format of the entered data!\n";
        exit(1);
    }
    if (king_pos[0] == rook_pos[0] && king_pos[1] == rook_pos[1] || king_pos[0] == bishop_pos[0] && king_pos[1] == bishop_pos[1] || bishop_pos[0] == rook_pos[0] && bishop_pos[1] == rook_pos[1])
    {
        cout << "Error! Two pieces have the same coordinates!";
        exit(1);
    } 
    cout << int('c') - int('a');
    bool rook = rook_threat(king_pos, rook_pos, bishop_pos);
    bool bishop = bishop_threat(king_pos, bishop_pos, rook_pos);
    if (rook) 
    {
        if (bishop)
            cout << "Error! Check from two pieces at the same time!";
        else
            cout << "Check from the rook!";
    }
        
    else if (bishop)
        cout << "Check from the bishop!";
    else
        cout << "No check!";

}