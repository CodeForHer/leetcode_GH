# Leetcode 283(moves zeros)


## 题目链接
[move zeros](http://leetcode-cn.com/problems/move-zeroes/ "leetcode 283")


## 算法思想
### 方法1：

*Time:O(n),Space:O(n)*

- step1: 把数组a中的非零元素放到另一个数组b中
- step2: 把b中的元素按次序复制到a中
- step3: a中其他位置的元素设置为
### 方法1代码：
```

 	void moveZeroes1(vector<int>& nums)
    {
        vector<int> temp ;
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]!=0)
            {
                temp.push_back(nums[i]);
            }
        }
        for(int i=0;i<temp.size();++i)
        {
            nums[i] = temp[i];
        }
        for(int i=temp.size();i<nums.size();++i)
        {
            nums[i] = 0;
        }
    }

```
### 方法2：
*Time:O(n),Space:O(1)*

- step1: 设置一个变量k,初始化为0，用来记录数组中的非零元素，使得[0,k)存放数组中的非零元素
- step2: 遍历数组，遇到非零元素，则放到k的位置，之后k自增
- step3: 从位置k开始，将数组的元素置为0

### 方法2代码：
```

	void moveZeroes2(vector<int> &nums)
	    {
	        int k = 0;
	        for(int i=0;i<nums.size();++i)
	        {
	            if(nums[i]!=0)
	            {
	                nums[k++]=nums[i];
	            }
	        }
	        for(int i=k;i<nums.size();++i)
	        {
	            nums[i]=0;
	        }
	    }


```
## 需要注意的地方