#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve(){
    i64 k, x, a;
    cin >> k >> x >> a;
    i64 needToEarn = 1;
    bool isWin = true;
    if(needToEarn >= a){
        isWin = false;
    }

    for(int i = 1; i <= x - 1; i++){
        i64 needToBet = (needToEarn + 1) / (k - 1);
        if((needToEarn + 1) % (k - 1) != 0){
            needToBet++; // 向上取整
        }
        needToEarn += needToBet; // 商场只能让你输，不然他亏了
        if(needToEarn >= a){
            isWin = false;
            break;
        }
    }
    if(k * (a - needToEarn) <= a){
        isWin = false;
    }
    if(isWin){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}


int main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }
}

