#include<bits/stdc++.h>

using namespace std;

struct Point
{
    int x, y;
};

double calculateArea(Point p1, Point p2, Point p3){
    int x_1 = p1.x, x_2 = p2.x, x_3 = p3.x;
    int y_1 = p1.y, y_2 = p2.y, y_3 = p3.y;

    function<double(int, int, int, int)> getDistance = [](int x1, int x2, int y1, int y2){
        return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    };

    double a = getDistance(x_1, x_2, y_1, y_2);
    double b = getDistance(x_2, x_3, y_2, y_3);
    double c = getDistance(x_1, x_3, y_1, y_3);

    double p = (a + b + c) / 2.0;

    return sqrt(p * (p - a) * (p - b) * (p - c));
}


void solveProblem(int n){
    double minArea = 1e8;

    vector<Point> points(n);
    for(int i = 0; i < n; i++){
        cin >> points[i].x >> points[i].y;
    }

    vector<Point> currentPoints;

    function<void(int)> dfs = [&](int x){
        if(currentPoints.size() == 3){
            double area = calculateArea(currentPoints[0], currentPoints[1], currentPoints[2]);
            minArea = min(area, minArea);
            return;
        }

        for(int i = x + 1; i < n; i++){
            currentPoints.push_back(points[i]);
            dfs(i);
            currentPoints.pop_back();
        }
    };

    dfs(0);

    printf("%.3lf", minArea + 0.0005);
}

int main(){
    int n;
    while(cin >> n){
        solveProblem(n);
    }   
}


