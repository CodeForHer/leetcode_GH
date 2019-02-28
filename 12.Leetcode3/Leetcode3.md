# Leetcode 3(longest substring without repeating characters)

## 题目链接
[longest substring without repeating characters](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/)

## 算法思想

### 方法1：

- 采用滑动窗口的方法，窗口[l,r]存放着不重复的字符串。
- 设置一个数组，用来存放各个字符出现的频率。
- 如果右边边界的下一个字符的频率是0，则加入到窗口中；否则向右移动窗口的左边界，同时右边界对应字符的频率要减一。

### 方法1代码：
```

	int lengthOfLongestSubstring(string s) {
	        int maxLength = 0;
	        int l=0,r=-1;
	        int freq[256] = {0};
	        while(l<(int)s.size()){
	            if(r+1<(int)s.size()&&freq[s[r+1]]==0){
	                ++r;
	                freq[s[r]]++;
	            }
	            else{
	                freq[s[l]]--;
	                l++;
	            }
	            if(r-l+1>maxLength)
	                maxLength = r-l+1;
	        }
	        return maxLength;
	    }
```