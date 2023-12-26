#include<bits/stdc++.h>
 
using namespace std;
 
const int MOD = 998244353;
 
mt19937_64 rnd(time(0));

using u64 = uint64_t;
using i64 = long long;

void solve()
{
	int colorNum;
    cin >> colorNum;
	i64 zoneNum = 0, resultNum = 1;

    vector<int> lights(colorNum * 2 + 1);
    vector<uint64_t> preHash(colorNum * 2 + 1);
    vector<uint64_t> hashValue(colorNum + 1);

    for(int i = 1; i <= colorNum; i++)
        hashValue[i] = rnd();

    for(int i = 1; i <= 2 * colorNum; i++){
        cin >> lights[i];
        preHash[i] = preHash[i - 1] ^ hashValue[lights[i]];
    }
	
	map<uint64_t, int> last;
    for(int i = 1; i <= colorNum * 2; i++)
        last[preHash[i]] = i;
    
    for(int i = 1, j; i <= colorNum * 2; i = j + 1)
	{
		i64 res = 0;
        for(j = i; preHash[j]; j++){
            res -= last[preHash[j]] - j;
            j = last[preHash[j]];
        }
        res += j - i + 1;
        zoneNum++;
        resultNum = resultNum * res % MOD;
	}
	
	cout << zoneNum << ' ' << resultNum << endl;
}
 
int main()
{
	int T;
	cin >> T;
    while(T--){
        solve();
    }
}