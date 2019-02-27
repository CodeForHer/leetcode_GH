# Leetcode 209(Minimum Size Subarray Sum)

## 题目链接
[Minimum Size Subarray Sum](https://leetcode-cn.com/problems/minimum-size-subarray-sum/description/)

## 算法思想

### 方法1：
*Time:O(n^3),Space:O(1)*

- 暴力求解，leetcode会超出时间限制

### 方法1代码：
```

	int minSubArrayLen(int s, vector<int>& nums) {
        int count_num = INT_MAX;
        for(int i=0;i<nums.size();++i){
            for(int j=i;j<nums.size();++j){
                int sum = 0;
                for(int k=i;k<=j;++k){
                    sum+=nums[k];
                }
                if(sum>=s){
                    if(j-i+1<count_num){
                        count_num=j-i+1;
                    }
                }
            }
        }
        if(count_num==INT_MAX){
            return 0;
        }
        else{
            return count_num;
        }
    }


```
### 方法2：
*Time:O(n^2),Space:O(n)*

- 同样采用暴力求解的方法，只不过先存储上数组各部分的和，用sum[i]表示数组的前i个元素之和，之后再遍历数组，求得结果

### 方法2代码：

```

	int minSubArrayLen2(int s, vector<int>& nums){
        vector<int> sum(nums.size()+1,0);
        int count_num = INT_MAX;
        for(int i=1;i<=nums.size();++i){
            sum[i]=sum[i-1]+nums[i-1];
        }
        for(int i=0;i<nums.size();++i){
            for(int j=i+1;j<=nums.size();++j){
                if(sum[j]-sum[i]>=s){
                    if(j-i<count_num){
                        count_num = j-i;
                    }
                }
            }
        }
        if(count_num==INT_MAX){
            return 0;
        }
        else{
            return count_num;
        }
    }

```
### 方法3：
*Time:O(n),Space:O(1)*

- 采用滑动窗口的思想，[l,r]这个窗口中，若sum<s,则向右移动r，观察此时的sum值是否符合条件，符合则观察窗口中数组的长度，与最短长度对比；若不符合条件，则向左移动l，sum值减去对应的元素，此时同样观察sum值是否符合条件。


### 方法3代码：
```

	int minSubArrayLen3(int s, vector<int>& nums){
	        int l=0,r=-1;
	        int sum = 0;
	        int len = nums.size()+1;
	        while(l<nums.size()){
	            if(r<(int)(nums.size()-1)&&sum<s){
	                r++;
	                sum+=nums[r];
	            }
	            else{
	                sum-=nums[l];
	                l++;
	            }
	            if(sum>=s){
	                if(r-l+1<len){
	                    len = r-l+1;
	                }
	            }
	        }
	        if(len==nums.size()+1){
	            return 0;
	        }
	        else{
	            return len;
	        }
	    }
```
#### 注意：
- 方法3代码中，第六行：r<(int)(nums.size()-1)，r是个整形负值-1，nums.size()-1是个无符号数，这时是补码比较，r(=-1)>(nums.size()-1)，会导致错误的结果，因此要将(nums.size()-1)强转为int。