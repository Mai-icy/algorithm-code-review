#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
const i64 mod = 998244353;

void solve(){
    int n;
    cin >> n;
    vector<i64> adj[n + 1];
    for(int i = 1; i < n; i++){
        i64 a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<vector<i64>> dp(3);
    dp[0].resize(n + 1, 1);
    dp[1].resize(n + 1, 1);
    dp[2].resize(n + 1, 0);

    function<void(i64, i64)> dfs = [&](i64 node, i64 parent){
        i64 t1 = 1, t2 = 1, t3 = 0;
        for(auto x: adj[node]){
            if(x == parent)
                continue;
            
            dfs(x, node);
            t2 *= (dp[1][x] + dp[0][x]) % mod;
            t2 %= mod;
            t3 += dp[1][x] + dp[2][x];
            t3 %= mod;
        }
        t2 -= t1;
        t2 = (t2 % mod + mod) % mod; // 取正数
        dp[0][node] = t1 % mod;
        dp[1][node] = (t1 + t2) % mod;
        dp[2][node] = t3 % mod;

    };
    dfs(1, -1);

    cout << (dp[1][1] + dp[2][1] + dp[0][1]) % mod << endl;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
}
