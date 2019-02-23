# Leetcode 125(Valid Palindrome)

## 题目链接
[Valid Palindrome](https://leetcode-cn.com/problems/valid-palindrome/description/)

## 算法思想

### 方法1：
*Time:O(n),Space:O(1)*

- 采用碰撞指针的方法，设置两个指针分别指向字符串的首和尾，验证字符串

```

	bool isPalindrome(string s) {
	        int i=0,j=s.size()-1;
	        transform(s.begin(),s.end(),s.begin(),::tolower);
	        while(i<j){
	            if(is_num_or_digit(s,i)){
	                if(is_num_or_digit(s,j)){
	                    if(s[i]==s[j]){
	                        ++i;
	                        --j;
	                    }
	                    else{
	                        return false;
	                    }
	                }
	                else{
	                    --j;
	                }
	            }
	            else{
	                ++i;
	            }
	        }
	        return true;
	    }
    bool is_num_or_digit(string s,int i){
        if((s[i]>='0'&&s[i]<='9')||(s[i] >='a' && s[i]<='z' )){
            return true;
        }
        else{
            return false;
        }
    }
```