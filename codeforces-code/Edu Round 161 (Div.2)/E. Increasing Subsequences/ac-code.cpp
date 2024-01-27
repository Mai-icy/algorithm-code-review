#include<bits/stdc++.h>

using namespace std;

void solve(){
    long long x;
    cin >> x;

    long long maxL = 0;
    long long resLen = 0;
    vector<long long> digits(60);

    for (int i = 0; i < 60; i++) {
        digits[i] = x % 2;
        if(x % 2 == 1) resLen++;
        x = x / 2;
        maxL++;
        if(x == 0){
            break;
        }
    }
    maxL--;
    resLen --;

    resLen += maxL;

    cout << resLen << endl;
    for(int i = 1; i <= maxL;i++){
        cout << i << ' ';
        if(digits[maxL - i] == 1 and maxL - i < maxL){
            cout << 0 << ' ';
        }
    }
    cout << endl;
}


int main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }
}

