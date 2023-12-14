// tic_tac_toe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

#include <iostream>
#include <windows.h>

using namespace std;

//gamemode classes
class TwoPlayers
{
public:
    char gameBoard[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };

    char turn = 'X';
    int choice;
    int row, column;
    int count = 0;

    //print funcs
    void makeSpaces(int numSpaces)
    {
        for (int i = 0; i <= numSpaces; i++)
        {
            cout << "\n";
        }
    }

    void printBoard()
    {

        cout << "\t     |     |     \n";
        cout << "\t  " << gameBoard[0][0] << "  |  " << gameBoard[0][1] << "  |  " << gameBoard[0][2] << " \n";
        cout << "\t_____|_____|_____\n";
        cout << "\t     |     |     \n";
        cout << "\t  " << gameBoard[1][0] << "  |  " << gameBoard[1][1] << "  |  " << gameBoard[1][2] << " \n";
        cout << "\t_____|_____|_____\n";
        cout << "\t     |     |     \n";
        cout << "\t  " << gameBoard[2][0] << "  |  " << gameBoard[2][1] << "  |  " << gameBoard[2][2] << " \n";
        cout << "\t     |     |     \n";

    }
    //game funcs
    void playerTurn()
    {
        if (turn == 'X')
        {
            cout << "Player 1's turn [X]: ";
        }
        else if (turn == 'O')
        {
            cout << "Player 2's turn [O]: ";
        }

        cin >> choice;
        
        switch (choice)
        {
        case 1: row = 0; column = 0; break;
        case 2: row = 0; column = 1; break;
        case 3: row = 0; column = 2; break;
        case 4: row = 1; column = 0; break;
        case 5: row = 1; column = 1; break;
        case 6: row = 1; column = 2; break;
        case 7: row = 2; column = 0; break;
        case 8: row = 2; column = 1; break;
        case 9: row = 2; column = 2; break;

        default:
            cout << "Invalid Move";
        }

        if (turn == 'X' && gameBoard[row][column] != 'X' && gameBoard[row][column] != 'O')
        {
            gameBoard[row][column] = 'X';
            turn = 'O';
            count += 1;
            cout << count;
            
        }
        else if (turn == 'O' && gameBoard[row][column] != 'X' && gameBoard[row][column] != 'O')
        {
            gameBoard[row][column] = 'O';
            turn = 'X';
            count += 1;
            cout << count;

            
        }
        else
        {
            cout << "Box already filled up, pick a different box.\n";   
            if (turn == 'X')
            {
                cout << "Player 1's turn [X]: ";
            }
            else if (turn == 'O')
            {
                cout << "Player 2's turn [O]: ";
            }
            cin >> choice;
        }

    }



    int playerWin()
    {

        for (int i = 0; i < 3; i++)
        {
            //column n row wins
            if (gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][0] == gameBoard[i][2] || gameBoard[0][i] == gameBoard[1][i] && gameBoard[0][i] == gameBoard[2][i])
            {

                //playerturn immediatly changes turn = X -> turn = 0
                if (turn == 'X') {
                    return 2;
                
                }
                else {
                    return 1;
                    
                }
                   
            }

            //diagonal wins
            if (gameBoard[0][0] == gameBoard[1][1] && gameBoard[0][0] == gameBoard[2][2] || gameBoard[0][2] == gameBoard[1][1] && gameBoard[0][2] == gameBoard[2][0])
            {
                if (turn == 'X') {
                    return 2;
                
                }
                else {
                    return 1;
                    
                }

            }



        }
            
        //checks for draw
        if (count == 9) {
            return 3;
        }

        return 4;
    }

    void winnerDecl(int winner) {
        //true = player 1 wins, false = player 2 wins

        string declaration;

        if (winner == 1) {
            declaration = "PLAYER 1 [X] WINS!";
        }
        else if (winner == 2) {
            declaration = "PLAYER 2 [0] WINS!";
        }
        else if (winner == 3) {
            declaration = "       DRAW";
        }

        // clears screen idk how
        cout << "\033[2J\033[0;0H"; 
        cout << "-------------------------------------------------\n";
        makeSpaces(3);
        cout << "                " << declaration << "\n";
        cout << "                   GAME OVER                     \n";
        makeSpaces(4);
        cout << "-------------------------------------------------\n";
        
    }
};

//class ComputerPlayer
//{
//public:
//    char gameBoard[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
//
//    char turn = 'X';
//    int choice;
//    int row, column;
//
//    //print funcs
//    void makeSpaces(int numSpaces)
//    {
//        for (int i = 0; i <= numSpaces; i++)
//        {
//            cout << "\n";
//        }
//    }
//
//    void printBoard()
//    {
//
//        cout << "\t     |     |     \n";
//        cout << "\t  " << gameBoard[0][0] << "  |  " << gameBoard[0][1] << "  |  " << gameBoard[0][2] << " \n";
//        cout << "\t_____|_____|_____\n";
//        cout << "\t     |     |     \n";
//        cout << "\t  " << gameBoard[1][0] << "  |  " << gameBoard[1][1] << "  |  " << gameBoard[1][2] << " \n";
//        cout << "\t_____|_____|_____\n";
//        cout << "\t     |     |     \n";
//        cout << "\t  " << gameBoard[2][0] << "  |  " << gameBoard[2][1] << "  |  " << gameBoard[2][2] << " \n";
//        cout << "\t     |     |     \n";
//
//    }
//
//    void playerTurn()
//    {
//        cout << "Player's turn [X]: ";
//
//        cin >> choice;
//
//        switch (choice)
//        {
//        case 1: row = 0; column = 0; break;
//        case 2: row = 0; column = 1; break;
//        case 3: row = 0; column = 2; break;
//        case 4: row = 1; column = 0; break;
//        case 5: row = 1; column = 1; break;
//        case 6: row = 1; column = 2; break;
//        case 7: row = 2; column = 0; break;
//        case 8: row = 2; column = 1; break;
//        case 9: row = 2; column = 2; break;
//
//        default:
//            cout << "Invalid Move";
//
//        
//    }
//
//};

//print functions
void makeSpaces(int numSpaces)
{
    for (int i = 0; i <= numSpaces; i++)
    {
        cout << "\n";
    }
}

//game funcs
//void playerTurn(int gamemode)
//{
//    switch (gamemode)
//    {
//    case 1:
//        
//        if (turn == 'X')
//        {
//            cout << "Player's turn [X]: ";
//        }
//        else if (turn == 'O')
//        {
//            cout << "Computer's turn [O]: ";
//        }
//        break;
//    case 2:
//        
//        if (turn == 'X')
//        {
//            cout << "Player_1's turn [X]: ";
//        }
//        else if (turn == 'O')
//        {
//            cout << "Player_2's turn [O]: ";
//        }
//        break;
//    }
//
//    cin >> choice;
//
//    switch (choice)
//    {
//    case 1: row = 0; column = 0; break;
//    case 2: row = 0; column = 1; break;
//    case 3: row = 0; column = 2; break;
//    case 4: row = 1; column = 0; break;
//    case 5: row = 1; column = 1; break;
//    case 6: row = 1; column = 2; break;
//    case 7: row = 2; column = 0; break;
//    case 8: row = 2; column = 1; break;
//    case 9: row = 2; column = 2; break;
//    default:
//        cout << "Invalid Move";
//    }
//
//
//
//    if (turn == 'X' && gameBoard[row][column] != 'X' && gameBoard[row][column] != 'O')
//    {
//        gameBoard[row][column] = 'X';
//        turn = 'O';
//
//    }
//    else if (turn == 'O' && gameBoard[row][column] != 'X' && gameBoard[row][column] != 'O')
//    {
//        gameBoard[row][column] = 'O';
//        turn = 'X';
//
//    }
//    else
//    {
//        cout << "Box already filled up, pick a different box.\n";
//
//        switch (gamemode)
//        {
//        case 1:
//            playerTurn(1);
//            break;
//        case 2:
//            playerTurn(2);
//            break;
//
//        }
//    }
//
//    printBoard();
//
//}


int main() {
    int start;
    int gamemode;
    TwoPlayers twoplayers;

    cout << "W E L C O M E --- T O --- T I C --- T A C --- T O E --- !\n";
    makeSpaces(5);
    cout << "---------------------Press 1 to Start-------------------\n";
    cin >> start;

    //Start Screen
    switch (start)
    {
     case 1: 
        cout << "\033[2J\033[0;0H"; // clears screen idk how 
        cout << "AI or 2 players?:\n";
        cout << "1. AI (Press 1)\n";
        cout << "2. 2 players(Press 2)\n";
        break;
    }

    cin >> gamemode;
    cout << "\033[2J\033[0;0H"; // clears screen idk how


    //Game Start
    switch (gamemode)
    {
    case 1: //AI

        //while (true)
        //{
        //    cout << "\033[2J\033[0;0H"; // clears screen idk how
        //    cout << "P L A Y E R [X] --- VS. --- C O M P U T E R [O]\n";
        //    makeSpaces(3);
        //    //printBoard();
        //    makeSpaces(3);
        //    //playerTurn(1);
        //    playerWin();
        //}

        break;

    case 2: //TwoPlayer


        while (true)
        {
            //set ups board
            cout << "\033[2J\033[0;0H"; // clears screen idk how
            cout << "P L A Y E R _ 1 [X] --- VS. --- P L A Y E R _ 2 [O]\n";
            twoplayers.makeSpaces(3);
            twoplayers.printBoard();
            twoplayers.makeSpaces(3);

            //runs game
            twoplayers.playerTurn();

            if (twoplayers.playerWin() == 1)
            {
                twoplayers.winnerDecl(1);
                break;
            }
            else if (twoplayers.playerWin() == 2) {
                twoplayers.winnerDecl(2);
                break;
            } 
            else if (twoplayers.playerWin() == 3) {
                twoplayers.winnerDecl(3);
                break;
            }
            else {
                continue;
            }

        }
        break;

    default:
        cout << "Not a valid choice, pick again.\n";
        cout << "AI or 2 players?:\n";
        cout << "1. AI (Press 1)\n";
        cout << "2. 2 players(Press 2)\n";
        cin >> gamemode;
        break;

    }

    return 0;
}


