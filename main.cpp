//// Author: khaled Alrashdi
#include <iostream>

using namespace std;


//GLOBAL CONSTANTS

const int ROWS = 3;

const int COLUMNS = 3;

const char BLANK = ' ';

const char X = 'X';

const char O = 'O';

const int QUIT = -1;


int main()

{

//3x3 matrix of characters, initially with blank spaces in each position

char board[ROWS][COLUMNS] = {{BLANK, BLANK, BLANK},

{BLANK, BLANK, BLANK},

{BLANK, BLANK, BLANK}};


char turn = X; //Player X always goes first

int row;

int column;

bool playing = true; //Continue playing by default

char winner = ' ';

bool won = false;

do

{

cout<<turn<<"'s turn.\n";

cout<<"Which column and row (0-2, or -1 for both to quit)?\n";

cin>>column;

cin>>row;


//Make sure the user isn't quitting

if(column == QUIT && row == QUIT)

{

playing = false;

}

//Print error if the column and/or row is out of bounds of 0-2

else if( column < 0 || row < 0 || column > 2 || row > 2 )

{

cout<<"Values must be between 0 and 2.\n";

}

else

{

board[row][column]=turn;

if(turn==X)

{

turn=O;

} 

else

{

turn=X;

}

}

cout<<"\nBOARD\n-----\n";

cout<<board[0][0]<<" "<<board[0][1]<<" "<<board[0][2]<<" "<<endl;

cout<<board[1][0]<<" "<<board[1][1]<<" "<<board[1][2]<<" "<<endl;

cout<<board[2][0]<<" "<<board[2][1]<<" "<<board[2][2]<<" "<<endl;


// for (int r = 0; r<2; r++)

// {

// for (int c = 0; c<2; c++)

// {


for (int i = 0; i<2; i++)

{

if ((board[i][0]!=BLANK)&&(board[i][1]!=BLANK)&&(board[i][2]!=BLANK)&&(board[i][0]==board[i][1])&&(board[i][0]==board[i][2]))

{

playing = false;

won = true;

winner = board[i][0];

// cout<<"Win condition 1"<<endl;

}

if ((board[0][i]!=BLANK)&&(board[1][i]!=BLANK)&&(board[2][i]!=BLANK)&&(board[0][i]==board[1][i])&&(board[0][i]==board[2][i]))

{

playing = false;

won = true;

winner = board[0][i];

// cout<<"Win Condition 2"<<endl;

} 

}

if (board[1][1]!=BLANK&&((board[1][1]==board[0][0]&&board[1][1]==board[2][2])||(board[1][1]==board[0][2]&&board[1][1]==board[2][0])))

{

playing = false;

won = true;

winner = board[1][1];

// cout<<"Win Condition 3"<<endl;

}


}while( playing );

if (won == true)

{

cout<<"Winner is "<<winner<<endl;

}

cout<<"Goodbye!\n";

return 0;

}
