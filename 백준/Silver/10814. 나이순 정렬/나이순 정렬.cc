#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct user
{
    int idx;
    int age;
    string name;
};

int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<user> userlist(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> userlist[i].age >> userlist[i].name;
        userlist[i].idx = i;
    }
    sort(userlist.begin(), userlist.end(), [](const user& lst, const user& rst)
        {
            if (lst.age == rst.age)
                return lst.idx < rst.idx;
            return lst.age < rst.age;
        });

    for (auto& u : userlist)
        cout << u.age << ' ' << u.name << '\n';

    return 0;
}