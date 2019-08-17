/**
 * oncoder 15. july 1
 */
#include <string>
#include <vector>
using namespace std;

//핵심 소스코드의 설명을 주석으로 작성하면 평가에 큰 도움이 됩니다.
class Solution{
public:
    vector<string> solution(int numPlayers, string deck){
        vector<string> players;
        string tmp;
        for (int i = 0; i < numPlayers; i++) {
            tmp = "";
            for (int j = 0; j < deck.size()/numPlayers; j++) {
                tmp += deck.at(numPlayers*j + i);
            }
            players.push_back(tmp);
        }
        return players;
    }
};