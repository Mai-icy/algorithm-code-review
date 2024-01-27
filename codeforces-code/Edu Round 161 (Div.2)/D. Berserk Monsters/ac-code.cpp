    #include <bits/stdc++.h>
     
    using namespace std;
     
    int main() {
      ios::sync_with_stdio(false); cin.tie(0);
      int t;
      cin >> t;
      while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 2), d(n + 2, INT_MAX);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) cin >> d[i];
        set<int> lft, cur;
        for (int i = 0; i < n + 2; ++i) {
          lft.insert(i);
          cur.insert(i);
        }
        for (int z = 0; z < n; ++z) {
          set<int> del, ncur;
          for (int i : cur) {
            auto it = lft.find(i);
            if (it == lft.end()) continue;
            int prv = *prev(it);
            int nxt = *next(it);
            if (a[prv] + a[nxt] > d[i]) {
              del.insert(i);
              ncur.insert(prv);
              ncur.insert(nxt);
            }
          }
          cout << del.size() << ' ';
          for (auto it : del) lft.erase(it);
          cur = ncur;
        }
        cout << '\n';
      }
    }