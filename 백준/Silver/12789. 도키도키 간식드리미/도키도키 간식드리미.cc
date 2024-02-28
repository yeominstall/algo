#include <iostream>

using namespace std;

int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n;
    int arr[1000];
    cin >> n;
    for (int i = 0, j = -1, num = 1; i < n; i++)
    {
        int ip;
        cin >> ip;
        while (1)
        {
            if (ip == num)
            {
                ++num;
                break;
            }
            else if (j > -1 && arr[j] == num)
            {
                --j;
                ++num;
                continue;
            }
            else
            {
                if (j > -1 && arr[j] < ip)
                {
                    cout << "Sad\n";
                    return 0;
                }
                else
                {
                    arr[++j] = ip;
                    break;
                }
            }
        }
    }
    cout << "Nice\n";
    return 0;
}