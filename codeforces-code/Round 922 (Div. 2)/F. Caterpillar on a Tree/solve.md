
分析题目可知
毛毛虫若不从树上掉下，并如果爬回原点，就要消耗 2 * (n - 1) 时间
此时加上 毛毛虫的掉落机制，可以发现，每次掉落都能带来一定的时间减少，如果我们能计算出所有掉落情况减少的时间，并从中选出最值得的几次掉落，就可以让总时间减去省下的时间即可

对于掉落的前提条件，就是毛毛虫在叶子节点上的时候。
画图做例子可以得出，对于一个分叉的点，这个点一定会被经过两次，因为不仅要走左边还要走右边或者更多。
如何规划一个更划算的走路过程，就是先走深度最浅的叶子节点，再走深度最深的叶子节点。
或者是说，为了掉落的时候省下更多时间，应当选择最深的节点进行掉落。
为了便于获取最深的节点，使用排序即可。

至于如何计算每次省下的时间，只需要计算当这个叶子节点作为最深节点的时候落下计算时间即可。


