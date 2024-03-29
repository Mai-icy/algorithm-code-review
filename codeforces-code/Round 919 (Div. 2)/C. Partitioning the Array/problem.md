# C. Partitioning the Array

艾伦有一个数组 $a_1, a_2,\ldots,a_n$ 。对于每个是 $n$ 除数的正整数 $k$ ，艾伦都会做如下运算：

- 他将数组分割成长度为 $k$ 的 $\frac{n}{k}$ 个互不相交的子数组。换句话说，他将数组划分为以下子数组：
    $$
    [a_1,a_2,\ldots,a_k],[a_{k+1}, a_{k+2},\ldots,a_{2k}],\ldots,[a_{n-k+1},a_{n-k+2},\ldots,a_{n}]
    $$
    
- 如果存在某个正整数 $m$ ( $m \geq 2$ )，使得他将数组中的每个元素除以 $m$ 后的余数都替换为该元素，则所有子数组都相同，则艾伦得一分。

帮助艾伦找出他将获得的分数。

**输入**

每个测试由多个测试用例组成。第一行包含一个整数 $t$ ( $1 \leq t \leq 10^4$ ) - 测试用例的个数。测试用例说明如下。

每个测试用例的第一行包含一个整数 $n$ ( $1 \leq n \leq 2\cdot10^5$ ) - 数组的长度 $a$ 。

每个测试用例的第二行包含 $n$ 个整数 $a_1, a_2,\ldots, a_n$ ( $1 \leq a_i \leq n$ ) - 数组 $a$ 的元素。

保证所有测试用例的 $n$ 之和不超过 $2 \cdot 10^5$ 。

**输出**

对于每个测试用例，输出一个整数 - 艾伦将获得的分数。