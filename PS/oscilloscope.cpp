#include <iostream>
#include <iomanip>

char panel[21][60] = { };

void drawSlash (int input, int start_point) {
    for (int i = 10 + input; i >= 10 - input; i--, start_point++) {
        if (start_point == 0) { i = 10; }
        if (i <= 21 && i >= 0 && start_point < 60) {
            panel[i][start_point] = '*';
        }
    }
}

int main (void) {
    int input, v = 10, step;
    // std::fill_n(panel, 1260, ' ');
    //for (int i = 0; i < 21; i++) for (int j = 0; j < 60; j++) panel[i][j] = ' ';
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(0);
    std::cin >> input;

    // draw
    // if graph_t % v == 0 it will have bar
    // v * (2 * n + 1)
    step = 0;
    if (input <= 10) {
        v = input;
    }
    drawSlash (input, 0);
    for (int ry = 10 - v; ry <= 10 + v; ry++) {
        for (int rx = input; rx < 60; rx += input * 2) {
            // bar
            panel[ry][rx] = '*';
            // slash
            drawSlash(input, rx);
        }
        step++;
    }

    // print
    for (int graph_v = 10; graph_v >= -10; graph_v--) {
        for (int graph_t = 0; graph_t < 60; graph_t++) {
            if (panel[10 - graph_v][graph_t] == '\0') { 
                std::cout << " "; 
            } else {
                std::cout << panel[10 - graph_v][graph_t];
            }
            if (graph_t == 59) { std::cout << "|" << std::setw(3) << std::right << graph_v << "V\n"; }
        }
    }

    return 0;
}