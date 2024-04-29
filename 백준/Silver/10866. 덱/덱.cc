#include <iostream>
#include <vector>

using namespace std;

int deque[10001];
int f_ptr = 1, b_ptr = 0, len, eoq;

int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    eoq = (sizeof(deque) / sizeof(int)) - 1;
    len = 0;
    string cmd;
    int x;
    for (int i = 0; i < n; ++i)
    {
        cin >> cmd;
        if (cmd == "push_front")
        {
            cin >> x;
            if ((--f_ptr) < 0)
                f_ptr = eoq;
            deque[f_ptr] = x;
            len++;
        }
        else if (cmd == "push_back")
        {
            cin >> x;
            if ((++b_ptr) > eoq)
                b_ptr = 0;
            deque[b_ptr] = x;
            len++;
        }
        else if (cmd == "pop_front")
        {
            if (len == 0)
            {
                printf("-1\n");
                continue;
            }
            printf("%d\n", deque[f_ptr]);
            if ((++f_ptr) > eoq)
                f_ptr = 0;
            len--;
        }
        else if (cmd == "pop_back")
        {
            if (len == 0)
            {
                printf("-1\n");
                continue;
            }
            printf("%d\n", deque[b_ptr]);
            if ((--b_ptr) < 0)
                b_ptr = eoq;
            len--;
        }
        else if (cmd == "size")
        {
            printf("%d\n", len);
        }
        else if (cmd == "empty")
        {
            if (len == 0)
                printf("%d\n", 1);
            else
                printf("%d\n", 0);
        }
        else if (cmd == "front")
        {
            if (len == 0)
                printf("%d\n", -1);
            else
                printf("%d\n", deque[f_ptr]);
        }
        else if (cmd == "back")
        {
            if (len == 0)
                printf("%d\n", -1);
            else
                printf("%d\n", deque[b_ptr]);
        }
    }

    return 0;
}