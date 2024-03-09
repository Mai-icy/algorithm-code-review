https://acm.hdu.edu.cn/contest/problem?cid=1118&pid=1006

给定长度为 n 的序列 w，初始时有数字 1 到 n，重复执行以下操作 n 次：>假设当前未被删除的数为[21...im],那么当前回合有,i的概率在序列中删除数字认。Z1=ز Wiز显然，每轮恰好会删除一个数字，且n 轮以后所有数字均会被删除。现在,小M知道了最终的删除顺序,但他没有记录下这一结果,只记得其中数字1是最后被删除的,且他记得数字i e [2,n]的删除时间早于数字pi,其中pi E [1,i),小M想知道这一事件发生的概率。答案对 998244353 取模。

第一行包含 1 个正整数 n。第二行包含n个整数,表示wi。第三行包含n-1个整数，其中第i个整数表示pi1。评测数据规模：对于所有测评数据，1<wi<5000,1<n,1<5000.

