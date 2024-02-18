#include <bits/stdc++.h>

using namespace std;


bool check(int64_t m, int n, const vector<int64_t> & a){
        set<pair<int64_t, int>> pos;
        int64_t dp[n + 1];
        int p2 = n;
        dp[n] = 0;
        pos.insert({dp[n], n});
        int64_t sum = 0;
        for (int j = n - 1; j >= 0; --j)
        {
            while (sum > m)
            {
                sum -= a[p2 - 1];
                pos.erase({dp[p2], p2});
                p2--;
            }
            dp[j] = pos.begin()->first + a[j];
            pos.insert({dp[j], j});
            sum += a[j];
        }
        sum = 0;
        int yes = 0;
        for (int j = 0; j < n; ++j)
        {
            if (sum <= m && dp[j] <= m)
                yes = 1;
            sum += a[j];
        }
        return yes;
}


void solve()
{
    int n;
    cin >> n;
    vector<int64_t> a(n + 1);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int64_t l = 0, r = int64_t(1e9) * n;
    while (l < r)
    {
        int64_t m = (l + r) / 2;

        if (check(m, n, a))
            r = m;
        else
            l = m + 1;
    }
    cout << l << "\n";
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}
