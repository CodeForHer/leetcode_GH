# Leetcode 350(Intersection of two arrays ii)

## 题目链接
[Intersection of two arrays ii](https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/description/)

## 算法思想

### 方法1：
*Time:O(n),Space:O(n)*

- Step1:为nums1数组设置一个哈希表，元素值作为键值，元素的频率作为key值
- Step2:遍历nums2数组，若哈希表中对应元素的key值不为0，则加入结果数组中，此时哈希表该元素对应的key值减一

### 方法1代码：
```

	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> freq;
        vector<int> result;
        for(int i=0;i<nums1.size();++i){
            freq[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();++i){
            if(freq[nums2[i]]!=0){
                result.push_back(nums2[i]);
                --freq[nums2[i]];
            }
        }
        return result;
    }


```
