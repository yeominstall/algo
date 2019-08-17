/**
 * swea 1208
 */

#include <iostream>
#include <array>

std::array<int, 100> boxes;

int main (void) {
    int mov, diff, min = 0, max = 0;
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);

    for (int tc = 1; tc <= 1; tc++) {
        std::cin >> mov;
        boxes.fill(0);
        diff = 101;
        for (int st = 0; st < 100; st++) {
            std::cin >> boxes.at(st);
        }

        for (int cnt = 0; cnt < mov+1; cnt++) {
            boxes.at(max)--;
            boxes.at(min)++;
            min = 0; max = 0;
            for (int st = 1; st < 100; st++) {
                if (boxes.at(st) >= boxes.at(max)) {
                    max = st;
                }
                if (boxes.at(st) < boxes.at(min)) {
                    min = st;
                }
            }
            diff = boxes.at(max) - boxes.at(min);
            if (diff < 2) {
                break;
            }
        }

        std::cout << "#" << tc << " " << diff << "\n";
    }
    
    return 0;
}