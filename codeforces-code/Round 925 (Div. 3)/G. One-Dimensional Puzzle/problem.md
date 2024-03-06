# G. One-Dimensional Puzzle

您有一个一维拼图，所有元素都需要排成一行，并相互连接。所有拼图元素都是完全白色的，只有当它们的形状不同时才能相互区分。

每个元素的顶部和底部都有直线边框，左右两侧都有连接点，每个连接点都可以是一个突出物或一个凹槽。不能***旋转元素。

可以看出，元素的类型正好有 $4$ 种。如果左边元素的右边连接点与右边元素的左边连接点相对，那么两个元素就可以连接起来。

![](https://espresso.codeforces.com/d862915ed3dc627101b0e632c1c778b818648879.png) 所有可能的元素类型。

谜题中每种类型包含 $c_1, c_2, c_3, c_4$ 个元素。如果您成功地将所有元素组合成一条长链，那么谜题就算完成了。您想知道有多少种方法可以做到这一点。

**输入**

第一行包含一个整数 $t$ ( $1 \le t \le 2 \cdot 10^5$ ) - 输入测试用例的数量。下面是测试用例的说明。

每个测试用例的描述分别包含 $4$ 个整数 $c_i$ ( $0 \le c_i \le 10^6$ ) - 每种类型的元素个数。

保证所有测试用例的 $c_i$ 之和不超过 $4 \cdot 10^6$ 。

**输出**

对于每个测试用例，打印一个整数 - 解题的可能方法数。

如果存在 $i$ ，且这两种方法中位于 $i$ 位置的元素类型不同，则认为这两种方法是不同的。

由于答案可能非常大，因此输出答案的模数 $998244353$ 。

如果无法解开谜题，则打印 $0$ 。



Example
```
11
1 1 1 1
1 2 5 10
4 6 100 200
900000 900000 900000 900000
0 0 0 0
0 0 566 239
1 0 0 0
100 0 100 0
0 0 0 4
5 5 0 2
5 4 0 5
```
output
```
4
66
0
794100779
1
0
1
0
1
36
126
```