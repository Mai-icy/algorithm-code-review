#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int dp1[n][n][x + 1], dp2[n][n][x + 1];

    for(int start = 0; start < n; start++){
        for(int end = start; end < n; end++){
            for(int k = 0; k <= x; k++){
                dp1[start][end][k] = 1e9;
                dp2[start][end][k] = 1e9;
            }
        }
    }  
    for(int start = 0; start < n; start++){
        for(int k = 1; k <= x; k ++){
            if(nums[start] == k){
                dp1[start][start][k] = 0;
                dp2[start][start][k] = 1;
            }else{
                dp1[start][start][k] = 1;
                dp2[start][start][k] = 0;
            }
        }
    }
    for(int len = 2; len <= n; len++){
        for(int start = 0, end = start + len - 1; end < n; start++, end++){
            for(int k = 1; k <= x; k++){
                for(int mid = start; mid + 1 <= end; mid++){
                    dp1[start][end][k] = min(dp1[start][end][k], dp1[start][mid][k] + dp1[mid + 1][end][k]);
                    dp2[start][end][k] = min(dp2[start][end][k], dp2[start][mid][k] + dp2[mid + 1][end][k]);
                    dp1[start][end][k] = min(dp1[start][end][k], dp2[start][end][k] + 1);
                }
            }
            for(int k1 = 1; k1 <= x; k1++){
                for(int k2 = 1; k2 <= x; k2++){
                    if(k1 == k2) continue;
                    dp2[start][end][k1] = min(dp2[start][end][k1], dp1[start][end][k2]);
                }
            }
        }
    }
    int result = 1e9;
    for(int k = 1; k <= x; k++){
        result = min(result, dp1[0][n - 1][k]);
    }
    cout << result << endl;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }
}