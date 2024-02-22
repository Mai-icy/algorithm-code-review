#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

using Edge = pair<int, pair<int, int>>;

struct UF {
    vector<int> par,num;
    UF(int n) : par(n), num(n,1) {
        iota(par.begin(), par.end(), 0);
    }
    int find(int v) {
        return (par[v] == v) ? v : (par[v]=find(par[v]));
    }
    void connect(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return;
        if (num[u] < num[v]) swap(u, v);
        num[u] += num[v];
        par[v] = u;
    }
    bool connected(int u, int v) {
        return find(u) == find(v);
    }
    int size(int v) {
        return num[find(v)];
    }
};


void solve(){
    int n, m;
    cin >> n >> m;

    UF uf(n + 1);

    vector<int> adj[n + 1];
    vector<Edge> edges(m);

    for(int i = 0; i < m; i++){
        int from, to, weight;
        cin >> from >> to >> weight;
        edges[i] = {weight, {from, to}};
    }

    sort(edges.rbegin(), edges.rend());

    int begin;
    int bto;
    int ans;

    for(const Edge &e:edges){
        if(uf.connected(e.second.first, e.second.second)){
            begin = e.second.first;
            bto = e.second.second;
            ans = e.first;
        }else{
            uf.connect(e.second.first, e.second.second);
            // 注意这两句不能在else外，否则会被卡时间
            adj[e.second.first].push_back(e.second.second);
            adj[e.second.second].push_back(e.second.first);
        }
        // uf.connect(e.second.first, e.second.second);
    }

    vector<int> path;
    vector<int> visited(n + 1);
    bool isEnd = false;
    
    function<void(int, int)> dfs = [&](int v, int parent){
        if(isEnd) return;
        for(int w:adj[v]){
            if(w == parent) continue;
            if(visited[w] == 1) continue;
        
            if(w == begin){
                isEnd = true;
                return;
            }else if(visited[w] != 1){
                path.push_back(w);
                visited[w] = 1;
                dfs(w, v);
                if(isEnd) return;
                visited[w] = 0;
            }
            path.pop_back();
        }
    };

    visited[bto] = 1;
    path.push_back(begin);
    path.push_back(bto);
    dfs(bto, begin);

    cout << ans << ' ' << path.size() << endl;
    for(int p : path){
        cout << p << ' ';
    }
    cout << endl;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
}

