# Leetcode 26(删除排序数组中的重复项)
## 题目链接
[26. 删除排序数组中的重复项](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/description/)

## 算法思想
### 方法1：
*Time O(n),Space O(1)*

- Step1: 设置一个标记k，使得[0,k)存放着不重复的元素
- Step2: 遍历数组，若当前元素与nums[k-1]不同，则nums[k]置为该元素
- Step3: 返回k即可