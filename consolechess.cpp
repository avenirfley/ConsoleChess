#include <iostream>
#include <string>
#include <fstream>
#include <array>

using namespace std;

int main()
{
    cout<<"Initializing Console Chess..."<<endl;
    char BLACK = 'b';
    char WHITE = 'w';

    char EMPTY = -1;

    char PAWN = 'p';
    char KNIGHT = 'n';
    char BISHOP = 'b';
    char ROOK = 'r';
    char QUEEN = 'q';
    char KING = 'k';

    char * board = new char[64];

    char turn = WHITE;

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
                    cout<<"-1"<<" ";
                }
                cout<<"|"<<endl;
            }
        }
    }

    bool bExit = false;

    enum Actions {Exit, Move, EndGame};
    string temp;
    Actions action;

    while(!bExit)
    {
        cout<<"What would you like to do? ('exit', 'move')"<<endl;
        cin>>temp;
        if(temp.compare("exit") == 0)action = Exit;
        else if(temp.compare("move") == 0)action = Move;
        switch(action)
        {
        case Exit:
            bExit = true;
            break;
        case Move:
            cout<<"What piece do you want to move?"<<endl;
            break;
        }
    }

    return 1;
}
