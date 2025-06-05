#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class TicTacToe {
private:
    char board[3][3];
    char turn;
    stack<int> moveHistory;
    queue<string> giliran;

    void init_board() {
        char num = '1';
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                board[i][j] = num++;
        turn = 'X';
    }

    void display_board() {
        system("cls"); // "clear" jika di Linux
        cout << "\nTIC TAC TOE\nPlayer [X] vs Komputer [O]\n\n";
        for (int i = 0; i < 3; ++i) {
            cout << "     |     |     \n";
            cout << "  " << board[i][0] << "  |  " << board[i][1] << "  |  " << board[i][2] << "\n";
            if (i != 2) cout << "_____|_____|_____\n";
        }
        cout << "     |     |     \n\n";
    }

    bool is_valid_move(int choice, int &row, int &col) {
        if (choice < 1 || choice > 9) return false;
        row = (choice - 1) / 3;
        col = (choice - 1) % 3;
        return board[row][col] != 'X' && board[row][col] != 'O';
    }

    bool check_win() {
        for (int i = 0; i < 3; ++i)
            if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
                (board[0][i] == board[1][i] && board[1][i] == board[2][i]))
                return true;
        if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
            (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
            return true;
        return false;
    }

    bool is_draw() {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (board[i][j] != 'X' && board[i][j] != 'O')
                    return false;
        return true;
    }

    void player_turn() {
        int choice, row, col;
        while (true) {
            cout << "Player [X] Masukkan posisi (1-9): ";
            cin >> choice;
            if (is_valid_move(choice, row, col)) {
                board[row][col] = 'X';
                moveHistory.push(choice);
                break;
            } else {
                cout << "Langkah tidak valid. Ulangi.\n";
            }
        }
    }

    void ai_turn() {
        // Rule-based AI: ambil langkah pertama yang kosong
        for (int i = 1; i <= 9; ++i) {
            int row, col;
            if (is_valid_move(i, row, col)) {
                board[row][col] = 'O';
                moveHistory.push(i);
                break;
            }
        }
    }

public:
    void play() {
        init_board();
        giliran.push("Player");
        giliran.push("AI");

        while (true) {
            display_board();
            string current = giliran.front();
            giliran.pop();

            if (current == "Player") {
                player_turn();
            } else {
                cout << "Komputer berpikir...\n";
                ai_turn();
            }

            if (check_win()) {
                display_board();
                cout << "Pemenang: " << current << endl;
                break;
            } else if (is_draw()) {
                display_board();
                cout << "Permainan Seri!\n";
                break;
            }

            giliran.push(current); // Masukkan giliran kembali
        }

        // Tampilkan urutan langkah
        cout << "\nHistory Langkah (Stack): ";
        vector<int> history;
        while (!moveHistory.empty()) {
            history.push_back(moveHistory.top());
            moveHistory.pop();
        }
        reverse(history.begin(), history.end());
        for (int step : history) cout << step << " ";
        cout << endl;
    }
};

int main() {
    TicTacToe game;
    game.play();
    return 0;
}
