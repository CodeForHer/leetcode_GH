# Leetcode 15(Three Sum)

## 题目链接
[Three Sum](https://leetcode-cn.com/classic/problems/3sum/description/)

## 算法思想

### 方法1：
*Time:O(n^2),Space:O(n)*

- 满足条件的结果可能有三种情况：1.三个元素全部相同，即都是0；2.三个元素中有两个元素相同；3.三个元素都不相同
- 针对第一种情况，若数组中存在3个或3个以上的零元素，即满足。第二种情况，若nums[i]*2+nums[j]==0并且数组中存在2个或2个以上nums[i]，即满足。第三种情况，数组中存在0-nums[i]-nums[j]，即满足
- 根据以上思想，先设置一个哈希表，用来统计数组中元素的出现频率，之后对数组排序并且去掉数组中的重复元素，最后双循环遍历数组，根据上面的条件找出结果

### 方法1代码：
```

		vector<vector<int>> threeSum(vector<int>& nums) {
	        unordered_map<int,int> freq;
	        vector<vector<int>> res;
	        for(int i=0;i<nums.size();++i){
	            freq[nums[i]]++;
	        }
	        sort(nums.begin(),nums.end());
	        vector<int>::iterator iter = unique(nums.begin(),nums.end());
	        nums.erase(iter,nums.end());
	        if(freq[0]>=3){
	            res.push_back({0,0,0});
	        }
	
	        for(int i=0;i<nums.size();++i){
	            for(int j=i+1;j<nums.size();++j){
	                if(nums[i]*2+nums[j]==0&&freq[nums[i]]>=2){
	                    res.push_back({nums[i],nums[i],nums[j]});
	                }
	                if(nums[i]+nums[j]*2==0&&freq[nums[j]]>=2){
	                    res.push_back({nums[i],nums[j],nums[j]});
	                }
	                int c = 0-nums[i]-nums[j];
	                if(c>nums[j]&&freq[c]>0){
	                    res.push_back({nums[i],nums[j],c});
	                }
	            }
	        }
	        return res;
	    }


```

### 需要注意的地方
- `if(c>nums[j]&&freq[c]>0)` 中，c要求大于nums[j]，因为数组已经被排序，这样是保证在nums[j]的右边寻找，不会重复地计入结果