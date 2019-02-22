# Leetcode 215(Kth Largest element in an Array)

## 题目链接
[Kth Largest element in an Array](https://leetcode-cn.com/problems/kth-largest-element-in-an-array/description/)

## 算法思想

### 方法1：
*Time:O(nlgn),Space:O(1)*

- 对数组排序，再逆序
- 取第k个元素
### 方法1代码：
```
	
	int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        return nums[k-1];
    }

```
### 方法2：
*Time:O(n),Space:O(1)*

- 采用快速排序的思路
- 在数组中找一个元素作为pivot，使得pivot左边的元素都大于pivot,右边的元素都小于pivot
- 查看pivot在当前数组中的排名rank，如果正好等于k，则返回；若小于k，则在pivot的右边寻找排名k-rank的元素；若大于k，则在pivot的左边寻找排名k的元素

### 方法2代码：
```

	int findKthLargest(vector<int>& nums, int k) {
	        int len = nums.size()-1;
	        return nums[find_pivot_rank(nums,0,len,k)];
	    }

	//find_pivot_rank函数，在区间[left,right]寻找排名为k的元素的索引，k>=1
	int find_pivot_rank(vector<int>& nums,int left,int right,int k)
	    {
	        if(left==right)
	        {
	            return left;
	        }
	//第一个元素作为pivot
	        int pivot=nums[left];
	        int i=left,j=right;
	        while(i<j)
	        {
	//在右边找一个大于pivot的元素j         
				while((i<j)&&(nums[j]<=pivot))
	            {
	                --j;
	            }
	//把它放到i的位置
	            if(i<j)
	            {
	                nums[i]=nums[j];
	                ++i;
	            }
	//在左边找一个小于等于pivot的元素i
	            while((i<j)&&(nums[i]>pivot))
	            {
	                ++i;//
	            }
	//把它放到j的位置
	            if(i<j)
	            {
	                nums[j]=nums[i];
	                --j;
	            }
	        }
	//最后i=j，用来存放pivot
	        nums[i]=pivot;
	//可知pivot在当前数组的排名是i-left+1
	        int cur_rank = i-left+1;
	        if(cur_rank==k)
	        {
	            return i;
	        }
	        else
	        {
	            if(cur_rank<k)
	            {
	                return find_pivot_rank(nums,i+1,right,k-cur_rank);
	            }
	            else
	            {
	                return find_pivot_rank(nums,left,i-1,k);
	            }
	        }
	    }

```
