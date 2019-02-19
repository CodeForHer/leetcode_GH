# Leetcode 88(Merge Sorted Array)

## 题目链接
[Merge Sorted Array](https://leetcode-cn.com/problems/merge-sorted-array/description/)

## 算法思想

### 方法1：
*Time:O(nlgn),Space:O(1)*

- Step1:在nums1后面的空位赋值nums2
- Step2:对nums1调用sort函数

### 方法1代码：
```

	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
	   {
	        for(int i=m,j=0;j<n;++i,++j)
	        {
	            nums1[i]=nums2[j];
	        }
	        sort(nums1.begin(),nums1.end());
	    }


```
### 方法2：
*Time:O(n),Space:O(n)*

- 采用归并的思想，新建一个数组用来存放归并的结果

```

	void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	        vector<int> save;
	        int i=0,j=0;
	        while((i<m)&&(j<n))
	        {
	            if(nums1[i]<=nums2[j])
	            {
	                save.push_back(nums1[i]);
	                ++i;
	            }
	            else
	            {
	                save.push_back(nums2[j]);
	                ++j;
	            }
	        }
	        while(i<m)
	        {
	            save.push_back(nums1[i]);
	            ++i;
	        }
	        while(j<n)
	        {
	            save.push_back(nums2[j]);
	            ++j;
	        }
	        nums1.assign(save.begin(),save.end());
	    }
	    void print(vector<int>& nums)
	    {
	        for(int i=0;i<nums.size();++i)
	        {
	            cout<<nums[i]<<" ";
	        }
	    }

```

### 方法3：
*Time:O(n),Space:O(1)*

- 同样采用归并的思想，只不过先把nums1中的元素移动到数组的后面，前面留出n个空位，之后归并。

```

	void merge3(vector<int>& nums1, int m, vector<int>& nums2, int n){
	        for(int i=m-1,j=m+n-1;i>=0;--i,--j)
	        {
	            nums1[j]=nums1[i];
	        }
	        int i=n,j=0,index=0;
	        while((i<m+n)&&(j<n))
	        {
	            if(nums1[i]<nums2[j])
	            {
	                nums1[index++]=nums1[i++];
	            }
	            else
	            {
	                nums1[index++]=nums2[j++];
	            }
	        }
	        while(j<n)
	        {
	            nums1[index++]=nums2[j++];
	        }
	    }
```