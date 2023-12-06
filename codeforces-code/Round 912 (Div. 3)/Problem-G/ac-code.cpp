#include <bits/stdc++.h>

using namespace std;

void solveProblem(){
    int lightNum;
    cin >> lightNum;
    vector<bool> lightStatus(lightNum + 1);
    string status;
    cin >> status;
    for(int i = 1; i <= lightNum; i++)
        lightStatus[i] = (status[i - 1] == '1'); // 输入灯的状态

    vector<int> edgeTo(lightNum + 1);
    vector<int> indegree(lightNum + 1);

    for(int i = 1; i <= lightNum; i++){
        cin >> edgeTo[i];
        indegree[edgeTo[i]]++; //记录入度
    }
    
    vector<int> result;
    queue<int> q;

    for(int i = 1; i <= lightNum; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    while (not q.empty()){   // 去掉所有的附加树枝（除了环以外）
        int currentLight = q.front();
        q.pop();
        if(lightStatus[currentLight]){
            result.push_back(currentLight);
            lightStatus[currentLight] = false;
            lightStatus[edgeTo[currentLight]] = !(lightStatus[edgeTo[currentLight]]);
        }
        indegree[edgeTo[currentLight]] --;
        if(indegree[edgeTo[currentLight]] == 0)
            q.push(edgeTo[currentLight]);
    }
    vector<bool> stutusCopy(lightStatus.begin(), lightStatus.end());
    

    for(int i = 1; i <= lightNum; i++){
        if(indegree[i]){
            vector<int> conditionPush, conditionSave;
            // 按下开关 i
            int currentNode = edgeTo[i];
            indegree[i] = 0;
            lightStatus[i] = !(lightStatus[i]);
            conditionPush.push_back(i);
            lightStatus[currentNode] = !(lightStatus[currentNode]);


            while (currentNode != i){
                indegree[currentNode] = 0;
                int nextNode = edgeTo[currentNode];
                if(lightStatus[currentNode]){
                    lightStatus[currentNode] = false;
                    conditionPush.push_back(currentNode);
                    lightStatus[nextNode] = !(lightStatus[nextNode]);
                }
                currentNode = nextNode;
            }
            if(lightStatus[i]){
                cout << -1 << endl;
                return;
            }


            // 不按下开关 i
            currentNode = edgeTo[i];

            while (currentNode != i){
                indegree[currentNode] = 0;
                int nextNode = edgeTo[currentNode];
                if(stutusCopy[currentNode]){
                    stutusCopy[currentNode] = false;
                    conditionSave.push_back(currentNode);
                    stutusCopy[nextNode] = !(stutusCopy[nextNode]);
                }
                currentNode = nextNode;
            }
            if(conditionPush.size() < conditionSave.size()){
                result.insert(result.end(), conditionPush.begin(), conditionPush.end());
            }else{
                result.insert(result.end(), conditionSave.begin(), conditionSave.end());
            }
        }
    }

    cout << result.size() << endl;
    for(int x : result){
        cout << x << ' ';
    }
    cout << endl;
    
}



int main(){
    int T;
    cin >> T;
    while(T--){
        solveProblem();
    }
}


