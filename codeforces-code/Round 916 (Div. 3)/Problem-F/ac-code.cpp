#include<bits/stdc++.h>

using namespace std;

void solveProblem(){
    int peopleNum;
    cin >> peopleNum;
    vector<int> sons[peopleNum + 1];

    for(int i = 2; i <= peopleNum; i++){
        int temp;
        cin >> temp;
        sons[temp].push_back(i);
    }

    vector<int> sonNodeNum(peopleNum + 1);
    vector<int> maxNodeofNode(peopleNum + 1);

    function<void(int)> dfs = [&](int node){
        int sumNum = 0;
        int maxNodeNum = -1;
        int maxNodeIndex = 0;
        for(int x:sons[node]){
            dfs(x);
            if(sonNodeNum[x] > maxNodeNum){
                maxNodeNum = sonNodeNum[x];
                maxNodeIndex = x;
            }
            sumNum += sonNodeNum[x] + 1;
        }
        maxNodeofNode[node] = maxNodeIndex;
        sonNodeNum[node] = sumNum;
    };

    dfs(1);

    function<int(int)> dfs2 = [&](int node){ // 返回可以减少的数量
        if(maxNodeofNode[node] == 0)
            return 0;

        if(sonNodeNum[node] >= 2 * (sonNodeNum[maxNodeofNode[node]] + 1)){
            if(sonNodeNum[node] % 2 == 0)
                return sonNodeNum[node];
            else
                return sonNodeNum[node] - 1;
        }else{
            int thisReleaseNum = 2 * (sonNodeNum[node] - (sonNodeNum[maxNodeofNode[node]] + 1));
            int oth = (sonNodeNum[maxNodeofNode[node]] + 1) - (sonNodeNum[node] - (sonNodeNum[maxNodeofNode[node]] + 1));

            int sonReleaseNum = dfs2(maxNodeofNode[node]);

            if(sonReleaseNum >= oth){
                if(sonNodeNum[node] % 2 == 0){
                    return sonNodeNum[node];
                }else{
                    return sonNodeNum[node] - 1;
                }
            }else{
                return sonNodeNum[node] - (oth - sonReleaseNum);
            }
        }
    };

    cout << dfs2(1) / 2 << endl;

}


int main(){
    int T;
    cin >> T;
    while(T--){
        solveProblem();
    }
}


