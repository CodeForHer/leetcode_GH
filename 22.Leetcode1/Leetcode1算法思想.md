# Leetcode 1(Two Sum）

## 题目链接
[Two Sum](https://leetcode-cn.com/classic/problems/two-sum/description/)

## 算法思想

### 方法1：
*Time:O(n),Space:O(n)*

- 设置一个哈希表，用来动态地存放数组元素的值与该元素出现的位置
- 遍历数组nums时，如果在哈希表中找不到target-nums[i]对应的key值，则哈希表中添加nums[i]-i与i的键值对；找到则返回对应位置i与target-nums[i]对应的key值

### 方法1代码：
```

	vector<int> twoSum(vector<int>& nums, int target) {
	        unordered_map<int,int> pos;
	        vector<int> res;
	        for(int i=0;i<nums.size();++i){
	            if(pos.find(target-nums[i])==pos.end()){
	                pos[nums[i]]=i;
	            }
	            else{
	                res.push_back(i);
	                res.push_back(pos[target-nums[i]]);
	                break;
	            }
	        }
	        return res;
	    }
	

```

### 方法2：
*Time:O(nlgn),Space:O(n)*

- 将数组中所有元素的值与该元素出现的位置都保存在一个multimap中（multimap允许健值重复）
- 之后用这个multimap来构建一个vector，并对vector排序（根据每个pair的first来排序）
- 采用对撞指针的方法，在vector中找到正确的结果


### 方法2代码：
```


	vector<int> twoSum2(vector<int>& nums, int target) {
        multimap<int,int> pos;
        vector<int> res;
        for(int i=0;i<nums.size();++i){

            pos.insert(make_pair(nums[i],i));
        }
        vector<pair<int,int>> vec(pos.begin(),pos.end());
        sort(vec.begin(),vec.end(),cmp);
        int i=0,j=vec.size()-1;
        while(i<j){
            if(vec[i].first+vec[j].first<target)
                ++i;
            else
            {
                if(vec[i].first+vec[j].first>target)
                {
                    --j;
                }
                else
                {
                    res.push_back(vec[i].second);
                    res.push_back(vec[i].second);
                    break;
                }
            }
        }
        return res;
    }

    static bool cmp(pair<int,int>& p1, pair<int,int>& p2){

        return p1.first < p2.first;
    }


```
