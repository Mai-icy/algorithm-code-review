分类：字典树 数据结构

## 题解
第一步是对题目的转化，对于 
`C(aabc, cddd) = C(aa, dd) = 4`
转化这个计算即 'S(aabc, cddd)为头尾相同字符数量，此处为2'
`C = len(s1) + len(s2) - 2 * S(aabc, cddd)= 4 + 4 - 2 * 2 =  4`

如果现在有三个字符串s1, s2, s3
RES = C(s1, s2) + C(s1, s3) + C(s2, s1) + C(s2, s3) + C(s3, s1)+ C(s3, s2)
= 4 * (len(s1) + len(s2) + len(s3)) - 所有前缀个数 * 后缀个数 * (前缀后缀长度)

当有n个字符串
RES = 2(n-1) * (len(s1) + len(s2) + len(s3)) - 所有前缀个数 * 后缀个数 * (前缀后缀长度)


解1：
直接使用哈希表，记录所有的前缀的个数和后缀的个数，按照以上的公式运算

```python
#!/usr/bin/env python
# -*- coding:utf-8 -*-
string_num = int(input())
strings = [input() for _ in range(string_num)]

prefix_dict = {}

for str1 in strings:
    for end in range(1, len(str1) + 1):
        if str1[:end] in prefix_dict:
            prefix_dict[str1[:end]] += 1
        else:
            prefix_dict[str1[:end]] = 1


result = 2 * string_num * sum(len(s) for s in strings)

for str1 in strings:
    re_str = str1[::-1]
    for end in range(1, len(str1) + 1):
        if re_str[:end] in prefix_dict:
            result -= prefix_dict[re_str[:end]] * 2
        else:
            break

print(result)
```
这是一个足以说明含义的python代码，它是正确的，但不能通过，由于内存和时间要求，不能满足条件
但算法思路是正确的，使用c++的哈希表便可通过题目，不过容易被hacked掉，因此可以使用
字典树的数据结构。

解2：使用字典树，详情见字典树博客，思路一致

