# Algorithm

1. [DP](#dp)
         1. [Steps](#steps)
2. [Sliding window](#sliding-window)
3. [Backtrace](#backtrace)
         1. [Backtrace v.s. Dynamic Planing](#backtrace-vs-dynamic-planing)
   1. [Binary search](#binary-search)

---------------

## DP

##### Steps

- [source|https://www.bilibili.com/video/BV1xb411e7ww?spm_id_from=333.1007.top_right_bar_window_custom_collection.content.click]
1. 确定状态 : 数组 代表什么（状态）
  - 最后一步
  - 子问题
2. 状态转移方程
  - 根据子问题定义得到
  - ，需要确认 dp[i] 的状态
    - 只和前一个/两个状态有关
      - 一层 loop
      - E.g. [买卖股票](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/solution/mai-mai-gu-piao-wen-ti-by-chen-wei-f-qrz4/)
    - 和前面 i-1 个状态有关
      - 二层 loop
      - E.g. [鸡蛋坠落](https://leetcode.cn/problems/egg-drop-with-2-eggs-and-n-floors/solution/dong-tai-gui-hua-shu-xue-tui-dao-by-tang-1zz1/)
3. 初始条件和边界情况
  - 初始条件：状态方程无法算出 && 又需要定义
  - 边界情况：不要数组越界
4. 计算顺序
  - 利用之前的计算结果
  - 从小到大
  - 从上到下
  - 在计算 f(x) 时，其依赖的 值应该已经确定
重叠子问题、最优子结构、状态转移方程就是动态规划三要素。

## Sliding window

- https://leetcode.cn/problems/longest-substring-without-repeating-characters/solution/hua-dong-chuang-kou-by-powcai/
  - finished LC: 3, 76
- https://leetcode.cn/problems/minimum-window-substring/solution/by-flix-1kac/
  - finished LC: 17.18. Shortest Supersequence LCCI

## Backtrace

- Use one group of status variable to handle all cases.
  - [all composition|https://leetcode-cn.com/problems/permutations/solution/quan-pai-lie-by-leetcode-solution-2/]

##### Backtrace v.s. Dynamic Planing

https://leetcode-cn.com/problems/permutations/solution/hui-su-suan-fa-python-dai-ma-java-dai-ma-by-liweiw/

- Same: 用于求解多阶段决策问题。多阶段决策问题即：
  - 求解一个问题分为很多步骤（阶段）；
  - 每一个步骤（阶段）可以有多种选择。
- Diff: 
  - 动态规划只需要求我们评估最优解是多少，最优解对应的具体解是什么并不要求。因此很适合应用于评估一个方案的效果；
  - 回溯算法可以搜索得到所有的方案（当然包括最优解），但是本质上它是一种遍历算法，时间复杂度很高。

### Binary search

- https://leetcode.cn/problems/maximum-number-of-removable-characters/submissions/391032211/
  1. range `[l, r]`
  2. `while(l <= r)`
  3. `mid = l + (r-l)/2`
  4. `l = m+1` or `r = m-1`
