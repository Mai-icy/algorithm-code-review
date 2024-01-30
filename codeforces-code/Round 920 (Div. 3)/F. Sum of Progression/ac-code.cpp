#include<bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve(){
    i64 n, req;
    cin >> n >> req;
    int pivot = sqrt(n);

    vector<i64> arr(n + 1);
    vector<vector<i64>> ans1(pivot + 1, vector<i64>(n + 1));
    vector<vector<i64>> ans2(pivot + 1, vector<i64>(n + 1));
    
    for(int i = 1; i <= n; i++)
        cin >> arr[i];

    for (int d = 1; d <= pivot; d++){
        for(int j = 1; j <= n; j++){
            ans1[d][j] = arr[j];
            ans2[d][j] = arr[j] * ((j - 1)/ d + 1);
            if(j >= d + 1){
                ans1[d][j] += ans1[d][j - d];
                ans2[d][j] += ans2[d][j - d];
            }
        }
    }

    while(req--){
        i64 s, d, k;
        cin >> s >> d >> k;
        if(d >= pivot){
            i64 result = 0;
            for(int i = 0; i < k; i++){
                result += arr[s + i * d] * (i + 1);
            }
            cout << result << ' ';
            continue;
        }else{
            i64 left = s - d;
            i64 right = s + (k - 1) * d;
            i64 result = ans2[d][right];
            if(left >= 1)
                result -= ans2[d][left] + (ans1[d][right] - ans1[d][left]) * ((left - 1) / d + 1);

            cout << result << ' ';
        }
    }
    cout << endl;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while(T--){
        solve();
    }
}

