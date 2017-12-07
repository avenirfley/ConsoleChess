#include <iostream>
#include <string>
#include <fstream>
#include <array>
#include <algorithm>

using namespace std;

// THE CLASSIC GAMME LOOP
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

array<char*, 8> movePiece(array<char*, 8> temp, char sourceRow,int sourceCol,char destRow,int destCol)
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
    string unitTemp;

    bool bExit = false;
    bool bValid = false;

    int whiteScore = 0;
    int blackScore = 0;

    while(!bExit)
    {
        cout<<"Turn: "<<((turn==WHITE)?"WHITE":"BLACK")<<endl;
        cout<<"What would you like to do? ('exit', 'move', 'endgame')"<<endl;
        cin>>temp;
        transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        if(temp.compare("exit") == 0){
            bExit=true;
        }
        else if(temp.compare("move") == 0){
            bValid = false;
            while(!bValid)
            {
                bValid = true;
                cout<<"What unit would you like to move?";
                cin>>unitTemp;
                transform(unitTemp.begin(), unitTemp.end(), unitTemp.begin(), ::tolower);
                if(unitTemp.compare("pawn") == 0) toMove = PAWN;
                else if(unitTemp.compare("bishop") == 0) toMove = BISHOP;
                else if(unitTemp.compare("knight") == 0) toMove = KNIGHT;
                else if((unitTemp.compare("rook") == 0) | (unitTemp.compare("tower") == 0)) toMove = ROOK;
                else if(unitTemp.compare("king") == 0) toMove = KING;
                else if(unitTemp.compare("queen") == 0) toMove = QUEEN;
                else {
                    bValid = false;
                    cout << "Please enter a valid piece name!"<<endl;
                    cout<<"(pawn,bishop,knight,rook,king,queen): ";
                }
            }
            bValid = false;
            while(!bValid)
            {
                bValid = true;
                cout<<"Where do you want to move? 'letternumber' (e4): ";
                cin>>unitTemp;
                transform(unitTemp.begin(), unitTemp.end(), unitTemp.begin(), ::tolower);
                // Parse letter and number to process here...

                if(unitTemp.length() > 2) {
                    cout<<"You entered an invalid destination!"<<endl;
                    bValid = false;
                }
                else {
                    cout<<endl<<"Attempting to move "<<turn<<" "<<toMove<<" to "<< unitTemp<<endl;

                    currentBoard = movePiece(currentBoard, 'g',4,'e',4);

                    DisplayBoard(currentBoard);

                    if(turn == WHITE) whiteScore+=10;
                    else blackScore+=10;
                }
            }

            //switch the turn
            if(turn == WHITE) turn = BLACK;
            else turn = WHITE;
        }
        else if(temp.compare("endgame")==0) {
            cout<<endl<<"------ GAME OVER ------"<<endl;
            cout<<"White Score: "<< whiteScore<<endl;
            cout<<"Black Score: "<< blackScore<<endl;
            cout<<endl<<"Would you like to start a new game? (yes/no): ";
            cin>>unitTemp;
            transform(unitTemp.begin(), unitTemp.end(), unitTemp.begin(), ::tolower);
            bValid = false;
            while(!bValid)
            {
                bValid = true;
                if(unitTemp.compare("yes") == 0) {
                    cout<<endl<<"Starting a new game..."<<endl;
                    currentBoard = DEFAULT_POSITION;
                    whiteScore = blackScore = 0;
                    turn = WHITE;
                    toMove="";
                    consolechess(DEFAULT_POSITION);
                    bExit = true;
                }
                else if (unitTemp.compare("no") == 0) bExit = true;
                else {
                    cout<<endl<<"Please Enter yes/no: ";
                    bValid = false;
                }
            }
        }
        else
        {
            cout<<endl<<"Invalid action entered!"<<endl;
        }
    }
}

int main()
{
    cout<<"Initializing Console Chess..."<<endl;

    consolechess(DEFAULT_POSITION);

    return 1;
}
