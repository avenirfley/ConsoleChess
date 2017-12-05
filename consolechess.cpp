#include <iostream>
#include <string>
#include <fstream>
#include <array>
#include <algorithm>

using namespace std;

int main()
{
    cout<<"Initializing Console Chess..."<<endl;
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

    array<char*, 4> DEFAULT_POSITION = {"rnbqkbnr","pppppppp", "PPPPPPPP","RNBQKBNR"};

    for(int i = 0; i<4;i++)
    {
        cout<<"| ";
        for(int j=0;j<8;j++)
        {
            cout<<" "<<DEFAULT_POSITION[i][j]<<" ";
        }
        cout<<"|"<<endl;
        if(i==1)
        {
            for(int k=0;k<4;k++)
            {
                cout<<"| ";
                for(int l=0;l<8;l++)
                {
                    cout<<"[]"<<" ";
                }
                cout<<"|"<<endl;
            }
        }
    }

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
                else if(unitTemp.compare("rook") == 0 | unitTemp.compare("tower") == 0) toMove = ROOK;
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
                else cout<<endl<<"Attempting to move "<<turn<<" "<<toMove<<" to "<< unitTemp<<endl;
            }
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
                    cout<<endl<<"Starting a new game, not yet implemented..."<<endl;
                    bExit = true;
                }
                else if (unitTemp.compare("no") == 0) bExit = true;
                else {
                    cout<<endl<<"Please Enter yes/no: ";
                    bValid = false;
                }
            }
        }

        //switch the turn
        if(turn == WHITE) turn = BLACK;
        else turn = WHITE;
    }

    return 1;
}
