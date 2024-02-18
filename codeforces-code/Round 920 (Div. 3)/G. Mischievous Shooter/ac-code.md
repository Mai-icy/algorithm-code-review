#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, m, k;
vector<vector<int>> a;


bool prov(int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < m;
}

int ans() {
    int cnt = 0;
    int dp[n][m];
    int pref[n][m];
    int pref_up[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            pref_up[i][j] = a[i][j];
            if (prov(i - 1, j))
                pref_up[i][j] += pref_up[i - 1][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = m - 1; j >= 0; j--) {
            pref[i][j] = a[i][j];
            if (prov(i - 1, j + 1))
                pref[i][j] += pref[i - 1][j + 1];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j] = pref_up[i][j];
            if (prov(i - k, j))
                dp[i][j] -= pref_up[i - k][j];
            if (prov(i, j - 1))
                dp[i][j] += dp[i][j - 1];
            if (j < k) {
                int i1 = j - k + i;
                if (i1 >= 0)
                    dp[i][j] -= pref[i1][0];
            }
            else
                dp[i][j] -= pref[i][j - k];
            if (prov(i - k, j))
                dp[i][j] += pref[i - k][j];
            cnt = max(cnt, dp[i][j]);
        }
    }

    return cnt;
}

void solve() {
    cin >> n >> m >> k;
    k++;
    char c;
    bool st[n][m];
    a.resize(n);
    for (int i = 0; i < n; i++) {
        a[i].resize(m);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
        {
            cin >> c;
            st[i][j] = (c == '#');
            a[i][j] = st[i][j];
        }
    }

    int mx = ans();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = st[n - i - 1][j];
        }
    }
    mx = max(mx, ans());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = st[i][m - j - 1];
        }
    }
    mx = max(mx, ans());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = st[n - i - 1][m - j - 1];
        }
    }
    mx = max(mx, ans());

    cout << mx << '\n';

}

signed main() {
    int T;
    cin >> T;
    while (T--)
        solve();

    return 0;
}