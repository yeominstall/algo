#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    auto iter2 = participant.begin();
    for (auto iter = completion.begin(); iter != completion.end(); iter++)
    {
        if (*iter != *iter2)
        {
            answer = *iter2;
            break;
        }
        
        iter2++;
    }
    if (answer == "")
        answer = *iter2;
    
    return answer;
}