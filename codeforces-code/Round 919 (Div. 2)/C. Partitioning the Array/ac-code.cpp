#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int result = 1;
    int gcd;
    for(int k = 1; k <= n - 1; k++){
        if(n % k != 0) continue;
        bool success = true;
        int totalGcd = 0;
        for(int start = 0; start < k; start++){
            gcd = abs(arr[k + start] - arr[start]);
            for(int i = 2 * k + start; i < n; i += k){
                gcd = __gcd(gcd, abs(arr[i] - arr[start]));
                if(gcd == 1){
                    break;
                }
            }
            totalGcd = __gcd(totalGcd, gcd);     
            if(gcd == 1){
                break;
            }
        }
        if(totalGcd != 1) result++;
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



