#include <bits/stdc++.h>
using namespace std;
vector<list<int>::iterator> G[200005];
void Solve()
{   
    int n;
    list<int> a;
    cin >> n;
    for (int i = 0; i < n; i++)
        G[i].clear();
    for (int i = 1, x; i <= n; i++)
    {
        cin >> x;
        a.push_back(x);
        G[x].push_back(--a.end());
    }


    for (int i = n - 1; i > 0; i--)
    {
        if (!G[i].size())
            continue;
        for (auto &it : G[i])
        {
            if (it != a.begin() && *prev(it) == i - 1)
                a.erase(it), it = a.end();
            else if (it != --a.end() && *next(it) == i - 1)
                a.erase(it), it = a.end(); // it = a.end() 是让 it 不会被访问到
            else if (it == --a.end() || *next(it) != i)
            {
                cout << "no\n";
                return;
            }
        }
        for (auto &it : G[i])
            if (it != a.end()) // 极长连续段中的元素
                a.erase(it);
    }
    if (a.size() > 1 || a.back() != 0)
        cout << "no\n";
    else
        cout << "yes\n";
}
signed main()
{
    // cin.tie(0)->ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}