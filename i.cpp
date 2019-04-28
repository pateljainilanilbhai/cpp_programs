#include <iostream>



// This program allows user(s) to play a game of tic-tac-toe.


using namespace std;

// constants
const char SIGIL[3] = { '.', 'X', 'O' };

// prototypes
int winner(int board[3][3]);
void drawBoard(int board[3][3]);
bool isMoveLegal(int board[3][3]);
bool isGameOver(int board[3][3]);



// return 1 if player 1 'X' has won
// return 2 if player 2 'O' has won
// return 0 if neither player has won
int winner(int board[3][3]){
    int win = 0;

    // Checks for:
    //     X X X
    for (int i = 0; i < 3; i++)
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            win = board[i][0];

    // Checks for:
    // X
    // X
    // X
    for (int i = 0; i < 3; i++)
    if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
        win = board[0][i];

    // Checks for:
    // X                 X
    //   X      or     X
    //     X         X
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
        win = board[1][1];

    return win;
}


// using this board as a guide
// draw the board using "." for empty squares
// or 'X' or 'O' for player 1 or player 2
void drawBoard(int board[3][3]){

cout << "   0  1  2" << endl;
for (int i = 0; i < 3; i++){
    cout << i ;


    for (int j = 0; j < 3; j++){
        cout.width(3);
        switch (board[i][j])
        {
        case 0:{
                   cout << ".";
        }break; case 1:{
                   cout << "X";
        }break;
        case 2:{
                   cout << "0";
        }break;
        default:
            break;
        }
    } cout << endl;
}


}


// return false if row or column are out of bounds
// or if that spot on the board is already taken
// otherwise return true
bool isMoveLegal(int board[3][3], int row, int column){
if (row >= 0 && row <= 3 && column <= 3 && column >= 0)     {
    if (board[row][column] == 0)
        return true;
    else return false;
}
return false;
}


// if any player has three in a row or if the board is full
// return true otherwise return false
bool isGameOver(int board[3][3]){
    if (winner(board) == 1 || winner(board) == 2) return true;
    for (int r = 0; r <= 2; r++)
    for (int c = 0; c <= 2; c++)
    if (board[r][c] == 0)
        return false;
    return true;
}


int main(){
int board[3][3] = { { 0 } }; // 0 for empty square, 1 or 2 for taken squares
int player = 1;
int row, column, result;
bool legalMove;

// starting board
drawBoard(board);
while (!isGameOver(board)){
    cout << "Player " << player << "(" << SIGIL[player] << "), your move?";
    cin >> row >> column;
    legalMove = isMoveLegal(board, row, column);
    while (!legalMove){
        cout << "Player " << player << "(" << SIGIL[player] << "), your move?";
        cin >> row >> column;
        legalMove = isMoveLegal(board, row, column);
    }
    board[row][column] = player;
    drawBoard(board);
    player = 3 - player;
}
// game over
result = winner(board);
if (result == 0){
    cout << "Tie Game" << endl;
}
else {
    cout << "Player " << result << "(" << SIGIL[result] << ") wins!" << endl;
}

return 0;
}
