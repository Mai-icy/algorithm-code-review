题解

对于一个这样的树，对于它的父节点，这个父节点是肯定无法组队的，此时考虑它的几颗子树，对于不同的子树中取两个必定能匹配，这就转化成了另一个问题，n种颜色的球有各种不同个数，每次取不同颜色的一对，最多可以剩下几对

问题结论，对于n种颜色的球，记录球的总数sumN和颜色最多的球的个数maxN
 - 如果 sumN >= maxN * 2，那么剩下球的个数sumN % 2
 - 否则剩下球的个数是 maxN - (sumN - maxN) 也就是 2 * maxN - sumN

那么问题就可以顺利转化，我们先使用dfs记录每个节点的所有子树的节点数量，和记录所有子树中最多节点的子树下标

再次使用dfs来根据上面的定理，一旦该节点满足sumN >= maxN * 2，那么他就可以取的只剩下sumN % 2 + 1

int dfs(int node)， 以节点作为参数，返回该节点的子节点能匹配的个数，如果能直接覆盖就可以直接返回，若不能，则递归最大子树的节点。


