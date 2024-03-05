
这道题是不难的
主要是在图算法上

主要是题目理解上，比赛的时候没写出来主要因为没看懂题目意思。

题意：
给你多个点和多个边以及边权值，已知图中会有环，每个环都有个最小权值的边，问多个环中哪个环的最小权值最小，输出这个环。


暴力思路，找到所有环再去找肯定是不行的。
不妨我们想，答案的这个环有最小权值的边，所以我们只要按照权值从小到大遍历边，找到第一个能在环中的边，包含这个边的环就是答案。


如何判断一个边是否在一个环内呢？根据题目中一句话：“图不一定联通”
提醒了我们使用并查集。
逐步加入边，在加入这个边之前查看这两个点是否已经联通，若已经联通，代表加入新边将出现环。

这样出现了另一个问题，如果检查一个边是否在环内，我们的并查集就需要只去掉这个边并包含其他的边，如何判断能最大利用呢？

答：从权值大的开始加，因为如果我们以一个边作为我们的答案边，代表这个环里面不存在比它更小的边，主要遍历一次所有的边就可以找到最小的符合要求的边。（同时计入邻接表）

最后按照DFS找到这两个点的路径即可
输出对应的路径

需要注意的是，这个图可能有众多连接的边，不利于dfs，一旦两个点已经连接，就不需要将新边加入邻接表，否则会卡时间
