
# D. Set To Max

给你两个长度为 $n$ 的数组 $a$ 和 $b$ 。

您可以执行以下操作若干次（可能为零）：

1. 选择 $l$ 和 $r$ ，使得 $1 \leq l \leq r \leq n$ .
2. 让 $x=\max(a_l,a_{l+1},\ldots,a_r)$ .
3. 对于所有的 $l \leq i \leq r$ ，设置 $a_i := x$ 。

判断能否使数组 $a$ 等于数组 $b$ 。


**输入**

每个测试包含多个测试用例。第一行包含一个整数 $t$ ( $1 \leq t \leq 10^4$ ) - 测试用例的数量。测试用例说明如下。

每个测试用例的第一行包含一个整数 $n$ ( $1 \le n \le 2 \cdot 10^5$ ) - 数组的长度。

第二行包含 $n$ 个整数 $a_1, a_2, \ldots, a_n$ （ $1 \le a_i \le n$ ）--数组的元素。( $1 \le a_i \le n$ ) -数组 $a$ 的元素。

第三行包含 $n$ 个整数 $b_1, b_2, \ldots, b_n$ - 数组 $a$ 的元素。( $1 \le b_i \le n$ ) - 数组 $b$ 的元素。

保证所有测试用例中 $n$ 的总和不超过 $2 \cdot 10^5$ 。


**输出**

对于每个测试用例，如果可以使用任意数量的操作将 $a$ 变成 $b$ ，则输出 "是"（不带引号），否则输出 "否"（不带引号）。

您可以在任何情况下输出 "YES "和 "NO"（例如，字符串 "yES"、"yes "和 "Yes "将被视为肯定回答）。


