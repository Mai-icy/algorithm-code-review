类型：区间DP

当我们考虑题目例子时，发现贪心是难以使用的，此时我们应当想到DP，并且这道题是区间操作的最小值，所以这题大概率也是区间DP

至于是DP会需要状态的转移，如何使用过去的便于之后的计算

先定义dp1[s][e][k] 为区间[s, e]全转变为k需要的次数
先定义dp2[s][e][k] 为区间[s, e]变后没有k需要的次数

状态转移方程则有
dp1[start][end][k] = min(dp1[start][end][k], dp1[start][mid][k] + dp1[mid + 1][end][k]);
dp2[start][end][k] = min(dp2[start][end][k], dp2[start][mid][k] + dp2[mid + 1][end][k]);
dp1[start][end][k] = min(dp1[start][end][k], dp2[start][end][k] + 1);
同时不能忘记其他k的变化会影响dp2，例如将区间内都变成k1,实际上就是让区间所有值都不等于k2(k2 != k1)
只要做一次更新即可。




