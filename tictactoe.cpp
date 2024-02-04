#include <iostream>
using namespace std;

// Function to draw the game board
void drawBoard(char board[]) {
    cout << endl;
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;
}

// Function to check if the game is over
int isGameOver(char board[]) {
    // Check if any row has all X's or all O's
    if ((board[0] == board[1] && board[1] == board[2]) ||
        (board[3] == board[4] && board[4] == board[5]) ||
        (board[6] == board[7] && board[7] == board[8])) {
        return 1;
    }
    // Check if any column has all X's or all O's
    if ((board[0] == board[3] && board[3] == board[6]) ||
        (board[1] == board[4] && board[4] == board[7]) ||
        (board[2] == board[5] && board[5] == board[8])) {
        return 1;
    }
    // Check if any diagonal has all X's or all O's
    if ((board[0] == board[4] && board[4] == board[8]) ||
        (board[2] == board[4] && board[4] == board[6])) {
        return 1;
    }
    // Check if the game is a tie
    for (int i = 0; i < 9; i++) {
        if (board[i] != 'X' && board[i] != 'O') {
            return 0;
        }
    }
    return 2;
}

int main() {
    // Initialize the game board
    char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

    // Initialize variables for player turn and game status
    int player = 1;
    int status = 0;
    char move;

    // Loop until the game is over
    while (status == 0) {
        // Draw the game board
        drawBoard(board);

        // Get the player's move
        cout << endl << "Player " << player << "'s turn (Enter a number 1-9): ";
        cin >> move;

        // Update the game board
        if (board[move - '1'] != 'X' && board[move - '1'] != 'O') {
            if (player == 1) {
                board[move - '1'] = 'X';
                player = 2;
            } else {
                board[move - '1'] = 'O';
                player = 1;
            }
        }

        // Check if the game is over
        status = isGameOver(board);
    }

    // Draw the final game board
    drawBoard(board);

    // Print the game outcome
    if (status == 1) {
        cout << endl << "Player " << player << " wins!" << endl;
        } else {
        cout << endl << "It's a tie!" << endl;
    }
}
