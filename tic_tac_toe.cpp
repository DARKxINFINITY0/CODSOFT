#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class TicTacToe {
public:
    TicTacToe() : board(3, vector<char>(3, ' ')), currentPlayer('X') {}

    void displayBoard() {
       cout << "  0 1 2\n";
        for (int i = 0; i < 3; ++i) {
            cout << i << " ";
            for (int j = 0; j < 3; ++j) {
               cout << board[i][j];
                if (j < 2) cout << "|";
            }
            cout << "\n";
            if (i < 2) cout << "  -----\n";
        }
    }

    bool makeMove(int row, int col) {
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            return true;
        }
        return false;
    }

    bool checkWin() {
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
                return true;
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
                return true;
        }
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
            return true;
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
            return true;
        return false;
    }

    bool checkDraw() {
        for (const auto& row : board) {
            for (char cell : row) {
                if (cell == ' ') {
                    return false;
                }
            }
        }
        return true;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    char getCurrentPlayer() const {
        return currentPlayer;
    }

    void resetBoard() {
        board = vector<vector<char>>(3, vector<char>(3, ' '));
    }

private:
    vector<vector<char>> board;
    char currentPlayer;
};

int main() {
    TicTacToe game;
    char playAgain;

    do {
        game.resetBoard();
        bool gameWon = false;
        bool gameDraw = false;

        while (!gameWon && !gameDraw) {
            game.displayBoard();
            int row, col;
            cout << "Player " << game.getCurrentPlayer() << ", enter your move (row and column): ";
            cin >> row >> col;

            if (game.makeMove(row, col)) {
                gameWon = game.checkWin();
                if (!gameWon) {
                    gameDraw = game.checkDraw();
                    game.switchPlayer();
                }
            } else {
                cout << "Invalid move. Try again.\n";
            }
        }

        game.displayBoard();
        if (gameWon) {
            cout << "Player " << game.getCurrentPlayer() << " wins!\n";
        } else if (gameDraw) {
            cout << "The game is a draw!\n";
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
