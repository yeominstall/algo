/**
 * swea 5653
 */
#include <iostream>

typedef struct cell {
    int alive = 0;  // no cell = 0, alive = 1, dead = -1
    int inact_time;
    int act_time;
    int gen_t;
} cell;
cell panel[351][351];

void clearPanel(void) {
    for (int i = 0; i < 351; i++) {
        for (int j = 0; j < 351; j++) {
            panel[i][j].alive = 0;
            panel[i][j].act_time = 0;
            panel[i][j].inact_time = 0;
        }
    }
}

void printPanel(void) {
    for (int i = 140; i < 160; i++) {
        std::cout << i << " ";
        for (int j = 140; j < 160; j++) {
            std::cout << panel[i][j].act_time;
        }
        std::cout << "\n";
    }
}

void spreadingCell(int from_x, int from_y, int to_x, int to_y, int tick) {
    if (panel[to_y][to_x].alive == 0 ||         // if to_cell is empty
    (panel[to_y][to_x].alive == 1 &&                                    // or to_cell is not empty 
    panel[to_y][to_x].gen_t == tick &&       // and to_cell is new
    panel[to_y][to_x].act_time < panel[from_y][from_x].act_time)) {     // and to_cell has lower act_time
        panel[to_y][to_x].alive = 1;
        panel[to_y][to_x].act_time = panel[from_y][from_x].act_time;
        panel[to_y][to_x].inact_time = panel[from_y][from_x].act_time;
        panel[to_y][to_x].gen_t = tick;
    }
}

int main (void) {
    int T, N, M, K, X, live_cell;
    // 1 <= N, M <= 50
    // 1 <= K <= 300
    // 1 <= cell's life <= 10

    std::cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // input each test case
        clearPanel();
        std::cin >> N >> M >> K;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                std::cin >> X;
                panel[150+i][150+j].act_time = X;
                panel[150+i][150+j].inact_time = X;
                panel[150+i][150+j].gen_t = 0;
                if (X != 0) {
                    panel[150+i][150+j].alive = 1;
                }
            }
        }

        // time ticking -- searching cells
        for (int t = 1; t <= K; t++) {
            for (int i = 0; i < 351; i++) {
                for (int j = 0; j < 351; j++) {
                    // if cell is not empty
                    if (panel[i][j].alive == 1) {
                        // and have no remaining inactive time
                        if (panel[i][j].inact_time == 0) {
                            if (panel[i][j].act_time > 0) {
                                // spreading -- up left right down
                                spreadingCell(j, i, j, i-1, t);
                                spreadingCell(j, i, j-1, i, t);
                                spreadingCell(j, i, j+1, i, t);
                                spreadingCell(j, i, j, i+1, t);
                                panel[i][j].act_time--;
                                if (panel[i][j].act_time == 0) {
                                    panel[i][j].alive = -1;
                                }
                            }
                        }
                        // or have remaining inactive time
                        else { //if (panel[i][j].inact_time > 0) {
                            // just reduce its inactive time
                            if (t != panel[i][j].gen_t) {
                                panel[i][j].inact_time--;
                            }
                        }
                    }
                }
            }
        }

        // calc live cell
        live_cell = 0;
        for (int i = 0; i < 351; i++) {
            for (int j = 0; j < 351; j++) {
                if (panel[i][j].alive == 1) {
                    live_cell++;
                }
            }
        }

        // print result
        std::cout << "#" << tc << " " << live_cell << "\n";
    }
    return 0;
}