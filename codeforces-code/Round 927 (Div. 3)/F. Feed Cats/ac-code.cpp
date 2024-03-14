#include<bits/stdc++.h>

using namespace std;

using Zone = pair<int, int>;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> catNumDiff(n + 2);
    vector<int> farPos(n + 2);

    vector<int> dp(n + 2);

    vector<Zone> zones(m);
    for(int i = 0; i < m; i++){
        cin >> zones[i].first >> zones[i].second;
    }

    for(Zone zone:zones){
        catNumDiff[zone.first]++;
        catNumDiff[zone.second + 1]--;

        farPos[zone.first] = max(farPos[zone.first], zone.second);
    }

    int currentMax = 0;
    for(int i = 1; i<= n; i++){
        currentMax = max(i, currentMax);
        currentMax = max(currentMax, farPos[i]);
        farPos[i] = currentMax;
    }

    int catNum = 0;
    for(int i = 1; i <= n; i++){
        catNum += catNumDiff[i];
        dp[farPos[i] + 1] = max(dp[farPos[i] + 1], dp[i] + catNum);
        dp[i + 1] = max(dp[i], dp[i + 1]);
    }

    cout << dp[n + 1] << endl;

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
