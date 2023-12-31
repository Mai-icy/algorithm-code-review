# F. Greetings

数线上有 $n$ 个人； $i$ th 的人在点 $a_i$ ，想去点 $b_i$ 。对于每个人来说， $a_i \lt; b_i$ 以及所有人的起点和终点都是不同的。(也就是说，所有的 $2n$ 数 $a_1, a_2, \dots, a_n, b_1, b_2, \dots, b_n$ 都是不同的)。

所有的人将以每秒 $1$ 个单位的速度同时开始移动，直到到达终点 $b_i$ 。当两个人在同一点相遇时，他们会互相问候一次。会有多少次打招呼？

请注意，即使一个人到达了最终点，他仍然可以向其他人打招呼。

**输入**

输入的第一行包含一个整数 $t$ ( $1 \le t \le 10^4$ ) - 测试用例的数量。测试用例说明如下。

每个测试用例的第一行包含一个整数 $n$ ( $1 \le n \le 2 \cdot 10^5$ ) - 人数。

然后是 $n$ 行，其中 $i$ 行包含两个整数 $a_i$ 和 $b_i$ 。( $-10^9 \leq a_i\lt; b_i \leq 10^9$ ) - 每个人的起始位置和结束位置。

对于每个测试用例，所有的 $2n$ 数字 $a_1, a_2, \dots, a_n, b_1, b_2, \dots, b_n$ 都是不同的。

所有测试用例的 $n$ 之和不超过 $2 \cdot 10^5$ 。

**输出**

为每个测试用例输出一个整数，表示将发生的问候次数。