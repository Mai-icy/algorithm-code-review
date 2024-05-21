# F. Equal XOR Segments

如果可以将数组分成 $k>1$ 部分，使得每个部分的值的 [bitwise XOR](http://tiny.cc/xor_wiki_eng)都相等，那么我们就可以称这个数组为 $x_1,\dots,x_m$ 有趣的数组。

更正式地说，你必须将数组 $x$ 分成 $k$ 个连续的部分， $x$ 中的每个元素都必须准确地**属于 $1$ 个部分。设 $y_1,\dots,y_k$ 分别是各部分元素的 XOR。那么 $y_1=y_2=\dots=y_k$ 必须满足。

例如，如果是 $x = [1, 1, 2, 3, 0]$ ，则可以将其拆分如下： $[\color{blue}1], [\color{green}1], [\color{red}2, \color{red}3, \color{red}0]$ .事实上是 $\color{blue}1=\color{green}1=\color{red}2 \oplus \color{red}3\oplus \color{red}0$ 。

给你一个数组 $a_1,\dots,a_n$ 。你的任务是回答 $q$ 个查询：

- 对于固定的 $l$ ， $r$ ，判断子数组 $a_l,a_{l+1},\dots,a_r$ 是否有趣。


**输入**

第一行包含一个整数 $t$ ( $1\le t\le 10^4$ )--测试用例数。( $1\le t\le 10^4$ ) - 测试用例的数量。

每个测试用例的第一行包含两个整数 $n$ 和 $q$ ( $2 \le n \le 2 \cdot 10^5$ , $1 \le q \le 2 \cdot 10^5$ )--分别是数组中的元素个数和查询次数。

下一行包含 $n$ 个整数 $a_1,\dots,a_n$ ( $0 \le a_i < 2^{30}$ ) - 数组元素。

接下来的每行 $q$ 包含两个整数 $l$ 和 $r$ ( $1 \le l < r \le n$ )，分别描述查询。

保证所有测试用例中 $n$ 的总和不超过 $2 \cdot 10^5$ 。

保证所有测试用例中 $q$ 的总和不超过 $2 \cdot 10^5$ 。


**输出**

对于每个查询，如果子数组有趣，则输出 "YES"，否则输出 "NO"。

您可以在任何情况下输出 "YES "和 "NO"(例如，字符串 "yES"、"yes "和 "Yes "将被识别为正确答案)。

