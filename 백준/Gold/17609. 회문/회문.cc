#include <iostream>

using namespace std;

string str;

bool palindrome(int& begin, int& end)
{
    while (begin < end)
    {
        if (str[begin] != str[end])
            return false;
        ++begin;
        --end;
    }
    return true;
}

int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n; 
    for (int i = 0; i < n; ++i)
    {
        cin >> str;
        int begin = 0, end = str.size() - 1;
        bool flag = palindrome(begin, end);
        if (flag)
            cout << "0\n";
        else
        {
            int nb = begin + 1, ne = end - 1;
            if (palindrome(nb, end) || palindrome(begin, ne))
                cout << "1\n";
            else
                cout << "2\n";
        }
    }
    return 0;
}
