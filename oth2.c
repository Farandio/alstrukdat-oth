#include <stdio.h>

void koboImaginaryChess(int i, int j, int chessBoard[8][8]) {
    int moves[8][2] = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1},
                       {2, 1}, {1, 2}, {-1, 2}, {-2, 1}};

    for (int k = 0; k < 8; k++) {
        int newX = i + moves[k][0];
        int newY = j + moves[k][1];
        if (newX >= 0 && newX < 8 && newY >= 0 && newY < 8) {
            chessBoard[newX][newY] = 1;
        }
    }
}

void printChessBoard(int chessBoard[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%d ", chessBoard[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int i, j;
    scanf("%d %d", &i, &j);
    int chessBoard[8][8] = {{0}};
    koboImaginaryChess(i, j, chessBoard);
    printChessBoard(chessBoard);
    return 0;
}
