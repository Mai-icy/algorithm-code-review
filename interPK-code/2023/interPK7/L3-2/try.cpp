#include<bits/stdc++.h>

using namespace std;

struct TreeNode{
    int color;
    int cost;
    vector<int> sons;
};

int main(){
    int nodeNum;
    cin >> nodeNum;
    vector<TreeNode> nodes(nodeNum + 1);
    for(int i = 1; i <= nodeNum; i++){
        int sonNum;
        cin >> nodes[i].color >> nodes[i].cost >> sonNum;
        nodes[i].sons = vector<int>(sonNum);
        for(int j = 0; j < sonNum; j++){
            cin >> nodes[i].sons[j];
        }
    }

    int dp[nodeNum + 1][3];
    int sonNodeNum[nodeNum + 1] = {0};

    function<void(int)> dfs = [&](int u){
        if(nodes[u].sons.size() == 0){
            sonNodeNum[u] = 1;
            if (nodes[u].color == 1){
                dp[u][1] = 0; dp[u][0] = nodes[u].cost; dp[u][2] = -1;
            }else{
                dp[u][0] = 0; dp[u][1] = nodes[u].cost; dp[u][2] = -1;
            }
            return;
        }

        vector<int> temp;
        int oriCost = 0;
        int zeroCost = 0;

        for(int x: nodes[u].sons){
            dfs(x);
            sonNodeNum[u] += sonNodeNum[x];
            if(sonNodeNum[x] % 2 == 0) oriCost += dp[x][2];
            if(sonNodeNum[x] % 2 == 1) {
                temp.push_back(x);
                zeroCost += dp[x][0];
            }
        }

        if(temp.size() == 0){
            if(nodes[u].color == 1) {
                dp[u][1] = oriCost;
                dp[u][0] = oriCost + nodes[u].cost;
            }else{
                dp[u][1] = oriCost + nodes[u].cost;
                dp[u][0] = oriCost;
            }
        }

        auto changeCmp = [&](int x1, int x2){
            return dp[x1][1] - dp[x1][0] < dp[x2][1] - dp[x2][0];
        };

        sort(temp.begin(), temp.end(), changeCmp);

        if(sonNodeNum[u] % 2 == 0){
            int ans1, ans0;
            int changeNum = temp.size() / 2;
            int changCost = 0;

            for(int i = 0; i < changeNum; i++){
                changCost += dp[temp[i]][1] - dp[temp[i]][0];
            }
            // temp结果是 多一个 0 
            ans1 = oriCost + zeroCost + changCost;

            changCost += dp[changeNum][1] - dp[changeNum][0]; 
            // temp结果是 多一个 1 
            ans0 = oriCost + zeroCost + changCost;

            if(nodes[u].color == 1){
                dp[u][2] = ans1;
            }else{
                dp[u][2] = ans0;
            }
        }
        
        if(sonNodeNum[u] % 2 == 1){
            int ans1, ans0, ans2;
            int changeNum = temp.size() / 2;
            int changCost = 0;

            // temp 多两个0
            for(int i = 0; i < changeNum - 1; i++)
                changCost += dp[temp[i]][1] - dp[temp[i]][0];
            ans0 = oriCost + zeroCost + changCost;

            //temp结果是 平衡
            changCost += dp[changeNum - 1][1] - dp[changeNum - 1][0];
            ans2 = oriCost + zeroCost + changCost;
            
            // temp 多两个1
            changCost += dp[changeNum][1] - dp[changeNum][0];
            ans1 = oriCost + zeroCost + changCost;


            if(nodes[u].color == 1){
                dp[u][0] = ans0;
                dp[u][1] = ans2;
            }else{
                dp[u][0] = ans2;
                dp[u][1] = ans1;
            }
        }
    };

    dfs(1);

    if(sonNodeNum[1] % 2 == 0){
        cout << dp[1][2] << endl;
    }else{
        cout << min(dp[1][1], dp[1][0]) << endl;
    }
    
}

