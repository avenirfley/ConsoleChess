#include <iostream>
#include <string>
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


array<char*, 8> DEFAULT_POSITION = {"rnbqkbnr","pppppppp", "OOOOOOOO","OOOOOOOO","OOOOOOOO","OOOOOOOO","PPPPPPPP","RNBQKBNR"};

void DisplayBoard(array<char*, 8> temp)
{
    cout <<"    1  2  3  4  5  6  7  8 "<<endl;
    cout <<"  -------------------------"<<endl;
    for(int i = 0; i<8;i++)
    {
        cout<<((char)('a'+i))<<"| ";
        for(int j=0;j<8;j++)
        {
            cout<<" "<<temp[i][j]<<" ";
        }
        cout<<"|"<<endl;
    }
    cout <<"  -------------------------"<<endl;
}

array<char*, 8> movePiece(array<char*, 8> temp,string source,string dest)
{
    /*int Row = (sourceRow-'a');
    int destiRow = (destRow-'a');
    char temp2 = temp[Row][sourceCol];
    char temp3 = temp[destiRow][destCol];
    temp[Row][sourceCol] = temp3;
    temp[destiRow][destCol] = temp2;*/
    return temp;
}

void consolechess(array<char*, 8> tempBoard)
{
    array<char*, 8> currentBoard = tempBoard;

    DisplayBoard(currentBoard);

    string BLACK = "black";
    string WHITE = "white";
    string EMPTY = "[]";
    string PAWN = "pawn";
    string KNIGHT = "knight";
    string BISHOP = "bishop";
    string ROOK = "rook";
    string QUEEN = "queen";
    string KING = "king";
    string toMove = "";
    string turn = WHITE;
    string temp;
    string unitTemp, unitTemp2;

    bool bExit = false;
    bool bValid = false;

    int whiteScore = 0;
    int blackScore = 0;

    while(!bExit)
    {
        cout<<"Turn: "<<((turn==WHITE)?"WHITE":"BLACK")<<endl;
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

            if(unitTemp2.empty() || unitTemp.empty() || (unitTemp.length() > 2) || (unitTemp2.length() > 2)) {
                cout<<"You entered an invalid action!"<<endl;
                bValid = false;
            }
            else {
                cout<<endl<<"Attempting to move "<<turn<<" "<<unitTemp<<" to "<< unitTemp2<<endl;

                currentBoard = movePiece(currentBoard, unitTemp,unitTemp2);

                DisplayBoard(currentBoard);

                if(turn == WHITE) whiteScore+=10;
                else blackScore+=10;
            }
        }

        cout<<"-----   EndTurn   -----"<<endl<<endl;

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
    cout<<"Initializing Console Chess..."<<endl;

    consolechess(DEFAULT_POSITION);

    return 1;
}
