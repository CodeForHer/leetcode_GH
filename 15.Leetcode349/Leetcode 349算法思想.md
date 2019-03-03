# Leetcode 349(Intersection of Two arrays)

## 题目链接
[Intersection of Two arrays](https://leetcode-cn.com/problems/intersection-of-two-arrays/description/)

## 算法思想

### 方法1：
*Time:O(nlgn),Space:O(n)*
####注：在set中调用find方法，时间复杂度*O(lgn)*

- 采用c++的set（集合）泛型，特点是里面不存放重复元素
- 初始化两个set，record和result;
- 首先对nums1数组遍历，存入record中。之后对nums2遍历，若其中的元素在record中存在，则说明该元素是两个集合所共有的元素，则放入result中。
- 将result转换为vector返回即可

### 方法1代码：
```

	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> record;
        for(int i=0;i<nums1.size();++i){
            record.insert(nums1[i]);
        }
        set<int> res;
        for(int i=0;i<nums2.size();++i){
            if(record.find(nums2[i])!=record.end()){
                res.insert(nums2[i]);
            }
        }
        vector<int> result;
        for(set<int>::iterator iter = res.begin();iter!=res.end();++iter){
            result.push_back(*iter);
        }
        return result;
    }


```

