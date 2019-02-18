# Leetcode 75(Sort Colors)


## 题目链接
[Sort Colors](https://leetcode-cn.com/problems/sort-colors/description/)

## 算法思想
### 方法1：
*Time:O(nlgn),Space:O(1)*

- 直接使用内置算法对数组排序

### 方法1代码：

```

	void sortColors(vector<int>& nums) {
        sort(nums.begin(),nums.end());
    }

```
### 方法2：
*Time:O(n),Space:O(n)*

- 采用计数排序的思想
- step1: 设置一个大小为3的数组count，初始化为0，分别用来统计0，1，2的个数
- step2: 遍历目标数组nums，对count数组的三个元素进行赋值
- step3: 对目标数组nums按照count数组中的统计结果进行赋值

### 方法2代码：

```

	void sortColors(vector<int>& nums){
        int Count[3]={0,0,0};
        for(int i=0;i<nums.size();++i)
        {
            Count[nums[i]]++;//遍历数组，统计0，1，2的个数
        }
        int index = 0;
        for(int i=0;i<Count[0];++i)
        {
            nums[index++]=0;
        }
        for(int i=0;i<Count[1];++i)
        {
            nums[index++]=1;
        }
        for(int i=0;i<Count[2];++i)
        {
            nums[index++]=2;
        }
    }
```

### 方法3：
*Time:O(n),Space:O(1)*

- 排序好的数组分为三段，我们设置[0,zero]存放0，[zero+1,two-1]存放1，[two,n-1]存放2，zero初始化为-1，two初始化为n
- 在遍历数组nums的时候，如果nums[i]等于0，则将其与nums[zero+1]调换位置，i自增，zero也自增；若nums[i]等于1，i自增即可；若nums[i]等于2，则与nums[two-1]互换位置，two自减，i不变。

### 方法3代码：
```

	void sortColors3(vector<int>& nums)
    {
        int zero = -1;
        int two = nums.size();
        for(int i=0;i<two;)	//注意这里终止条件是i<two,当i=two-1时，意味着正在处理最后一个元素
        {
            if(nums[i]==0)
            {
                if(i!=zero+1) //开始全是0就不用交换了，例如[0,0,0,0,2,1,0,1]
                    swap(nums[i],nums[zero+1]);
                ++i;
                ++zero;
            }
            else if(nums[i]==1)
            {
                ++i;
            }
            else
            {
                swap(nums[two-1],nums[i]);
                --two;
            }
        }
    }

```
