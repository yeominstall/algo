#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> str_list) {
    vector<string> answer;
    for (auto it = str_list.begin(); it != str_list.end(); ++it)
    {
        if (*it == "l")
        {
            for (auto it2 = str_list.begin(); it2 != it; ++it2)
                answer.push_back(*it2);
            return answer;
        }
        else if (*it == "r")
        {
            for (auto it2 = ++it; it2 != str_list.end(); ++it2)
                answer.push_back(*it2);
            return answer;
        }
    }
    return answer;
}