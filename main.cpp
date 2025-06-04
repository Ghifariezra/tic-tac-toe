#include <iostream>
using namespace std;

// Array untuk papan permainan
char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}};

int choice;
int row, column;
char turn = 'X';
bool draw = false;

void display_board()
{
    cout << "\n\tT I C K   --   T A C   --   T O E\n";
    cout << "\tPlayer 1 [X]  -  Player 2 [O]\n\n";

    cout << "\t     |     |     \n";
    cout << "\t  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "\n";
    cout << "\t_____|_____|_____\n";
    cout << "\t     |     |     \n";
    cout << "\t  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "\n";
    cout << "\t_____|_____|_____\n";
    cout << "\t     |     |     \n";
    cout << "\t  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "\n";
    cout << "\t     |     |     \n\n";
}

void player_turn()
{
    if (turn == 'X')
    {
        cout << "Player - 1 [X] turn : ";
    }
    else
    {
        cout << "Player - 2 [O] turn : ";
    }

    cin >> choice;

    switch (choice)
    {
    case 1:
        row = 0;
        column = 0;
        break;
    case 2:
        row = 0;
        column = 1;
        break;
    case 3:
        row = 0;
        column = 2;
        break;
    case 4:
        row = 1;
        column = 0;
        break;
    case 5:
        row = 1;
        column = 1;
        break;
    case 6:
        row = 1;
        column = 2;
        break;
    case 7:
        row = 2;
        column = 0;
        break;
    case 8:
        row = 2;
        column = 1;
        break;
    case 9:
        row = 2;
        column = 2;
        break;
    default:
        cout << "Invalid Move\n";
        player_turn(); // Minta input ulang
        return;
    }

    if (board[row][column] != 'X' && board[row][column] != 'O')
    {
        board[row][column] = turn;
        turn = (turn == 'X') ? 'O' : 'X';
    }
    else
    {
        cout << "Box already filled! Please choose another!\n";
        player_turn();
    }
    display_board();
}

bool gameover()
{
    // Cek kemenangan horizontal & vertikal
    for (int i = 0; i < 3; i++)
    {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i]))
        {
            return false;
        }
    }

    // Cek kemenangan diagonal
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
    {
        return false;
    }

    // Cek apakah masih ada kotak kosong
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return true;

    // Jika tidak ada kotak kosong dan tidak ada pemenang
    draw = true;
    return false;
}

int main()
{
    cout << "\tWelcome to Tic Tac Toe Game!\n";

    while (gameover())
    {
        display_board();
        player_turn();
    }

    display_board(); // tampilkan papan terakhir

    if (draw == false)
    {
        if (turn == 'O') // karena turn diganti setelah input
            cout << "\nCongratulations! Player with 'X' has won the game!\n";
        else
            cout << "\nCongratulations! Player with 'O' has won the game!\n";
    }
    else
    {
        cout << "\nGAME DRAW!\n";
    }

    return 0;
}
