#include <iostream>
#include <thread> // this_thread, sleep_for()
#include <chrono>  // milliseconds

using namespace std;

//variables
char gameBoard[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};

int start;
int gamemode;

char turn = 'X';
int choice;
int row, column;

//print functions
void printBoard()
{
    cout<<"\t     |     |     \n";
    cout<<"\t  " << gameBoard[0][0] <<"  |  "<<gameBoard[0][1]<<"  |  "<< gameBoard[0][2]<<" \n";
    cout<<"\t_____|_____|_____\n";
    cout<<"\t     |     |     \n";
    cout<<"\t  "<< gameBoard[1][0]<<"  |  "<<gameBoard[1][1]<<"  |  "<<gameBoard[1][2]<<" \n";
    cout<<"\t_____|_____|_____\n";
    cout<<"\t     |     |     \n";
    cout<<"\t  "<<gameBoard[2][0]<<"  |  "<<gameBoard[2][1]<<"  |  "<<gameBoard[2][2]<<" \n";
    cout<<"\t     |     |     \n";
}

void makeSpaces(int numSpaces)
{
    for (int i = 0; i <= numSpaces ; i++)
    {
      cout << "\n";
    }
}

void gameStart()
{
  cout << "\033[2J\033[0;0H"; // clears screen idk how 
  cout << "AI or 2 players?:\n";
  cout << "1. AI (Press 1)\n";
  cout << "2. 2 players(Press 2)\n";
}

//game funcs

void playerTurn(int gamemode)
{

  switch (gamemode)
  {
    case 1:
      if (turn == 'X')
      {
        cout << "Player's turn [X]: ";
      }
      else if (turn == 'O')
      {
        cout << "Computer's turn [O]: ";
      }
      break;
    case 2:
      if (turn == 'X')
      {
        cout << "Player_1's turn [X]: ";
      }
        else if (turn == 'O')
      {
        cout << "Player_2's turn [O]: ";
      }
      break;
  }

  cin >> choice;
  
  switch(choice)
  {
    case 1: row=0; column=0; break;
    case 2: row=0; column=1; break;
    case 3: row=0; column=2; break;
    case 4: row=1; column=0; break;
    case 5: row=1; column=1; break;
    case 6: row=1; column=2; break;
    case 7: row=2; column=0; break;
    case 8: row=2; column=1; break;
    case 9: row=2; column=2; break;
    default:
      cout<<"Invalid Move";
  }



  if (turn == 'X' && gameBoard[row][column] != 'X' && gameBoard[row][column] != 'O')
  {
    gameBoard[row][column] = 'X';
    turn = 'O';
    
  }
  else if (turn == 'O' && gameBoard[row][column] != 'X' && gameBoard[row][column] != 'O')
  {
    gameBoard[row][column] = 'O';
    turn = 'X';
    
  }
  else
  {
    cout << "Box already filled up, pick a different box.\n";

    switch (gamemode)
    {
      case 1:
      playerTurn(1);
      break;
      case 2:
      playerTurn(2);
      break;
      
    }
  }
  
  printBoard();
  
}

bool playerWin()
{
  for (int i = 0; i < 3; i++)
  {
    //column n row wins
    if (gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][0] == gameBoard[i][2] || gameBoard[0][i] == gameBoard[1][i] && gameBoard[0][i] == gameBoard[2][i])
    {
     return false;
    }


    if (gameBoard[0][0] == gameBoard[1][1] && gameBoard[0][0] == gameBoard[2][2] || gameBoard[0][2] == gameBoard[1][1] && gameBoard[0][2] == gameBoard[2][0])
    {
      return false;
    }
  }
  return true;
}

int main() {
  cout << "W E L C O M E --- T O --- T I C --- T A C --- T O E --- !\n";
  makeSpaces(5);
  cout << "---------------------Press 1 to Start-------------------\n";
  cin >> start;

  switch (start)
  {
    case 1: gameStart();
  }

  cin >> gamemode;
  cout << "\033[2J\033[0;0H"; // clears screen idk how
  
  switch (gamemode) 
  {
    case 1:

      while(playerWin())
      {
        cout << "\033[2J\033[0;0H"; // clears screen idk how
        cout << "P L A Y E R [X] --- VS. --- C O M P U T E R [O]\n";
        makeSpaces(3);
        printBoard();
        makeSpaces(3);
        playerTurn(1);
        playerWin();
      }
      break;
    
    case 2:
     
      while (playerWin())
      {
        cout << "\033[2J\033[0;0H"; // clears screen idk how
        cout << "P L A Y E R _ 1 [X] --- VS. --- P L A Y E R _ 2 [O]\n";
        makeSpaces(3);
        printBoard();
        makeSpaces(3);
        playerTurn(2);
        playerWin();
      }


      
      break;
    
    default:
      cout << "Not a valid choice, pick again.\n";
      gameStart();
      cin >> gamemode;
      break;

    return 0;
    
  }
}
