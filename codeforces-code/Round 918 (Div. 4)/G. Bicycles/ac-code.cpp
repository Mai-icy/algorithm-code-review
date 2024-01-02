#include<bits/stdc++.h>

using namespace std;

struct Path{
    int to;
    int weight;
};
using i64 = long long;
using City = pair<int, int>;

void solveProblem(){
    int cityNum, roadNum;
    cin >> cityNum >> roadNum;
    vector<Path> roads[cityNum + 1];
    vector<City> citys(cityNum);
    vector<int> speed(cityNum + 1);
    vector<i64> result(cityNum + 1, -1);
    for(int _ = 0; _ < roadNum; _++){
        int c1, c2, weight;
        cin >> c1 >> c2 >> weight;
        roads[c1].push_back({c2, weight});
        roads[c2].push_back({c1, weight});
    }
    for(int i = 0; i < cityNum; i++){
        citys[i].second = i + 1;
        cin >> citys[i].first;
    }
    sort(citys.begin(), citys.end());

    function<void(int, int)> bfs = [&](int s, int speed){
        vector<i64> distTo(cityNum + 1, INT_MAX);
        vector<bool> onQ(cityNum + 1);
        queue<int> que;
        
        distTo[s] = 0;
        que.push(s);
        while(not que.empty()){
            int v = que.front();
            que.pop();
            onQ[v] = false;

            for(auto p:roads[v]){
                int w = p.to;
                if(distTo[w] > distTo[v] + p.weight){
                    distTo[w] = distTo[v] + p.weight;
                    if(not onQ[w]){
                        que.push(w);
                        onQ[w] = true;
                    }
                }
            }
        }

        result[s] = distTo[cityNum] * speed;
        for(int i = 1; i <= cityNum; i++){
            if(i != s and result[i] != -1){
                result[s] = min(result[s], distTo[i] * speed + result[i]);
            }
        }
    };

    for(int i = 0; i < cityNum; i++){
        bfs(citys[i].second, citys[i].first);
    }

    cout << result[1] << endl;

}


int main(){
    int T;
    cin >> T;
    while(T--){
        solveProblem();
    }
}
