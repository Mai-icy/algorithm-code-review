水题

线性的动态规划，很好发现。

然后观察题目，找到题目中的不同点，对于任意一个点，只有两种选择，一种是喂养这个点的所有猫，另外一种就是不喂养，但是如果一旦喂养了，我的下次喂养至少要在这些猫都走了之后，也就是这些猫中区间最大的右边界，这样，动态规划的状态转移就可以轻松得出。

现在开始思考我们需要的东西。
经过以上分析，对于一个位置点，我们要知道这个点的猫的数量，以及这些猫最大右边界

好了就是这么简单，至于如何获取猫的数量，可以使用差分数组
如何获得最大右边界，可以先记录forPos[i]为i这个点的最大右边界，forPos[i]是递增的，只要对于每个区间进行：
```cpp
farPos[zone.first] = max(farPos[zone.first], zone.second);

int currentMax = 0;
for(int i = 1; i<= n; i++){
    currentMax = max(i, currentMax);
    currentMax = max(currentMax, farPos[i]);
    farPos[i] = currentMax;
}
```
即可。

然后正常状态转移方程：
```cpp
dp[farPos[i] + 1] = max(dp[farPos[i] + 1], dp[i] + catNum);
dp[i + 1] = max(dp[i], dp[i + 1]);
```