#include <iostream>
#include <array>
#include <list>

std::array<std::array<int, 1001>, 1001> panel;
std::list<int> arr;
std::array<int, 1001> checker;
int N, M, V, p;

void dfs (int caller) {
    arr.push_back(caller);
    checker.at(caller) = -1;
    for (int i = 0; i < 1001; i++) {
        if ((panel[i][caller] > 0 || panel[caller][i] > 0) && checker.at(i) == 0) {
            dfs(i);
        }
    }
}

void bfs (void) {
    std::list<int>::iterator it;
    for (it = arr.begin(); it != arr.end(); it++) {
        for (int i = 0; i < 1001; i++) {
            if ((panel[i][*it] > 0 || panel[*it][i] > 0) && checker.at(i) == 0) {
                arr.push_back(i);
                checker.at(i) = -1;
            }
        }
    }
}



void printList(void) {
    std::list<int>::iterator it;
    for (it = arr.begin(); it != arr.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
}

int main (void) {
    int N = 1, M, V, from, to;
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);
    
    // fill(0)
    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            panel[i][j] = 0;
        }
    }

    // input
    std::cin >> N >> M >> V;
    for (int i = 0; i < M; i++) {
        std::cin >> from >> to;
        panel[to][from]++;
    }

    // for (int i = 0; i < 11; i++) {
    //     for (int j = 0; j < 11; j++) {
    //         std::cout << panel[i][j] << " ";
    //     }
    //     std::cout << "\n";
    // }

    // dfs
    checker.fill(0);
    dfs(V);
    printList();
    arr.clear();

    // bfs
    checker.fill(0);
    arr.push_back(V);
    checker.at(V) = -1;
    p = 1;
    bfs();
    printList();

    return 0;
}

