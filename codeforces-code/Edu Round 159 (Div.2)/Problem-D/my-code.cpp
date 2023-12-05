#include <bits/stdc++.h>

using namespace std;

struct Point{
    int x, y;
    bool operator<(const Point& other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
};

int main(){
    int commandNum, searchNum;
    cin >> commandNum >> searchNum;

    string commands;
    cin >> commands;
    
    map<Point, vector<int>> positionIndexMap; // 意为变化量(delX, delY) 位于前 index 个指令之和
    map<Point, vector<int>> reverseIndexMap;  // 上者的反向情况
    Point currentPoint({0, 0}), rcurrentPoint({0, 0});

    vector<Point> postiveDeltaPoint(commandNum + 2);
    vector<Point> reserveDeltaPoint(commandNum + 2);
    for(int i = 0; i < commandNum; i++){
        if(commands[i] == 'U') currentPoint.y++;
        if(commands[i] == 'D') currentPoint.y--;
        if(commands[i] == 'L') currentPoint.x--;
        if(commands[i] == 'R') currentPoint.x++;

        postiveDeltaPoint[i + 1] = currentPoint;

        if(commands[commandNum - 1 - i] == 'U') rcurrentPoint.y++;
        if(commands[commandNum - 1 - i] == 'D') rcurrentPoint.y--;
        if(commands[commandNum - 1 - i] == 'L') rcurrentPoint.x--;
        if(commands[commandNum - 1 - i] == 'R') rcurrentPoint.x++;

        reserveDeltaPoint[commandNum - i] = rcurrentPoint;

        positionIndexMap[currentPoint].push_back(i);
        positionIndexMap[rcurrentPoint].push_back(commandNum - 1 - i);
    }

    function<bool(const vector<int> &, int, int)> search = [&](const vector<int> &result, int left, int right){
        if(result.empty() or left > right)
            return false;
        int l = 0, r = result.size() - 1, mid;
        while (l < r)
        {
            mid = l + r >> 1;
            if (result[mid] >= left)
                r = mid;
            else
                l = mid + 1;
        }
        return (left <= result[l] and result[l] <= right);
    };


    while(searchNum--){
        Point targetPoint;
        int reserveLeft, reserveRight; // 包含左右的
        cin >> targetPoint.x >> targetPoint.y >> reserveLeft >> reserveRight;

        // 先检查在未反向的指令段是否以满足要求
        if(search(positionIndexMap[targetPoint], 0, reserveLeft - 1) or 
           search(positionIndexMap[targetPoint], reserveRight, commandNum)){
            cout << "YES" << endl;
        }else{
            // 理解点，需要打草稿理解，此时需要转化targetPoint
            targetPoint.x = targetPoint.x - postiveDeltaPoint[reserveLeft - 1].x + reserveDeltaPoint[reserveRight + 1].x;
            targetPoint.y = targetPoint.y - postiveDeltaPoint[reserveLeft - 1].y + reserveDeltaPoint[reserveRight + 1].y;
            if(search(reverseIndexMap[targetPoint], reserveLeft, reserveRight)){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }

    }


}
