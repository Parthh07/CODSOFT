#include <iostream>
using namespace std;

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char current_marker;
int current_player;

void drawBoard() {
    system("cls"); 
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

bool placeMarker(int slot) {
    int row = slot / 3;
    int col = slot % 3;
    if (slot % 3 == 0) {
        row = row - 1;
        col = 2;
    } else {
        col = col - 1;
    }

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = current_marker;
        return true;
    } else {
        return false;
    }
}

int checkWin() {
    
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return current_player;
    }
    
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return current_player;
    }
    
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return current_player;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return current_player;

    return 0;
}

bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }
    return true;
}

void swapPlayerAndMarker() {
    if (current_marker == 'X')
        current_marker = 'O';
    else
        current_marker = 'X';

    if (current_player == 1)
        current_player = 2;
    else
        current_player = 1;
}

void resetBoard() {
    char resetBoard[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
    memcpy(board, resetBoard, 3 * 3 * sizeof(char));
}

void game() {
    cout << "Player one, choose your marker (X or O): ";
    char marker_p1;
    cin >> marker_p1;

    current_player = 1;
    current_marker = marker_p1;

    drawBoard();

    int player_won = 0;

    while (true) {
        cout << "It's player " << current_player << "'s turn. Enter your slot: ";
        int slot;
        cin >> slot;

        if (slot < 1 || slot > 9) {
            cout << "Invalid slot! Try another slot!" << endl;
            continue;
        }

        if (!placeMarker(slot)) {
            cout << "Slot occupied! Try another slot!" << endl;
            continue;
        }

        drawBoard();

        player_won = checkWin();

        if (player_won != 0) {
            cout << "Player " << player_won << " won! Congratulations!" << endl;
            break;
        }

        if (checkDraw()) {
            cout << "That's a draw game!" << endl;
            break;
        }

        swapPlayerAndMarker();
    }
}

int main() {
    char play_again;
    do {
        resetBoard();
        game();
        cout << "Do you want to play again? (y/n): ";
        cin >> play_again;
    } while (play_again == 'y');

    return 0;
}
