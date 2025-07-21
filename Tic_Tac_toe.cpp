#include<iostream>

using namespace std;

void printBoard(char array[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

bool checkWin(char array[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if (array[i][0] == player && array[i][1] == player && array[i][2] == player) {
            cout << "Player " << player << " wins!" << endl;
            return true;
        }
    }
    for (int j = 0; j < 3; j++) {
        if (array[0][j] == player && array[1][j] == player && array[2][j] == player) {
            cout << "Player " << player << " wins!" << endl;
            return true;
        }
    }
    if (array[0][0] == player && array[1][1] == player && array[2][2] == player) {
        cout << "Player " << player << " wins!" << endl;
        return true;
    }
    if (array[0][2] == player && array[1][1] == player && array[2][0] == player) {
        cout << "Player " << player << " wins!" << endl;
        return true;
    }

    return false;
}

int main() {
    char array[3][3] = {{'*', '*', '*'}, {'*', '*', '*'}, {'*', '*', '*'}};
    int r, c;

    printBoard(array);

    for (int turn = 1; turn <= 9; turn++) {
        char player = (turn % 2 == 1) ? 'X' : 'O';
        cout << "Player " << player << ", enter row and column (from 0,1,2): ";
        cin >> r >> c;

        if (r < 0 || r >= 3 || c < 0 || c >= 3 || array[r][c] != '*') {
            cout << "Invalid move! Try again." << endl;
            turn--;
            continue;
        }

        array[r][c] = player;

        printBoard(array);

        if (checkWin(array, player)) {
            cout << "Game Over!" << endl;
            return 0;
        }
    }

    cout << "It's a draw!" << endl;

    return 0;
}