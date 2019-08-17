/**
 * boj 1018
 */
#include <iostream>

char board[50][50];

void initBoard(void) {
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            board[i][j] = '\0';
        }
    }
}

int main (void) {
    int N, M, min = 65;
    std::string ip;
    std::cin >> N >> M;
    initBoard();
    for (int i = 0; i < N; i++) {
        std::cin >> ip;
        for (int j = 0; j < M; j++) {
            board[i][j] = ip.at(j);
        } 
    }

    int count;
    for (int i = 0; i < N - 7; i++) {
        for (int j = 0; j < M - 7; j++) {
            char block = 'B';
            count = 0;
            for (int y = 0; y < 8; y++) {
                for (int x = 0; x < 8; x++) {
                    if (board[i+y][j+x] != block) {
                        count++;
                    }
                    block = block == 'B' ? 'W' : 'B';
                }
                block = block == 'B' ? 'W' : 'B';
            }
            min = count < min ? count : min;
            count = 0;
            block = 'W';
            for (int y = 0; y < 8; y++) {
                for (int x = 0; x < 8; x++) {
                    if (board[i+y][j+x] != block) {
                        count++;
                    }
                    block = block == 'B' ? 'W' : 'B';
                }
                block = block == 'B' ? 'W' : 'B';
            }
            min = count < min ? count : min;
        }
    }

    std::cout << min << "\n";

}