#include <bits/stdc++.h>

using namespace std;


int main()
{

    int n, k;
    cin >> n >> k;
    vector<vector<int>> children(n + 1, vector<int>());
    vector<int> paceFromRoot(n + 1);
    vector<int> parent(n + 1);
    vector<int> depth(n + 1);

    for(int i = 2; i <= n; ++i)
    {
        cin >> parent[i];
        children[parent[i]].push_back(i);
    }

    function<void(int)> dfs1 = [&](int currentNode){
        depth[currentNode] = 0;
        int parentNode = parent[currentNode];
        // 记录到根节点的距离，方便计算
        if(currentNode == 1) 
            paceFromRoot[currentNode] = 0;
        else 
            paceFromRoot[currentNode] = paceFromRoot[parentNode] + 1;
        // 记录每个节点的最大深度
        for(int child: children[currentNode]){
            dfs1(child);
            depth[currentNode] = max(depth[currentNode], depth[child] + 1);
        }
        sort(children[currentNode].begin(), children[currentNode].end(), [&](int n1, int n2){return depth[n1] < depth[n2]; });
    };
    dfs1(1);

    vector<int> profits;
    for(int i = 1; i <= n; ++i)
    {   
        int node = i;
        if(children[node].size() == 0) // 遍历所有叶子节点
        {
            int profit = 0;
            while(node != 1)
            {
                if(children[parent[node]].back() == node)
                {
                    node = parent[node];
                    profit++;
                }else{
                    profit = profit + 1 - paceFromRoot[parent[node]];
                    break;
                }
            }
            if(profit > 0){
                profits.push_back(profit);
            }
        }
    }

    sort(profits.begin(),profits.end(), greater<int>());

    int result = 2 * (n - 1);

    for(int i = 0; i < min((int)profits.size(), k + 1); ++i){
        result -= profits[i];
    }

    cout << result << '\n';
    return 0;
}