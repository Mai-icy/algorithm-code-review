#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MP make_pair
mt19937 rnd(time(0));
const int MAXN = 2e5 + 5;
int n, q;
int dx[MAXN], dy[MAXN];
int px[MAXN], py[MAXN], sx[MAXN], sy[MAXN];
map<pair<int, int>, vector<int>> vp, vs;
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        char c;
        cin >> c;
        if (c == 'U')
            dy[i] = 1;
        else if (c == 'D')
            dy[i] = -1;
        else if (c == 'L')
            dx[i] = -1;
        else if (c == 'R')
            dx[i] = 1;
    }
    for (int i = 1; i <= n; i++)
        px[i] = px[i - 1] + dx[i], py[i] = py[i - 1] + dy[i];
    for (int i = n; i >= 1; i--)
        sx[i] = sx[i + 1] + dx[i], sy[i] = sy[i + 1] + dy[i];
    for (int i = 0; i <= n; i++)
    {
        vp[MP(px[i], py[i])].push_back(i);
        vs[MP(sx[i], sy[i])].push_back(i);
    }
    auto any = [&](vector<int> &a, int L, int R)
    {
        if (a.empty() || L > R)
            return false;
        int l = 0, r = a.size() - 1, mid;
        while (l < r)
        {
            mid = l + r >> 1;
            if (a[mid] >= L)
                r = mid;
            else
                l = mid + 1;
        }
        return L <= a[l] && a[l] <= R;
    };
    while (q--)
    {
        int x, y, l, r;
        cin >> x >> y >> l >> r;
        if (any(vp[MP(x, y)], 0, l - 1) || any(vp[MP(x, y)], r + 1, n) ||
            any(vs[MP(x - px[l - 1] + sx[r + 1], y - py[l - 1] + sy[r + 1])], l, r))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}