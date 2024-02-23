#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    vector<vector<vector<int>>> d(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, INT_MAX)));
    d[0][0][0] = 0;

    for(int i = 0; i < n; i++)
        for(int k = 0; k < n; k++)    //
            for(int j = 0; j < n; j++)// k 和 j的两者顺序不重要

                if (d[i][j][k] < INT_MAX) { // d[i][j][k] 已经被考虑过
                    int ai = a[i];
                    int ni, nj, nk;

                    // 不涂
                    nj = j > 0 ? j + 1 : (k == 0 ? 1 : 0);
                    nk = max(0, k - 1);
                    d[i + 1][nj][nk] = min(d[i + 1][nj][nk], d[i][j][k]);
                    // 左涂
                    nj = j > 0 ? j + 1 : 0;
                    if (nj <= ai)
                        nj = 0;
                    nk = max(0, k - 1);
                    d[i + 1][nj][nk] = min(d[i + 1][nj][nk], d[i][j][k] + 1);
                    // 右涂
                    nj = j > 0 ? j + 1 : 0;
                    nk = max(ai - 1, k - 1);
                    d[i + 1][nj][nk] = min(d[i + 1][nj][nk], d[i][j][k] + 1);
                }

    cout << *min_element(d[n][0].begin(), d[n][0].end()) << endl;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }
}

