# Leetcode 16(3Sum-closet)

## 题目链接
[3Sum-closet](https://leetcode-cn.com/classic/problems/3sum-closest/description/)

## 算法思想

### 方法1：
*Time:O(n^3),Space:O(1)*

- 暴力求解，遍历所有的三个数的组合组合

### 方法1代码：
```
	
	int threeSumClosest(vector<int>& nums, int target) {
	        int closet = INT_MAX;
	        int sum = 0;
	        for(int i=0;i<nums.size();++i){
	            for(int j=i+1;j<nums.size();++j){
	                for(int k=j+1;k<nums.size();++k){
	                    int sum_temp = nums[i]+nums[j]+nums[k];
	                    if(abs(sum_temp-target)<closet){
	                        closet = abs(sum_temp-target);
	                        sum = sum_temp;
	                    }
	                }
	            }
	        }
	        return sum;
	    }

	


```
### 方法2：
*Time:O(n^2),Space:O(1)*

- 设数组长度为n，对于数组每一个元素nums[i]，计算t=target-nums[i]，在nums[i+1]~nums[n-1]寻找和最接近t的两个元素。
- 采用对撞指针的方法寻找第一步中的元素。在nums[i+1]~nums[n-1]有序的情况下，设l为左边界即i+1，r为右边界即n-1。如果nums[l]+nums[r]正好等于t，则返回这个值；如果nums[l]+nums[r]与t的差值（绝对值）要比当前的最小差值要小，则更新当前最小差值与结果；如果nums[l]+nums[r]小于t，则l向右移动；否则r向左移动。

### 方法2代码：

```

	int threeSumClosest2(vector<int>& nums, int target) {
	        sort(nums.begin(),nums.end());
	        int diff = abs(nums[0]+nums[1]+nums[2]-target);
	        int res = nums[0]+nums[1]+nums[2];
	        for(int i=0;i<nums.size();++i){
	            int l = i+1,r = nums.size()-1;
	            int t = target - nums[i];
	            while(l<r){
	                if(nums[l]+nums[r]==t){
	                    return nums[i]+nums[l]+nums[r];
	                }
	                else{
	                    if(abs(nums[l]+nums[r]-t)<diff){
	                        diff = abs(nums[l]+nums[r]-t);
	                        res = nums[i] + nums[l] +nums[r];
	                    }
	                }
	                if(nums[l]+nums[r]<t)
	                    ++l;
	                else
	                    --r;
	            }
	        }
	        return res;
    }



```

