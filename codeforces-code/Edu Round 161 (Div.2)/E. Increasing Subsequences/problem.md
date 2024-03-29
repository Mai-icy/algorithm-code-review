# E. Increasing Subsequences

让我们回顾一下，数组 $a$ 的递增子序列是指在不改变其余元素顺序的情况下，通过移除某些元素而得到的序列，并且其余元素是严格递增的(即 $a_{b_1} \lt; a_{b_2} \lt; \dots \lt; a_{b_k}$ 和 $b_1 \lt; b_2 \lt; \dots \lt; b_k$ )。注意，空子序列也是递增的。

给你一个正整数 $X$ 。你的任务是找出一个长度为**最多 $200$ **的整数数组，使得它有恰好 $X$ 个递增的子序列，或者报告说没有这样的数组。如果有多个答案，你可以打印其中任何一个。

如果两个子序列由相同的元素组成，但对应数组中的不同位置，则认为它们是不同的(例如，数组 $[2, 2]$ 有两个不同的子序列等于 $[2]$ )。

**输入**

第一行包含一个整数 $t$ ( $1 \le t \le 1000$ ) - 测试用例的数量。

每个测试用例的唯一一行包含一个整数 $X$ ( $2 \le X \le 10^{18}$ )。

**输出**

对于每个查询，打印其答案。如果无法找到所需的数组，则在第一行打印 \-1。否则，在第一行打印正整数 $n$ - 数组的长度。在第二行打印 $n$ 个整数--所需的数组本身。如果有多个答案，可以打印任意一个。数组的所有元素都应在 $[-10^9; 10^9]$ 范围内。
