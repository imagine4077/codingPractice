LIS 最大递增子序列问题
====

LIS问题是DP问题的一个经典习题.有三种解法可以用于解此问题.

例子:给定序列A={5,6,7,1,2,8},则最大递增子序列为{5,6,7,8},长度为4.

#### 1.最长公共子序列(LCS)方法

对A排序得到序列B={1,2,5,6,7,8},然后对A和B求最长公共子序列. 求LCS的方法也是运用了DP算法,详细内容可以我参见之前的代码[https://github.com/imagine4077/codingPractice/tree/master/fundamental_algorithm/DynamicProgramming/LCS%E6%9C%80%E9%95%BF%E5%85%AC%E5%85%B1%E5%AD%90%E5%BA%8F%E5%88%97](https://github.com/imagine4077/codingPractice/tree/master/fundamental_algorithm/DynamicProgramming/LCS%E6%9C%80%E9%95%BF%E5%85%AC%E5%85%B1%E5%AD%90%E5%BA%8F%E5%88%97).

#### 2. O( n^2 )算法

参见代码powerN.cpp.

算法思想为: 遍历A中的每个元素e, 寻找以e为结尾的最长子序列.

开一个和A一样长的数组dp(A.size(),1),当指向A[i]时,找到满足(j<i&&A[j]<A[i])的最大dp[j].

#### 3. O(nlog(n))算法

参见代码nlogn.cpp.

算法思想: 记录长度为i的子列的最小结尾值.

分步的例子可以看这里:[http://www.cnblogs.com/liyukuneed/archive/2013/05/26/3090402.html](http://www.cnblogs.com/liyukuneed/archive/2013/05/26/3090402.html)

