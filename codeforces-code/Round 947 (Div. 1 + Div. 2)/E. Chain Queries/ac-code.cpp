#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, q;
    cin >> n >> q;
    vector<bool> isBlack(n + 1);
    for(int i = 1; i <= n; i++){
        int tmp;
        cin >> tmp;
        isBlack[i] = tmp;
    }

    vector<int> parent(n + 1);
    vector<int> blackSonCnt(n + 1);
    set<int> recordCnt[4];
    vector<int> adj[n + 1];

    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    function<void(int, int)> dfs = [&](int current, int par){
        parent[current] = par;

        for(int son: adj[current]){
            if(son == par) continue;

            if(isBlack[son]) blackSonCnt[current] ++;
            dfs(son, current);
        }
        
        if(isBlack[current]){
            recordCnt[min(3, blackSonCnt[current])].insert(current);
        }
    };
    dfs(1, 0);
    while(q--){
        int target;
        cin >> target;
        if(isBlack[target]){
            recordCnt[min(3, blackSonCnt[target])].erase(target);
            int father = parent[target];
            if(isBlack[father]){
                recordCnt[min(3, blackSonCnt[father])].erase(father);
                recordCnt[min(3, blackSonCnt[father] - 1)].insert(father);
            }
            blackSonCnt[father]--;
        }else{
            recordCnt[min(3, blackSonCnt[target])].insert(target);
            int father = parent[target];
            if(isBlack[father]){
                recordCnt[min(3, blackSonCnt[father])].erase(father);
                recordCnt[min(3, blackSonCnt[father] + 1)].insert(father);
            }
            blackSonCnt[father]++;
        }
        isBlack[target] = not isBlack[target];

        // 进入判断
        if(recordCnt[3].size() >= 1){
            cout << "NO" << endl;
            continue;
        }

        if(recordCnt[2].size() == 1){
            int node = *recordCnt[2].begin();
            if(isBlack[parent[node]]){ // node != 1 and 
                cout << "NO" << endl;
                continue;
            }
            if(recordCnt[0].size() != 2){
                cout << "NO" << endl;
                continue;
            }
            cout << "YES" << endl;
            continue;
        }

        if(recordCnt[0].size() != 1){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
    }
}


int main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }
}