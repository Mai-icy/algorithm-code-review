# 题解

对于这道题，我们可以分析几种情况，若给定两人的区间，区间在什么情况下才能有一次打招呼。
对于区间[1, 5], [3, 7]这两个区间就无法相遇，但如果是[1, 9], [3, 7]便可以相遇，总结规律可以发现，只有遇到区间的包含，两者才会相遇，对于区间的相关问题，我们建议对起始标坐标进行排序。

[1, 9], [3, 7], [4, 6], [5, 8]
根据这个顺序排序后，我们可以知道，前面的区间由于起始位置前，所以只有他们会 包含后面的区间。
现在进行一次按顺序的遍历，遍历到一个人时，将这个人的终点加入容器，然后再查看容器中有多少大于它的值，这个人就会与他们相遇一次。

这题实际上就是在问
9, 7, 6, 8的逆序数，求逆序数可以用有序集合
```c++
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

```


