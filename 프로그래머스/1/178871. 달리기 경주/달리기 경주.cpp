#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string, int> pool;
    int i = 0;
    for (int i = 0; i < players.size(); i++)
    {
        pool[players[i]] = i;
    }
    for (auto& it : callings)
    {
        int rank = pool[it];
        string front = players[rank-1];
        
        players[rank-1] = it;
        pool[it]--;
        players[rank] = front;
        pool[front]++;
    }

    return players;
}