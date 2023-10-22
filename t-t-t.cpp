#include <iostream>
#include <vector>

const int BOARD_SIZE = 3;

std::vector<std::vector<char>> board(BOARD_SIZE, std::vector<char>(BOARD_SIZE, ' '));

void printBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            std::cout << board[i][j];
            if (j < BOARD_SIZE - 1) {
                std::cout << " | ";
            }
        }
        std::cout << std::endl;
        if (i < BOARD_SIZE - 1) {
            std::cout << "---------" << std::endl;
        }
    }
    std::cout << std::endl;
}

bool isMoveValid(int row, int col) {
    return row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == ' ';
}

bool isGameOver(char player) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;  // Horizontal win
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;  // Vertical win
        }
    }

    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;  // Diagonal win (top-left to bottom-right)
    }

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;  // Diagonal win (top-right to bottom-left)
    }

    return false;
}

int main() {
    char currentPlayer = 'X';
    int moves = 0;

    std::cout << "Welcome to Tic-Tac-Toe!" << std::endl;

    while (moves < BOARD_SIZE * BOARD_SIZE) {
        std::cout << "Current board:" << std::endl;
        printBoard();

        int row, col;
        do {
            std::cout << "Player " << currentPlayer << ", enter your move (row and column, e.g., 1 2): ";
            std::cin >> row >> col;
        } while (!isMoveValid(row - 1, col - 1));

        board[row - 1][col - 1] = currentPlayer;
        moves++;

        if (isGameOver(currentPlayer)) {
            std::cout << "Player " << currentPlayer << " wins!" << std::endl;
            printBoard();
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    if (moves == BOARD_SIZE * BOARD_SIZE) {
        std::cout << "It's a draw! The game is over." << std::endl;
        printBoard();
    }

    return 0;
}
