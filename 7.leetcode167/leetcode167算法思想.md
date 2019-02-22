# leetcode 167(Two sum II)

## 题目链接
[Two sum II](https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/description/)

## 算法思想

### 方法1：
*Time:O(n^2),Space:O(1)*

- 采用暴力求解的方法
- 遍历数组的所有组合

### 方法1代码：

```

	vector<int> twoSum(vector<int>& numbers, int target) {
	        vector<int> res;
	        for(int i=0;i<numbers.size();++i){
	            for(int j=i+1;j<numbers.size();++j)
	            {
	                if(numbers[i]+numbers[j]==target)
	                {
	                    res.push_back(i+1);
	                    res.push_back(j+1);
	                    return res;
	                }
	            }
	        }
	        return res;
	    }

```

### 方法2：
*Time:O(nlgn),Space:O(1)*

- 对于每个元素，利用二分查找搜索target-nums[i]

### 方法2代码：

```

	vector<int> twoSum(vector<int>& numbers, int target){
	        vector<int> res;
	        for(int i=0;i<numbers.size();++i){
	            int j = BinarySearch(numbers,target-numbers[i],i);
	            if(j!=-1){
	                res.push_back(i+1);
	                res.push_back(j+1);
	                break;
	            }
	        }
	        sort(res.begin(),res.end());
	        return res;
	    }

	    int BinarySearch(vector<int>& nums,int target,int i){
	        int low = 0,high = nums.size()-1;
	        while(low<=high){
	            int mid = low+(high-low)/2;
	            if((nums[mid]==target)&&(mid!=i)){
	                return mid;
	            }
	            else{
	                if(nums[mid]<target){
	                    low=mid+1;
	                }
	                else{
	                    high =mid-1;
	                }
	            }
	        }
	        return -1;
	    }
```

###方法3：
*Time:O(n),Space:O(1)*

- 对撞指针的思路
- Step1: 初始化两个指针i和j，分别指向数组的首端和尾端
- Step2: 若nums[i]+nums[j]>target,则j--；若nums[i]+nums[j]<target，则i++；若nums[i]+nums[j]=target，则返回结果

### 方法3代码：

```

	vector<int> twoSum3(vector<int>& numbers, int target){
        int i=0,j=numbers.size()-1;
        vector<int> res;
        while(i<j){
            int sum =numbers[i]+numbers[j];
            if(sum==target){
                res.push_back(i+1);
                res.push_back(j+1);
                break;
            }
            else{
                if(sum<target){
                    ++i;
                }
                else{
                    --j;
                }
            }
        }
        return res;
    }
```