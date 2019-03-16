# Leetcode 219(Contains Duplicate II)

## 题目链接
[Contains Duplicate II](https://leetcode-cn.com/classic/problems/contains-duplicate-ii/description/)

## 算法思想

### 方法1：
*Time:O(nlgn),Space:O(n)*

- 存放数组中每个元素与它对应的索引对，放在一个vector<pair<int,int>> vec中,第一个存放元素的值，第二个存放元素的索引。
- 对vec稳定排序，排序的标准是元素的值
- 遍历vec，如果vec[i]与vec[i+1]的first相当，则比较second是否满足条件

### 方法1代码：
```
	
	class Solution {
		public:
		    bool containsNearbyDuplicate(vector<int>& nums, int k) {
		        vector<pair<int,int>> vec;
		        for(int i=0;i<nums.size();++i){
		            vec.push_back(make_pair(nums[i],i));
		        }
		        stable_sort(vec.begin(),vec.end(),cmp);
		        for(int i=0;i+1<vec.size();++i){
		            if(vec[i].first==vec[i+1].first){
		                if(abs(vec[i].second-vec[i+1].second)<=k){
		                    return true;
		                }
		            }
		        }
		        return false;
		    }
	    static  bool cmp(const pair<int,int>& p1,const pair<int,int>& p2){
	        return p1.first<p2.first;
	    }
};

	


```


