# G. Moving Platforms

有一个游戏，你需要穿过一个迷宫。迷宫由 $n$ 个平台组成，由 $m$ 条通道连接。

每个平台都处于某个级别 $l_i$ ，是一个从 $0$ 到 $H - 1$ 的整数。在一个步骤中，如果你目前在平台 $i$ 上，你可以留在上面，或者移动到另一个平台 $j$ 上。要移动到平台 $j$ ，它们必须通过通道相连，而且它们的级别必须相同，即 $l_i = l_j$ 。

每走一步，所有平台的水平面都会发生变化。对于所有的 $i$ ，平台 $i$ 的新水平面计算为 $l'_i = (l_i + s_i) \bmod H$ 。

你从平台 $1$ 开始。求到达平台 $n$ 所需的最少步数。

**输入**

第一行输入包含一个整数 $t$ ( $1 \le t \le 10^4$ ) - 测试用例的数量。然后是测试用例的描述。

每个测试用例的第一行包含三个整数 $n$ 、 $m$ 和 $H$ （ $2 \le n \le 10^5$ 、 $1 \le m \le 10^5$ 、 $1 \le H \le 10^9$ ）。

第二行包含 $n$ 个整数 $l_i$ ，即每个平台的初始级别（ $0 \le l_i \le H-1$ ）。

第三行包含 $n$ 个整数 $s_i$ ，即每个平台的高度变化（ $0 \le s_i \le H-1$ ）。

接下来的 $m$ 行包含对通道的描述。每个通道都是一对整数--由通道连接的平台。每对平台之间最多只有一条通道连接，没有任何通道连接平台与平台之间。

所有测试的 $n$ 之和不超过 $10^5$ ，所有测试的 $m$ 之和不超过 $10^5$ 。

**输出**

对于每个测试用例，打印一个整数，即从平台 $1$ 到平台 $n$ 所需的最少步骤数。

如果无法到达平台 $n$ ，则打印 $-1$ 。

Example
inputCopy
3
3 3 10
1 9 4
2 3 0
1 2
3 2
1 3
2 1 10
1 2
4 6
1 2
8 7 25
22 14 5 3 10 14 11 1
9 5 4 10 7 16 18 18
2 8
6 3
3 5
7 5
2 6
1 4
4 7
outputCopy
6
-1
52


**Note**

This is how levels of the platforms change, and what actions we need to perform in the first example.

|  | **Platform 1** | **Platform 2** | **Platform 3** | **Action** |
|  --- | --- | --- | --- | ---  |
| **Step 1** | 1 | 9 | 4 | Stay on the platform 1 |
| **Step 2** | 3 | 2 | 4 | Stay on the platform 1 |
| **Step 3** | **5** | **5** | 4 | Move to the platform 2 |
| **Step 4** | 7 | 8 | 4 | Stay on the platform 2 |
| **Step 5** | 9 | 1 | 4 | Stay on the platform 2 |
| **Step 6** | 1 | **4** | **4** | Move to the platform 3 |