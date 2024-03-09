#include <bits/stdc++.h>
using namespace std;

bool isNotPrime[1000001];
using i64 = long long;

vector<int> getPrime(){
    vector<int> result;
    for(int i = 2; i < 1e6; i++){
        if(not isNotPrime[i]){
            result.push_back(i);
        }
        for(int j = 0; i * result[j] < 1000001 and j < result.size(); j++){
            isNotPrime[i * result[j]] = true;
            if(i % result[j] == 0) break;
        }
    }
    return result;
}
int main(){
    auto primeVector = getPrime();

    function<set<int>(i64)> getSet = [&](i64 n){
        set<int> result;
        for(int x: primeVector){
            if(1LL * x * x > n)
                break;
            
            if(n % x == 0)
                result.insert(x);
                while(n % x == 0){
                    n /= x;
                }
        }
        if(n > 1){
            result.insert(n);
        }
        return result;
    };

    int T;
    cin >> T;
    while(T--){
        int ans = 0;
        i64 a, b;
        cin >> a >> b;
        set<int> setA = getSet(a);
        set<int> setB = getSet(b);
        set<int> setC = getSet(a + b);
        // cout << setA.size() << ' ' << setB.size() << ' ' << setC.size() << endl;
        ans += setA.size() * setB.size() + setC.size();
        vector<int> setSameAB;
        vector<int> setSameABC;
        set_intersection(setA.begin(), setA.end(), setB.begin(), setB.end(), back_inserter(setSameAB));
        set_intersection(setSameAB.begin(), setSameAB.end(), setC.begin(), setC.end(), back_inserter(setSameABC));
        
        ans -= setSameABC.size();
        cout << ans << endl;
    }
}


