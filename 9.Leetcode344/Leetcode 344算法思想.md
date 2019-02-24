# Leetcode 344(Reverse String)

## 题目链接
[Reverse String](https://leetcode-cn.com/problems/reverse-string/description/)

## 算法思想

### 方法1：
*Time:O(n),Space:O(1)*

- 采用对撞指针的方法，设置两个指针i、j分别指向数组的首尾，之后互相交换即可

```

	void reverseString(vector<char>& s) {
	        int i=0,j=s.size()-1;
	        while(i<j){
	            swap(s[i],s[j]);
	            i++;
	            j--;
	        }
	    }
```