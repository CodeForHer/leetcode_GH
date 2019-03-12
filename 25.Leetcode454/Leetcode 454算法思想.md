# Leetcode 454(Four Sum II)

## 题目链接
[Four Sum II](https://leetcode-cn.com/classic/problems/4sum-ii/description/)

## 算法思想

### 方法1：
*Time:O(n^3),Space:O(n)*

- 设置一个哈希表，用来统计数组D元素的频率
- 对A，B，C三个数组三重循环。设c=0-A[i]-B[j]-C[k]，若在循环的时候发现哈希表中c的频率大于0，则结果中可以加上对应的频数。

### 方法1代码：
```


	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {

	        int res = 0;
	        int n = A.size();
	        unordered_map<int,int> freq;
	        for(int i=0;i<n;++i){
	            freq[D[i]]++;
	        }
	        for(int i=0;i<n;++i){
	            for(int j=0;j<n;++j){
	                for(int k=0;k<n;++k){
	                    int c = 0-A[i]-B[j]-C[k];
	                    if(freq[c]>0){
	                        res +=freq[c];
	                    }
	                }
	            }
	        }
	        return res;
    }


```


### 方法2：
*Time:O(n^2),Space:O(n^2)*

- 设置一个哈希表，用来统计数组A,B元素之和的频率
- 对C，D两个数组二重循环。设c=0-A[i]-B[j]，若在循环的时候发现哈希表中c的频率大于0，则结果中可以加上对应的频数。

### 方法2代码：
```


	int fourSumCount2(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
	        int res = 0;
	        int n = A.size();
	        unordered_map<int,int> sum_freq;
	        for(int i=0;i<n;++i){
	            for(int j=0;j<n;++j){
	                int sum = A[i]+B[j];
	                sum_freq[sum]++;
	            }
	        }
	
	        for(int i=0;i<n;++i){
	            for(int j=0;j<n;++j){
	                int c = 0 - C[i]-D[j];
	                if(sum_freq[c]>0){
	                    res+=sum_freq[c];
	                }
	            }
	        }
	        return res;
    }


```
### 需要注意的问题：
- 方法一时间复杂度太高，Leetcode无法通过