# 最大平均区间
Time Limit (Java / Others)
6000 / 3000 MS
Memory Limit (Java / Others)
327680 / 327680 K

Problem Description

给定长度为 $N$ 的序列 $a$ 和 $p$ 以及定值 $k$，一个区间 $[l，r]$ 是好的，当且仅当 $p_l ⊕ p_r ≥ k $，其中表示异或符号。
一个区间$[l，r]$的权值定义为其中所有$a$ 元素的平均值。
小M想知道所有好的区间中,a元素平均值最大的区间的平均值是多少,你只需要将答案下取整保留至整数。如果不存在好的区间，请你输出-1。

Input
本题共有 $T$ 组数据。
第一行包含一个正整数，表示$T$。
之后对于每组数据,第一行包含2个正整数 $N,k$。
第二行包含$n$ 个整数，第$i$个表示$a_i$.
第三行包含$n$ 个整数，第$i$个表示$p_i$.
评测数据规模：对于所有测评数据，$1≤ \sum_{i=1}^{T} N_i ≤ 123456,0 ≤p_i,k, a_i ≤ 987654321$

Output

对于每组数据输出一行，输出  1 个整数，表示最终答案。

Sample Input
3
3 1
1 2 3
1 1 2
5 6
7 1 2 4 5
1 4 2 5 7
8 1234567
1 2 3 4 5 6 7 8
8 7 6 5 4 3 2 1

Sample Output
2
3
-1