#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <fstream>
#include <array>
#include <algorithm>

using namespace std;

// THE CLASSIC GAMME LOOP
// NOTES: Switch array of c strings to one fen array. (fen is a chess programming term)
/**********************************
 state := playGame;
initialize position
print board
while (state != gameover)
   wait for input of a move by the user
   make move (if legal)
   if (mate or stalemate) {
      state := gameOver;
      break;
   }
   search move with allocated time
   make move
   print move and update board
   if (mate or stalemate)
      state := gameOver;
}
print "thank you for playing the game";
*************************************/


char DEFAULT_POSITION[64];

void DisplayBoard(char* temp)
{
    cout <<"    1  2  3  4  5  6  7  8 "<<endl;
    cout <<"  -------------------------"<<endl;
    for(int i = 0; i<8;i++)
    {
        cout<<((char)('a'+i))<<"| ";
        for(int j=0;j<8;j++)
        {
            cout<<" "<<temp[i*8+j]<<" ";
        }
        cout<<"|"<<endl;
    }
    cout <<"  -------------------------"<<endl;
}

void consolechess(char* tempBoard)
{
    char* currentBoard = tempBoard;
    char BLACK = 'b';
    char WHITE = 'w';
    char EMPTY = ('a'-1);
    char PAWN = 'p';
    char KNIGHT = 'n';
    char BISHOP = 'b';
    char ROOK = 'r';
    char QUEEN = 'q';
    char KING = 'k';
    string toMove = "";
    char turn = WHITE;
    string temp;
    string unitTemp, unitTemp2;

    bool bExit = false;
    bool bValid = false;

    int whiteScore = 0;
    int blackScore = 0;

    cout<<"Turn: "<<((turn==WHITE)?"WHITE":"BLACK")<<endl;
    while(!bExit)
    {
        DisplayBoard(currentBoard);
        bValid = false;
        while(!bValid)
        {
            bValid = true;
            cout<<"Please enter action with 'letternumber' Example: g4 e4 "<<endl;
            cin>>unitTemp;
            cin>>unitTemp2;
            transform(unitTemp.begin(), unitTemp.end(), unitTemp.begin(), ::tolower);
            transform(unitTemp2.begin(), unitTemp2.end(), unitTemp2.begin(), ::tolower);
            // Parse letter and number to process here...

            if(unitTemp2.empty() || unitTemp.empty() || (unitTemp.length() > 2) ||
               (unitTemp2.length() > 2) || (((unitTemp.c_str()[0])-'a') > 7) ||
               (((unitTemp2.c_str()[0])-'a') > 7) || (((unitTemp.c_str()[1])-'0')-1 > 7) ||
               (((unitTemp2.c_str()[1])-'0')-1 > 7)) {
                cout<<"You entered an invalid action!"<<endl;
                bValid = false;
            }
            else {


                char sourceRow = unitTemp.c_str()[0];
                char destRow = unitTemp2.c_str()[0];
                int sourceCol = ((unitTemp.c_str()[1])-'0')-1;
                int destCol = ((unitTemp2.c_str()[1])-'0')-1;
                int Row = (sourceRow-'a');
                int destiRow = (destRow-'a');
                char temp2 = currentBoard[(Row*8)+sourceCol];
                char temp3 = currentBoard[(destiRow*8)+destCol];
                currentBoard[(Row*8)+sourceCol] = temp3;
                currentBoard[(destiRow*8)+destCol] = temp2;
                system("cls");

                cout<<((turn==WHITE)?"WHITE":"BLACK")<<"moved "<<unitTemp<<" to "<<unitTemp2<<endl;

                if(turn == WHITE) whiteScore+=10;
                else blackScore+=10;
            }
        }

        //switch the turn
        if(turn == WHITE) turn = BLACK;
        else turn = WHITE;
//        if(temp.compare("endgame")==0) {
//            cout<<endl<<"------ GAME OVER ------"<<endl;
//            cout<<"White Score: "<< whiteScore<<endl;
//            cout<<"Black Score: "<< blackScore<<endl;
//            cout<<endl<<"Would you like to start a new game? (yes/no): ";
//            cin>>unitTemp;
//            transform(unitTemp.begin(), unitTemp.end(), unitTemp.begin(), ::tolower);
//            bValid = false;
//            while(!bValid)
//            {
//                bValid = true;
//                if(unitTemp.compare("yes") == 0) {
//                    cout<<endl<<"Starting a new game..."<<endl;
//                    currentBoard = DEFAULT_POSITION;
//                    whiteScore = blackScore = 0;
//                    turn = WHITE;
//                    toMove="";
//                    consolechess(DEFAULT_POSITION);
//                    bExit = true;
//                }
//                else if (unitTemp.compare("no") == 0) bExit = true;
//                else {
//                    cout<<endl<<"Please Enter yes/no: ";
//                    bValid = false;
//                }
//            }
//        }
    }
}

int main()
{
    strcpy(DEFAULT_POSITION,"rnbqkbnrppppppppOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOPPPPPPPPRNBQKBNR");
    consolechess(DEFAULT_POSITION);
    return 1;
}
