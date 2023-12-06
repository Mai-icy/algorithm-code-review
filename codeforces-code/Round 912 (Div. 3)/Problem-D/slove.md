分类：二分

# 题解

题目特点鲜明可见，是最大值的最小值，对于最大值的最小值和最小值的最大值，这种比较典型的问题，通常采用二分来解决。
这题的思路卡在如何验证是否可行，也就是当`k=n`时，判断能否达成题目要求。

至于如何判断，实际上很简单
只需要知道当前 能站到的区间currentSection 最大移动k 下一个区间nextSection 这三个条件
可得
`nextSection = (max(currentSection[0] - k, nextSection[0]), min(currentSection[1] + k, nextSection[1]))`

由于这是一个闭区间，所以一开始的 Section 就是 [0, 0]
当 Section[1] < Section[0]
便代表无法在该区间站立，此时k不成立

此时再按二分，找到[0, 1e9]区间内，最小能成立的k即可