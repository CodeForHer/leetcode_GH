# Leetcode 18(Four Sum)

## 题目链接
[Four Sum](https://leetcode-cn.com/classic/problems/4sum/description/)

## 算法思想

### 方法1：
*Time:O(n^3),Space:O(n)*

- 思路和3 sum类似，结果分情况讨论：1.四个元素全部相同；2.三个元素相同；3.两个元素相同，另外两个也相同；4.两个元素相同，另外两个元素不同；5.四个元素全部不相同
- 首先要对原数组排序，并统计元素的出现频率
- 之后要去掉数组中的重复元素，分情况讨论

### 方法1代码：
```


	vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> res;
        unordered_map<int,int> freq;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();++i){
            freq[nums[i]]++;
        }
        nums.erase(unique(nums.begin(),nums.end()),nums.end());

        int temp = target/4;
        if(temp*4==target&&freq[temp]>=4){
            vector<int> part = {temp,temp,temp,temp};
            res.insert(part);
        }

        for(int i=0;i<nums.size();++i){
            for(int j=i+1;j<nums.size();++j){
                if(3*nums[i]+nums[j]==target&&freq[nums[i]]>=3){
                    vector<int> part = {nums[i],nums[i],nums[i],nums[j]};
                    res.insert(part);
                }
                if(nums[i]+3*nums[j]==target&&freq[nums[j]]>=3){
                    vector<int> part = {nums[i],nums[j],nums[j],nums[j]};
                    res.insert(part);
                }
            }
        }

        for(int i=0;i<nums.size();++i){
            for(int j=i+1;j<nums.size();++j){
                if(2*nums[i]+2*nums[j]==target&&freq[nums[i]]>=2&&freq[nums[j]]>=2){
                    vector<int> part = {nums[i],nums[i],nums[j],nums[j]};
                    res.insert(part);
                }
            }
        }

        for(int i=0;i<nums.size();++i){
            for(int j=i+1;j<nums.size();++j){
                for(int k=j+1;k<nums.size();++k){
                    if(2*nums[i]+nums[j]+nums[k]==target&&freq[nums[i]]>=2){
                        vector<int> part = {nums[i],nums[i],nums[j],nums[k]};
                        res.insert(part);
                    }

                    if(nums[i]+2*nums[j]+nums[k]==target&&freq[nums[j]]>=2){
                        vector<int> part = {nums[i],nums[j],nums[j],nums[k]};
                        res.insert(part);
                    }

                    if(nums[i]+nums[j]+2*nums[k]==target&&freq[nums[k]]>=2){
                        vector<int> part = {nums[i],nums[j],nums[k],nums[k]};
                        res.insert(part);
                    }
                }
            }
        }

        for(int i=0;i<nums.size();++i){
            for(int j=i+1;j<nums.size();++j){
                for(int k=j+1;k<nums.size();++k){
                    int c = target-nums[i]-nums[j]-nums[k];
                    if(freq[c]>0&&c>nums[k]){
                        vector<int> part = {nums[i],nums[j],nums[k],c};
                        res.insert(part);
                    }
                }
            }
        }
        vector<vector<int>> res_final(res.begin(),res.end());
        return res_final;
    }


```

