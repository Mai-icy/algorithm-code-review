# 子集整除

Time Limit (Java / Others)
2000 / 1000 MS
Memory Limit (Java / Others)
327680 / 327680 K

Problem Description

给定长度为 $N$ 的序列 $a$ 和定值 $k，p$。对于一个序列$b$，其权值为$[ \frac{sum(b)}{k}]$。
小M想请你求解序列a的所有非空子序列的权值和 , 答案对p取模。
题目不保证模p意义下存在k的逆元。

Input

第一行包含 3 个正整数 $N,k,p$。第二行包含$N$个正整数,第$i$个表示$a_i$。
评测数据规模：对于所有测评数据，$1 ≤ N,k ≤ 4321, 1 < a_i,p ≤ 987654321$。

Output

输出共 1 行，输出 1 个整数，表示最终答案。

Sample Input
3 3 9
1 2 1

Sample Output
3