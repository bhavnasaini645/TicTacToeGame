#include <iostream>
using namespace std;

char board[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

void displayBoard()
{
    cout << "\n";
    cout << "-------------\n";

    for(int i=0;i<3;i++)
    {
        cout << "| ";
        for(int j=0;j<3;j++)
        {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

bool checkWin(char player)
{
    // Rows
    for(int i=0;i<3;i++)
    {
        if(board[i][0]==player &&
           board[i][1]==player &&
           board[i][2]==player)
            return true;
    }

    // Columns
    for(int i=0;i<3;i++)
    {
        if(board[0][i]==player &&
           board[1][i]==player &&
           board[2][i]==player)
            return true;
    }

    // Diagonal
    if(board[0][0]==player &&
       board[1][1]==player &&
       board[2][2]==player)
       return true;

    if(board[0][2]==player &&
       board[1][1]==player &&
       board[2][0]==player)
       return true;

    return false;
}


bool checkDraw()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j]!='X' && board[i][j]!='O')
                return false;
        }
    }

    return true;
}


void resetBoard()
{
    char num='1';

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            board[i][j]=num++;
        }
    }
}


int main()
{
    char player;
    int choice;
    char playAgain;


    do
    {
        resetBoard();
        player='X';

        while(true)
        {
            displayBoard();

            cout<<"Player "<<player<<" enter position: ";
            cin>>choice;


            bool valid=false;

            for(int i=0;i<3;i++)
            {
                for(int j=0;j<3;j++)
                {
                    if(board[i][j]==choice+'0')
                    {
                        board[i][j]=player;
                        valid=true;
                    }
                }
            }


            if(!valid)
            {
                cout<<"Invalid Move! Try again\n";
                continue;
            }


            if(checkWin(player))
            {
                displayBoard();
                cout<<"Player "<<player<<" Wins!\n";
                break;
            }


            if(checkDraw())
            {
                displayBoard();
                cout<<"Match Draw!\n";
                break;
            }


            if(player=='X')
                player='O';
            else
                player='X';

        }


        cout<<"Play Again? (Y/N): ";
        cin>>playAgain;


    }while(playAgain=='Y'||playAgain=='y');


    cout<<"Thanks for playing!";

    return 0;
}