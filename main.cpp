#include <iostream>
#include <cstdlib> // Add this for system()
using namespace std;

class TicTacToe {
private:
    char board[3][3];
    char turn;
    bool draw;

    void init_board() {
        char num = '1';
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                board[i][j] = num++;
    }

    void display_board() const {
        // Clear screen before displaying the board
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        cout << "\n\tT I C K   --   T A C   --   T O E\n";
        cout << "\tPlayer 1 [X]  -  Player 2 [O]\n\n";
        for (int i = 0; i < 3; ++i) {
            cout << "\t     |     |     \n";
            cout << "\t  " << board[i][0] << "  |  " << board[i][1] << "  |  " << board[i][2] << "\n";
            if (i != 2) cout << "\t_____|_____|_____\n";
        }
        cout << "\t     |     |     \n\n";
    }

    bool is_valid_move(int choice, int &row, int &col) const {
        if (choice < 1 || choice > 9) return false;
        row = (choice - 1) / 3;
        col = (choice - 1) % 3;
        return board[row][col] != 'X' && board[row][col] != 'O';
    }

    void player_turn() {
        int choice, row, col;
        while (true) {
            cout << "Player - " << (turn == 'X' ? "1 [X]" : "2 [O]") << " turn : ";
            cin >> choice;
            if (is_valid_move(choice, row, col)) {
                board[row][col] = turn;
                turn = (turn == 'X') ? 'O' : 'X';
                break;
            } else {
                cout << "Invalid move! Try again.\n";
            }
        }
    }

    bool check_win() const {
        // Rows, columns, diagonals
        for (int i = 0; i < 3; ++i)
            if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
                (board[0][i] == board[1][i] && board[1][i] == board[2][i]))
                return true;
        if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
            (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
            return true;
        return false;
    }

    bool is_draw() const {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (board[i][j] != 'X' && board[i][j] != 'O')
                    return false;
        return true;
    }

public:
    TicTacToe() : turn('X'), draw(false) {
        init_board();
    }

    void play() {
        cout << "\tWelcome to Tic Tac Toe Game!\n";
        display_board();
        while (true) {
            player_turn();
            display_board();
            if (check_win()) {
                cout << "\nCongratulations! Player with '" << (turn == 'O' ? 'X' : 'O') << "' has won the game!\n";
                break;
            }
            if (is_draw()) {
                cout << "\nGAME DRAW!\n";
                break;
            }
        }
    }
};

int main() {
    TicTacToe game;
    game.play();
    return 0;
}
