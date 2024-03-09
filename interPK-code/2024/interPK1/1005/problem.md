# 异或

Time Limit (Java / Others)
16000 / 8000 MS
Memory Limit (Java / Others)
827680 / 827680 K

Problem Description
给定大小为n的数组$a_0, \dots, a_{n-1}$。
构造b数组, 任意 $0 ≤ x < n$有$b_{0,x}=a_x$,并对于任意 $x > 0,x+y<n-1$,有$b_{x,y}= b_{x-1,y}⊕ b_{x-1,y+1}$
有$q$ 次询问，询问每次给出$（x，y）$，请你输出 $b_{x,y}$ 的值。

Input
第一行包含一个正整数表示 $n$。
第二行给出$n$个数字$a_0,\dots,a_{n-1}$。
第三行包含一个正整数表示$q$。
之后$q$行，每行给定2 个整数，给出$x,y$表示一组询问,满足$0≤x+y<n$。
评测数据规模：对于所有测评数据, $n,q ≤ 3 × 10^5, a_i ≤ 10^9$

Output
输出 $q$ 行，表示 $q$ 次询问的答案。

Sample Input
4
9 5 9 2
4
1 2
0 0
0 2
3 0

Sample Output
11
9
9
7
